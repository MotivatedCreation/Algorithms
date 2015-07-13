//
//  GAPopulation.m
//  GeneticAlgorithm_ObjC
//
//  Created by Jonathan Sullivan on 7/2/15.
//  Copyright (c) 2015 Jonathan Sullivan. All rights reserved.
//

#import "GAPopulation.h"
#import "GAChromosome.h"


#define ARC4RANDOM_MAX 0x100000000


#pragma mark - Constants

static NSString * const kCharacterSet = @"abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789 ~`!@#$%^&*()_-+=[]{}|;:,.<>?\"";

#pragma mark -


@interface GAPopulation ()

@property(copy, nonatomic) NSString * targetGenes;
@property(strong, nonatomic) NSMutableArray * chromosomes;

@end


@implementation GAPopulation


#pragma mark - Initializers

- (instancetype)initWithPopulationSize:(int)thePopulationSize targetGenes:(NSString *) theTargetGenes
{
    self = [super init];
    if (self)
    {
        self.targetGenes = theTargetGenes;
        self.chromosomes = [[NSMutableArray alloc] init];
        
        for (int i = 0; i < thePopulationSize; i++)
        {
            NSString * randomGenes = [self generateRandomGenes:self.targetGenes.length];
            
            GAChromosome * chromosome = [[GAChromosome alloc] initWithGenes:randomGenes];
            chromosome.fitness = [self calculateFitness:chromosome];
            [self.chromosomes addObject:chromosome];
        }
    }
    return self;
}

#pragma mark -


#pragma mark - Mutation Methods

- (void)mutate:(GAChromosome *)chromosome
{
    NSInteger targetLength = self.targetGenes.length;
    NSInteger pivot = arc4random_uniform((unsigned)targetLength);
    
    NSMutableString * genes = [chromosome.genes mutableCopy];
    [genes replaceCharactersInRange:NSMakeRange(pivot, 1) withString:[self generateRandomGene]];
    chromosome.genes = [genes copy];
}

#pragma mark -


#pragma mark - Selection Methods

- (GAChromosome *)tournamentSelection:(int)theTournamentSize
{
    NSMutableArray * competitors = [[NSMutableArray alloc] init];
    
    NSInteger populationSize = self.chromosomes.count;
    
    for (NSInteger i = 0; i < theTournamentSize; i++)
    {
        NSInteger index = arc4random_uniform((unsigned)populationSize);
        [competitors addObject:self.chromosomes[index]];
    }
    
    GAChromosome * strongestCompetitor = competitors[0];
    
    for (int i = 1; i < theTournamentSize; i++)
    {
        GAChromosome * competitor = self.chromosomes[i];
        
        if (competitor.fitness < strongestCompetitor.fitness)
            strongestCompetitor = competitor;
    }
    
    return strongestCompetitor;
}

- (GAChromosome *)rouletteWheelSelection
{
    NSInteger totalFitness = 0;
    NSInteger populationSize = self.chromosomes.count;
    
    for (GAChromosome * chromosome in self.chromosomes)
        totalFitness += chromosome.fitness;
    
    double accumulatedNormalizedFitness = 0;
    double randomNumber = (float)(arc4random() / (float)ARC4RANDOM_MAX);
    
    GAChromosome * chromosome;
    
    for (int i = 0; i < populationSize; i++)
    {
        GAChromosome * theChromosome = self.chromosomes[i];
        
        accumulatedNormalizedFitness += (theChromosome.fitness / (double)totalFitness);
        
        if (randomNumber < accumulatedNormalizedFitness)
        {
            chromosome = theChromosome;
            break;
        }
    }
    
    return chromosome;
}

- (GAChromosome *)randomSelection
{
    NSInteger populationSize = self.chromosomes.count;
    
    NSInteger index = arc4random_uniform((unsigned)populationSize);
    return self.chromosomes[index];
}

- (GAChromosome *)selectChromosome
{
    GAChromosome * chromosome;
    
    switch (self.selectionType)
    {
        case GAPopulationSelectionTypeRouletteWheel: {
            chromosome = [self rouletteWheelSelection];
        }
            break;
            
        case GAPopulationSelectionTypeTournament: {
            chromosome = [self tournamentSelection:self.tournamentSize];
        }
            break;
            
        case GAPopulationSelectionTypeRandom:
        default: {
            chromosome = [self randomSelection];
        }
            break;
    }
    
    return chromosome;
}

