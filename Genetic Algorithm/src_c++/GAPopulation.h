//
//  GAPopulation.h
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

#ifndef __GeneticAlgorithm_C____GAPopulation__
#define __GeneticAlgorithm_C____GAPopulation__


#include <string>
#include <vector>

#include "GAChromosome.h"


typedef GAChromosome<std::string> GAChromosomeString;


enum class GAPopulationCrossoverType
{
    GAPopulationCrossoverTypeOnePoint = 0,
    GAPopulationCrossoverTypeTwoPoint
};

enum class GAPopulationSelectionType
{
    GAPopulationSelectionTypeTournament = 0,
    GAPopulationSelectionTypeRouletteWheel,
    GAPopulationSelectionTypeRandom
};


class GAPopulation
{
    
private:
    
#pragma mark - Private Class Members
    
    std::string targetGenes;
    std::vector<GAChromosomeString>chromosomes;
    
#pragma mark -
    

#pragma mark - Helper Methods
    
    char generateRandomGene();
    std::string generateRandomGenes(int geneLength);
    
#pragma mark -
    
    
#pragma mark - Fitness Methods
    
    GAChromosomeString getFittest();
    int calculateFitness(GAChromosomeString const &chromosome);
    
#pragma mark -
    
    
#pragma mark - Mutation Methods
    
    void mutate(GAChromosomeString &chromosome);
    
#pragma mark -
    

#pragma mark - Selection Methods
    
    GAChromosomeString selectChromosome();
    GAChromosomeString randomSelection();
    GAChromosomeString rouletteWheelSelection();
    GAChromosomeString tournamentSelection(int tournamentSize);
    
#pragma mark -
    
    
#pragma mark - Crossover Methods
    
    void crossoverPopulation();
    std::pair<GAChromosomeString, GAChromosomeString> onePointCrossover(GAChromosomeString const &chromosomeA, GAChromosomeString const &chromosomeB);
    std::pair<GAChromosomeString, GAChromosomeString> twoPointCrossover(GAChromosomeString const &chromosomeA, GAChromosomeString const &chromosomeB);
    
#pragma mark -
    
    
public:
    
#pragma mark - Private Class Members
    
    int tournamentSize;
    bool elitismEnabled;
    double elitismPercentage;
    double mutationProbability;
    double crossoverProbability;
    GAPopulationCrossoverType crossoverType;
    GAPopulationSelectionType selectionType;
    
#pragma mark -
    
    
#pragma mark - Constructors
    
    GAPopulation(int thePopulationSize, std::string theTargetGenes);
    
#pragma mark -
    

#pragma mark - Evolution Methods
    
    void evolve();
    
#pragma mark -
    
};

#endif /* defined(__GeneticAlgorithm_C____GAPopulation__) */
