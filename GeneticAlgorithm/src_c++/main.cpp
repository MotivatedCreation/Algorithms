//
//  main.cpp
//  GeneticAlgorithm_C++
//
//  Created by Jonathan Sullivan on 6/28/15.
//  Copyright (c) 2015 Jonathan Sullivan. All rights reserved.
//

#include <iostream>

#include "GAPopulation.h"
#include "GAChromosome.h"


#define PERCENTAGE(X) ((X / 100.0f))


#pragma mark - Constants

const int kTournamentSize = 2;
const int kPopulationSize = 1000;
const bool kElitismEnabled = true;
const int kElitismPercentage = 25;
const int kMutationProbability = 20;
const int kCrossoverProbability = 95;
const std::string kTargetGenes = "Hello, World!";

#pragma mark -


int main(int argc, const char * argv[])
{
    srand((unsigned)time(NULL));
    
    printf("Running Genetic Algorithm...\n");
    printf("Target Genes: %s\n", kTargetGenes.c_str());
    printf("Population Size: %d\n", kPopulationSize);
    printf("Elitism: %s\n", (kElitismEnabled ? "true" : "false"));
    printf("Elitism Percentage: %d%%\n", kElitismPercentage);
    printf("Mutation Probability: %d%%\n", kMutationProbability);
    printf("Crossover Probability: %d%%\n\n", kCrossoverProbability);
    
    GAPopulation population = GAPopulation(kPopulationSize, kTargetGenes);
    population.elitismEnabled = kElitismEnabled;
    population.tournamentSize = kTournamentSize;
    population.elitismPercentage = PERCENTAGE(kElitismPercentage);
    population.mutationProbability = PERCENTAGE(kMutationProbability);
    population.crossoverProbability = PERCENTAGE(kCrossoverProbability);
    population.selectionType = GAPopulationSelectionType::GAPopulationSelectionTypeTournament;
    population.crossoverType = GAPopulationCrossoverType::GAPopulationCrossoverTypeOnePoint;
    population.evolve();
    
    return 0;
}