#pragma mark -


#pragma mark - Crossover Methods

- (void)onePointCrossover
{
    NSInteger elitismOffset = 0;
    NSInteger populationSize = self.chromosomes.count;
    
    NSMutableArray * buffer = [[NSMutableArray alloc] init];
    
    if (self.isElitismEnabled)
    {
        elitismOffset = (self.elitismPercentage * populationSize);
        
        NSSortDescriptor * sortDescriptor = [NSSortDescriptor sortDescriptorWithKey:@"fitness" ascending:YES];
        [self.chromosomes sortUsingDescriptors:@[sortDescriptor]];
        
        for (NSInteger i = 0; i < elitismOffset; i++)
            [buffer addObject:self.chromosomes[i]];
    }
    
    for (NSInteger i = elitismOffset; i < populationSize; i += 2)
    {
        @autoreleasepool
        {
            GAChromosome * chromosomeA = [self selectChromosome];
            GAChromosome * chromosomeB = [self selectChromosome];
            
            float randomCrossover = (float)(arc4random() / (float)ARC4RANDOM_MAX);
            
            if (randomCrossover < self.crossoverProbability)
            {
                NSInteger targetLength = self.targetGenes.length;
                NSInteger pivot = arc4random_uniform((unsigned)targetLength);
                
                NSString * genesToCrossOverA = [chromosomeA.genes substringWithRange:NSMakeRange(pivot, targetLength - pivot)];
                NSString * genesToCrossOverB = [chromosomeB.genes substringWithRange:NSMakeRange(pivot, targetLength - pivot)];
                
                NSString * crossedOverGenesA = [NSString stringWithFormat:@"%@%@", [chromosomeA.genes substringWithRange:NSMakeRange(0, pivot)], genesToCrossOverB];
                NSString * crossedOverGenesB = [NSString stringWithFormat:@"%@%@", [chromosomeB.genes substringWithRange:NSMakeRange(0, pivot)], genesToCrossOverA];
                
                GAChromosome * offspringA = [[GAChromosome alloc] initWithGenes:crossedOverGenesA];
                GAChromosome * offspringB = [[GAChromosome alloc] initWithGenes:crossedOverGenesB];
                
                float randomMutation = (float)(arc4random() / (float)ARC4RANDOM_MAX);
                
                if (randomMutation < self.mutationProbability)
                {
                    [self mutate:offspringA];
                    [self mutate:offspringB];
                }
                
                offspringA.fitness = [self calculateFitness:offspringA];
                offspringB.fitness = [self calculateFitness:offspringB];
                
                [buffer addObject:offspringA];
                [buffer addObject:offspringB];
            }
            else {
                [buffer addObject:chromosomeA];
                [buffer addObject:chromosomeB];
            }
        }
    }
    
    self.chromosomes = [buffer mutableCopy];
}

