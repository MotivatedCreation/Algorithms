//
//  GAPopulation.h
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


@class GAChromosome;


typedef NS_ENUM(NSInteger, GAPopulationCrossoverType)
{
    GAPopulationCrossoverTypeOnePoint = 0,
    GAPopulationCrossoverTypeTwoPoint
};

typedef NS_ENUM(NSInteger, GAPopulationSelectionType)
{
    GAPopulationSelectionTypeTournament = 0,
    GAPopulationSelectionTypeRouletteWheel,
    GAPopulationSelectionTypeRandom
};


@interface GAPopulation : NSObject


#pragma mark - Private Class Members
    
@property(assign, nonatomic) int tournamentSize;
@property(assign, nonatomic) double elitismPercentage;
@property(assign, nonatomic) double mutationProbability;
@property(assign, nonatomic) double crossoverProbability;
@property(assign, nonatomic) GAPopulationCrossoverType crossoverType;
@property(assign, nonatomic) GAPopulationSelectionType selectionType;
@property(assign, nonatomic, getter=isElitismEnabled) BOOL elitismEnabled;
    
#pragma mark -
    
    
#pragma mark - Constructors

- (instancetype)initWithPopulationSize:(int)thePopulationSize targetGenes:(NSString *)theTargetGenes;
    
#pragma mark -
    
    
#pragma mark - Evolution Methods

- (void)evolve;
    
#pragma mark -
    
@end
