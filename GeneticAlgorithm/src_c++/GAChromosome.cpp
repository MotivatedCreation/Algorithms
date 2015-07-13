//
//  GAChromosome.cpp
//  GeneticAlgorithm_C++
//
//  Created by Jonathan Sullivan on 6/28/15.
//  Copyright (c) 2015 Jonathan Sullivan. All rights reserved.
//

#include "GAChromosome.h"


#pragma mark - Namespaces

using namespace std;

#pragma mark -


#pragma mark - Constructors

template <typename GenoType>
GAChromosome<GenoType>::GAChromosome()
{
    fitness = 0;
    genes = "";
}

template <typename GenoType>
GAChromosome<GenoType>::GAChromosome(GenoType theGenes)
{
    fitness = 0;
    genes = theGenes;
}

#pragma mark -


#pragma mark - Overloaded Operators

template <typename GenoType>
bool operator< (const GAChromosome<GenoType> &chromosomeA, const GAChromosome<GenoType> &chromosomeB)
{
    return (chromosomeA.fitness < chromosomeB.fitness);
}

#pragma mark -

