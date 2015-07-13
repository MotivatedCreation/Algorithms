//
//  main.swift
//  GeneticAlgorithm_Swift
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
