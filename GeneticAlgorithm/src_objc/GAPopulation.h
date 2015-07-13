//
//  GAPopulation.h
//  GeneticAlgorithm_ObjC
//
//  Created by Jonathan Sullivan on 7/2/15.
//  Copyright (c) 2015 Jonathan Sullivan. All rights reserved.
//

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
