//
//  main.swift
//  GeneticAlgorithm_Swift
//
//  Created by Jonathan Sullivan on 7/2/15.
//  Copyright (c) 2015 Jonathan Sullivan. All rights reserved.
//

import Foundation


// MARK: - Constants

let TournamentSize = 2;
let PopulationSize = 333;
let ElitismEnabled = true;
let ElitismPercentage = 0.25;
let MutationProbability = 0.20;
let CrossoverProbability = 0.95;
let TargetGenes = "Hello, World!";

// MARK: -


print("Running Genetic Algorithm...\n");
print("Target Genes: \(TargetGenes)\n");
print("Population Size: \(PopulationSize)\n");
print("Elitism: \(ElitismEnabled)\n");
print("Elitism Percentage: \(ElitismPercentage)%\n");
print("Mutation Probability: \(MutationProbability)%\n");
print("Crossover Probability: \(CrossoverProbability)%\n\n");

let population = GAPopulation(thePopulationSize: PopulationSize, theTargetGenes: TargetGenes);
population.elitismEnabled = ElitismEnabled;
population.tournamentSize = TournamentSize;
population.elitismPercentage = ElitismPercentage;
population.mutationProbability = MutationProbability;
population.crossoverProbability = CrossoverProbability;
population.selectionType = .GAPopulationSelectionTypeTournament;
population.crossoverType = .GAPopulationCrossoverTypeOnePoint;
population.evolve();