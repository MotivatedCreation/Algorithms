//
//  main.m
//  GeneticAlgorithm_ObjC
//
//  Created by Jonathan Sullivan on 7/2/15.
//  Copyright (c) 2015 Jonathan Sullivan. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "GAPopulation.h"


#define PERCENTAGE(X) ((X / 100.0f))


#pragma mark - Constants

static const BOOL kElitismEnabled = true;
static const NSInteger kTournamentSize = 2;
static const NSInteger kPopulationSize = 1000;
static const NSInteger kElitismPercentage = 25;
static const NSInteger kMutationProbability = 20;
static const NSInteger kCrossoverProbability = 95;
static NSString * const kTargetGenes = @"Hello, World!";

#pragma mark -


int main(int argc, const char * argv[])
{
    @autoreleasepool
    {
        NSLog(@"Running Genetic Algorithm...\n");
        NSLog(@"Target Genes: %@\n", kTargetGenes);
        NSLog(@"Population Size: %ld\n", (long)kPopulationSize);
        NSLog(@"Elitism: %s\n", (kElitismEnabled ? "true" : "false"));
        NSLog(@"Elitism Percentage: %ld%%\n", (long)kElitismPercentage);
        NSLog(@"Mutation Probability: %ld%%\n", (long)kMutationProbability);
        NSLog(@"Crossover Probability: %ld%%\n\n", (long)kCrossoverProbability);
        
        GAPopulation * population = [[GAPopulation alloc] initWithPopulationSize:kPopulationSize targetGenes:kTargetGenes];
        population.elitismEnabled = kElitismEnabled;
        population.tournamentSize = kTournamentSize;
        population.elitismPercentage = PERCENTAGE(kElitismPercentage);
        population.mutationProbability = PERCENTAGE(kMutationProbability);
        population.crossoverProbability = PERCENTAGE(kCrossoverProbability);
        population.selectionType = GAPopulationSelectionTypeTournament;
        population.crossoverType = GAPopulationCrossoverTypeOnePoint;
        [population evolve];
    }
    return 0;
}