- (void)twoPointCrossover
{
    NSInteger elitismOffset = 0;
    NSInteger populationSize = self.chromosomes.count;
    
    NSMutableArray * buffer = [[NSMutableArray alloc] init];
    
    if (self.isElitismEnabled)
    {
        elitismOffset = (self.elitismPercentage * populationSize);
        
        NSSortDescriptor * sortDescriptor = [NSSortDescriptor sortDescriptorWithKey:@"fitness" ascending:YES];
        [self.chromosomes sortUsingDescriptors:@[sortDescriptor]];
        
        for (NSInteger i = 0; i < elitismOffset; i++)
            [buffer addObject:self.chromosomes[i]];
    }
    
    for (NSInteger i = elitismOffset; i < populationSize; i += 2)
    {
        @autoreleasepool
        {
            GAChromosome * chromosomeA = [self selectChromosome];
            GAChromosome * chromosomeB = [self selectChromosome];
            
            float randomCrossover = (float)(arc4random() / (float)ARC4RANDOM_MAX);
            
            if (randomCrossover < self.crossoverProbability)
            {
                NSInteger targetLength = self.targetGenes.length;
                
                NSInteger pivotA = arc4random_uniform((unsigned)targetLength);
                NSInteger pivotB = arc4random_uniform((unsigned)targetLength);
                
                if (pivotA > pivotB)
                {
                    NSInteger temp = pivotA;
                    pivotA = pivotB;
                    pivotB = temp;
                }
                
                NSString * genesToCrossOverA = [chromosomeA.genes substringWithRange:NSMakeRange(pivotA, pivotB - pivotA)];
                NSString * genesToCrossOverB = [chromosomeB.genes substringWithRange:NSMakeRange(pivotA, pivotB - pivotA)];
                
                NSString * crossedOverGenesA = [NSString stringWithFormat:@"%@%@%@", [chromosomeA.genes substringWithRange:NSMakeRange(0, pivotA)], genesToCrossOverB, [chromosomeA.genes substringWithRange:NSMakeRange(pivotB, targetLength - pivotB)]];
                
                NSString * crossedOverGenesB = [NSString stringWithFormat:@"%@%@%@", [chromosomeB.genes substringWithRange:NSMakeRange(0, pivotA)], genesToCrossOverA, [chromosomeA.genes substringWithRange:NSMakeRange(pivotB, targetLength - pivotB)]];
                
                GAChromosome * offspringA = [[GAChromosome alloc] initWithGenes:crossedOverGenesA];
                GAChromosome * offspringB = [[GAChromosome alloc] initWithGenes:crossedOverGenesB];
                
                float randomMutation = (float)(arc4random() / (float)ARC4RANDOM_MAX);
                
                if (randomMutation < self.mutationProbability)
                {
                    [self mutate:offspringA];
                    [self mutate:offspringB];
                }
                
                offspringA.fitness = [self calculateFitness:offspringA];
                offspringB.fitness = [self calculateFitness:offspringB];
                
                [buffer addObject:offspringA];
                [buffer addObject:offspringB];
            }
            else {
                [buffer addObject:chromosomeA];
                [buffer addObject:chromosomeB];
            }
        }
    }
    
    self.chromosomes = [buffer mutableCopy];
}

- (void)crossoverPopulation
{
    switch (self.crossoverType)
    {
        case GAPopulationCrossoverTypeTwoPoint:
            [self twoPointCrossover];
            break;
            
        case GAPopulationCrossoverTypeOnePoint:
        default:
            [self onePointCrossover];
            break;
    }
}

#pragma mark -


#pragma mark - Fitness Methods

- (GAChromosome *)getFittest
{
    GAChromosome * bestChromosome = self.chromosomes[0];
    
    NSInteger populationSize = self.chromosomes.count;
    
    for (NSInteger i = 0; i < populationSize; i++)
    {
        GAChromosome * chromosome = self.chromosomes[i];
        
        if (chromosome.fitness < bestChromosome.fitness)
            bestChromosome = chromosome;
    }
    
    return bestChromosome;
}

- (NSInteger)calculateFitness:(GAChromosome *)theChromosome
{
    NSInteger fitness = 0;
    
    for (NSInteger i = 0; i < theChromosome.genes.length; i++)
    {
        if ([theChromosome.genes characterAtIndex:i] == [self.targetGenes characterAtIndex:i])
            fitness += 1;
    }
    
    return labs(fitness - (NSInteger)self.targetGenes.length);
}

#pragma mark -


#pragma mark - Evolution Methods

- (void)evolve
{
    NSInteger generationCount = 0;
    
    while ([self getFittest].fitness != 0)
    {
        [self crossoverPopulation];
        
        NSLog(@"[Generation %ld]\n", (long)generationCount);
        NSLog(@"Genes: %@\n", [self getFittest].genes);
        NSLog(@"Fitness: %ld\n\n", (long)[self getFittest].fitness);
        
        generationCount++;
    }
}

#pragma mark -


#pragma mark - Helper Methods

- (NSString *)generateRandomGene
{
    NSInteger index = arc4random_uniform((unsigned)kCharacterSet.length);
    NSString * randomGene = [NSString stringWithFormat:@"%c", [kCharacterSet characterAtIndex:index]];
    return randomGene;
}

- (NSString *)generateRandomGenes:(NSInteger)theLength
{
    NSMutableString * genes = [@"" mutableCopy];
    
    for (NSInteger i = 0; i < theLength; i++)
    {
        NSInteger index = arc4random_uniform((unsigned)kCharacterSet.length);
        NSString * characterString = [NSString stringWithFormat:@"%c", [kCharacterSet characterAtIndex:index]];
        [genes appendString:characterString];
    }
    
    return [genes copy];
}

#pragma mark -

@end
