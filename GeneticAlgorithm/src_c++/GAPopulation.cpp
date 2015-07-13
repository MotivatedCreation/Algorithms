//
//  GAPopulation.cpp
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

#include <cstdlib>

#include "GAPopulation.h"
#include "GAChromosome.h"
#include "GAChromosome.cpp"


#pragma mark - Namespaces

using namespace std;

#pragma mark -


#pragma mark - Constants

static const string kCharacterSet = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789 ~`!@#$%^&*()_-+=[]{}|;:,.<>?\"";

#pragma mark -


#pragma mark - Constructors

GAPopulation::GAPopulation(int thePopulationSize, string theTargetGenes)
{
    this->targetGenes = theTargetGenes;
    this->chromosomes = vector<GAChromosomeString>();
    
    for (int i = 0; i < thePopulationSize; i++)
    {
        string randomGenes = this->generateRandomGenes((int)this->targetGenes.length());
        
        GAChromosomeString chromosome = GAChromosomeString(randomGenes);
        chromosome.fitness = this->calculateFitness(chromosome);
        this->chromosomes.push_back(chromosome);
    }
}

#pragma mark -


#pragma mark - Mutation Methods

void GAPopulation::mutate(GAChromosomeString &chromosome)
{
    size_t targetLength = this->targetGenes.length();
    
    int pivot = (rand() % targetLength);
    
    string genes = chromosome.genes;
    genes.at(pivot) = this->generateRandomGene();
    chromosome.genes = genes;
}

#pragma mark -


#pragma mark - Selection Methods

GAChromosomeString GAPopulation::tournamentSelection(int theTournamentSize)
{
    vector<GAChromosomeString> competitors = vector<GAChromosomeString>();
    
    int populationSize = (int)this->chromosomes.size();
    
    for (int i = 0; i < theTournamentSize; i++)
    {
        int index = (rand() % populationSize);
        competitors.push_back(this->chromosomes.at(index));
    }
    
    GAChromosomeString strongestCompetitor = competitors.at(0);
    
    for (int i = 1; i < theTournamentSize; i++)
    {
        GAChromosomeString competitor = this->chromosomes.at(i);
        
        if (competitor.fitness < strongestCompetitor.fitness)
            strongestCompetitor = competitor;
    }
    
    competitors.clear();
    
    return strongestCompetitor;
}

GAChromosomeString GAPopulation::rouletteWheelSelection()
{
    int populationSize = (int)this->chromosomes.size();
    
    int totalFitness = 0;
    
    for (int i = 0; i < populationSize; i++)
        totalFitness += this->chromosomes.at(i).fitness;
    
    double randomNumber = (float)(rand() / (float)RAND_MAX);
    double accumulatedNormalizedFitness = 0;
    
    GAChromosomeString chromosome;
    
    for (int i = 0; i < populationSize; i++)
    {
        GAChromosomeString theChromosome = this->chromosomes.at(i);
        
        accumulatedNormalizedFitness += (theChromosome.fitness / (double)totalFitness);
        
        if (randomNumber < accumulatedNormalizedFitness)
        {
            chromosome = theChromosome;
            break;
        }
    }
    
    return chromosome;
}

GAChromosomeString GAPopulation::randomSelection()
{
    int populationSize = (int)this->chromosomes.size();
    
    int index = (rand() % populationSize);
    return this->chromosomes.at(index);
}

GAChromosomeString GAPopulation::selectChromosome()
{
    GAChromosomeString chromosome;
    
    switch (this->selectionType)
    {
        case GAPopulationSelectionType::GAPopulationSelectionTypeRouletteWheel: {
            chromosome = this->rouletteWheelSelection();
        }
            break;
            
        case GAPopulationSelectionType::GAPopulationSelectionTypeTournament: {
            chromosome = this->tournamentSelection(this->tournamentSize);
        }
            break;
            
        case GAPopulationSelectionType::GAPopulationSelectionTypeRandom:
        default: {
            chromosome = this->randomSelection();
        }
            break;
    }
    
    return chromosome;
}

#pragma mark -


#pragma mark - Crossover Methods

pair<GAChromosomeString, GAChromosomeString> GAPopulation::onePointCrossover(GAChromosomeString const &chromosomeA, GAChromosomeString const &chromosomeB)
{
    int targetLength = (int)this->targetGenes.length();
    int pivot = (rand() % targetLength);
    
    string genesToCrossOverA = chromosomeA.genes.substr(pivot, targetLength - pivot);
    string genesToCrossOverB = chromosomeB.genes.substr(pivot, targetLength - pivot);
    
    string crossedOverGenesA = chromosomeA.genes.substr(0, pivot) + genesToCrossOverB;
    string crossedOverGenesB = chromosomeB.genes.substr(0, pivot) + genesToCrossOverA;
    
    GAChromosomeString offspringA = GAChromosomeString(crossedOverGenesA);
    GAChromosomeString offspringB = GAChromosomeString(crossedOverGenesB);
    
    float randomMutation = (float)(rand() / (float)RAND_MAX);
    
    if (randomMutation < this->mutationProbability)
    {
        this->mutate(offspringA);
        this->mutate(offspringB);
    }
    
    offspringA.fitness = this->calculateFitness(offspringA);
    offspringB.fitness = this->calculateFitness(offspringB);
    
    return make_pair(offspringA, offspringB);
}

pair<GAChromosomeString, GAChromosomeString> GAPopulation::twoPointCrossover(GAChromosomeString const &chromosomeA, GAChromosomeString const &chromosomeB)
{
    int targetLength = (int)this->targetGenes.length();
    
    int pivotA = (rand() % targetLength);
    int pivotB = (rand() % targetLength);
    
    if (pivotA > pivotB)
    {
        int temp = pivotA;
        pivotA = pivotB;
        pivotB = temp;
    }
    
    string genesToCrossOverA = chromosomeA.genes.substr(pivotA, pivotB - pivotA);
    string genesToCrossOverB = chromosomeB.genes.substr(pivotA, pivotB - pivotA);
    
    string crossedOverGenesA = chromosomeA.genes.substr(0, pivotA) + genesToCrossOverB + chromosomeA.genes.substr(pivotB, targetLength - pivotB);
    string crossedOverGenesB = chromosomeB.genes.substr(0, pivotA) + genesToCrossOverA + chromosomeA.genes.substr(pivotB, targetLength - pivotB);
    
    GAChromosomeString offspringA = GAChromosomeString(crossedOverGenesA);
    GAChromosomeString offspringB = GAChromosomeString(crossedOverGenesB);
    
    float randomMutation = (float)(rand() / (float)RAND_MAX);
    
    if (randomMutation < this->mutationProbability)
    {
        this->mutate(offspringA);
        this->mutate(offspringB);
    }
    
    offspringA.fitness = this->calculateFitness(offspringA);
    offspringB.fitness = this->calculateFitness(offspringB);
    
    return make_pair(offspringA, offspringB);
}

void GAPopulation::crossoverPopulation()
{
    int elitismOffset = 0;
    int populationSize = (int)this->chromosomes.size();
    
    vector<GAChromosomeString> buffer = vector<GAChromosomeString>();
    
    if (this->elitismEnabled)
    {
        elitismOffset = (int)(this->elitismPercentage * populationSize);
        
        sort(this->chromosomes.begin(), this->chromosomes.end());
        
        for (int i = 0; i < elitismOffset; i++)
            buffer.push_back(this->chromosomes.at(i));
    }
    
    for (int i = elitismOffset; i < populationSize; i += 2)
    {
        GAChromosomeString chromosomeA = this->selectChromosome();
        GAChromosomeString chromosomeB = this->selectChromosome();
        
        float randomCrossover = (float)(rand() / (float)RAND_MAX);
        
        if (randomCrossover < this->crossoverProbability)
        {
            pair<GAChromosomeString, GAChromosomeString> offspring;
            
            switch (this->crossoverType)
            {
                case GAPopulationCrossoverType::GAPopulationCrossoverTypeTwoPoint: {
                    offspring = this->twoPointCrossover(chromosomeA, chromosomeB);
                }
                    break;
                    
                case GAPopulationCrossoverType::GAPopulationCrossoverTypeOnePoint:
                default: {
                    offspring = this->onePointCrossover(chromosomeA, chromosomeB);
                }
                    break;
            }
            
            buffer.push_back(offspring.first);
            buffer.push_back(offspring.second);
        }
        else {
            buffer.push_back(chromosomeA);
            buffer.push_back(chromosomeB);
        }
    }
    
    this->chromosomes = vector<GAChromosomeString>(buffer);
}

#pragma mark -


#pragma mark - Fitness Methods

GAChromosomeString GAPopulation::getFittest()
{
    GAChromosomeString bestChromosome = this->chromosomes.at(0);
    
    int populationSize = (int)this->chromosomes.size();
    
    for (int i = 0; i < populationSize; i++)
    {
        GAChromosomeString chromosome = this->chromosomes.at(i);
        
        if (chromosome.fitness < bestChromosome.fitness)
            bestChromosome = chromosome;
    }
    
    return bestChromosome;
}

int GAPopulation::calculateFitness(GAChromosomeString const &theChromosome)
{
    int fitness = 0;
    
    for (int i = 0; i < theChromosome.genes.length(); i++)
        if (theChromosome.genes.at(i) == this->targetGenes.at(i))
            fitness += 1;
    
    return abs(fitness - (int)this->targetGenes.length());
}

#pragma mark -


#pragma mark - Evolution Methods

void GAPopulation::evolve()
{
    int generationCount = 0;
    
    while (this->getFittest().fitness != 0)
    {
        this->crossoverPopulation();
        
        printf("[Generation %d]\n", generationCount);
        printf("Genes: %s\n", this->getFittest().genes.c_str());
        printf("Fitness: %d\n\n", this->getFittest().fitness);
        
        generationCount++;
    }
}

#pragma mark -


#pragma mark - Helper Methods

char GAPopulation::generateRandomGene()
{
    int index = (rand() % kCharacterSet.length());
    return kCharacterSet.at(index);
}

string GAPopulation::generateRandomGenes(int theLength)
{
    string genes = "";
    
    for (int i = 0; i < theLength; i++)
    {
        int index = (rand() % kCharacterSet.length());
        genes += kCharacterSet.at(index);
    }
    
    return genes;
}

#pragma mark -
