//
//  GAChromosome.h
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
