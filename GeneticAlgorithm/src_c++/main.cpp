//
//  main.cpp
//  GeneticAlgorithm_C++
//
//  Created by Jonathan Sullivan on 6/28/15.
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
