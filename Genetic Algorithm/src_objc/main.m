//
//  main.m
//  GeneticAlgorithm_ObjC
//
//  Created by Jonathan Sullivan on 7/2/15.
//
// The MIT License (MIT)
//
// Copyright (c) 2015 Jonathan Sullivan
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.

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
