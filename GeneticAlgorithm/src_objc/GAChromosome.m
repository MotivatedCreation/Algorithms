//
//  GAChromosome.m
//  GeneticAlgorithm_ObjC
//
//  Created by Jonathan Sullivan on 7/2/15.
//  Copyright (c) 2015 Jonathan Sullivan. All rights reserved.
//

#import "GAChromosome.h"

@implementation GAChromosome

#pragma mark - Constructors

- (instancetype)initWithGenes:(NSString *)genes
{
    self = [super init];
    if (self)
    {
        self.fitness = 0;
        self.genes = genes;
    }
    return self;
}

#pragma mark -

@end
