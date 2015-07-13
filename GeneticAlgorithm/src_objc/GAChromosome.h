//
//  GAChromosome.h
//  GeneticAlgorithm_ObjC
//
//  Created by Jonathan Sullivan on 7/2/15.
//  Copyright (c) 2015 Jonathan Sullivan. All rights reserved.
//

#import <Foundation/Foundation.h>


@interface GAChromosome : NSObject

#pragma mark Constructors

- (instancetype)initWithGenes:(NSString *)genes;

#pragma mark -


#pragma mark - Public Class Members

@property (assign, nonatomic) NSInteger fitness;

@property (copy, nonatomic) NSString * genes;

#pragma mark -


@end
