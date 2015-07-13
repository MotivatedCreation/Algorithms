//
//  GAChromosome.h
//  GeneticAlgorithm_C++
//
//  Created by Jonathan Sullivan on 6/28/15.
//  Copyright (c) 2015 Jonathan Sullivan. All rights reserved.
//

#ifndef __GeneticAlgorithm_C____GAChromosome__
#define __GeneticAlgorithm_C____GAChromosome__


#include <string>


template <class GenoType>
class GAChromosome
{
    
public:
    
#pragma mark Constructors
    
    GAChromosome();
    GAChromosome(GenoType theGenes);
    
#pragma mark -
    

#pragma mark - Public Class Members
    
    int fitness;
    GenoType genes;
    
#pragma mark -
    
    
#pragma mark - Overloaded Operators
    
    template <typename GT>
    friend bool operator<(const GAChromosome<GT> &chromosomeA, const GAChromosome<GT> &chromosomeB);
    
#pragma mark -
    
    
};



#endif /* defined(__GeneticAlgorithm_C____GAChromosome__) */