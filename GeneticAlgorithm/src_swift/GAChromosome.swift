//
//  GAChromosome.swift
//  GeneticAlgorithm_Swift
//
//  Created by Jonathan Sullivan on 7/2/15.
//  Copyright (c) 2015 Jonathan Sullivan. All rights reserved.
//

import Foundation

class GAChromosome<GenoType>
{
    // MARK: - Public Class Members
    
    var fitness: Int
    var genes: GenoType
    
    // MARK: -
    
    
    // MARK: Constructors
    
    init(genes: GenoType)
    {
        self.fitness = 0
        self.genes = genes
    }
    
    // MARK: -
}