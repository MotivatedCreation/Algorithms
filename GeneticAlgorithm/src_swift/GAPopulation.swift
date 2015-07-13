//
//  GAPopulation.swift
//  GeneticAlgorithm_Swift
//
//  Created by Jonathan Sullivan on 7/2/15.
//  Copyright (c) 2015 Jonathan Sullivan. All rights reserved.
//

import Foundation


typealias GAChromosomeString = GAChromosome<String>

let CharacterSet = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789 ~`!@#$%^&*()_-+=[]{}|:,.<>?\""


enum GAPopulationCrossoverType: Int
{
    case GAPopulationCrossoverTypeOnePoint = 0
    case GAPopulationCrossoverTypeTwoPoint
}

enum GAPopulationSelectionType: Int
{
    case GAPopulationSelectionTypeTournament = 0
    case GAPopulationSelectionTypeRouletteWheel
    case GAPopulationSelectionTypeRandom
}


class GAPopulation
{
    
    // MARK: - Private Class Members
    
    private var targetGenes: String
    private var chromosomes: Array<GAChromosomeString>
    
    // MARK: -
    
    
    // MARK: - Private Class Members
    
    var tournamentSize: Int = 2
    var elitismEnabled: Bool = true
    var elitismPercentage: Double = 0.25
    var mutationProbability: Double = 0.25
    var crossoverProbability: Double = 0.95
    var crossoverType: GAPopulationCrossoverType = .GAPopulationCrossoverTypeOnePoint
    var selectionType: GAPopulationSelectionType = .GAPopulationSelectionTypeTournament
    
    // MARK: -
    
    
    // MARK: - Constructors
    
    init(thePopulationSize: Int, theTargetGenes: String)
    {
        self.targetGenes = theTargetGenes
        self.chromosomes = [GAChromosomeString]()
        
        for i in 0..<thePopulationSize
        {
            let randomGenes = self.generateRandomGenes(count(self.targetGenes))
            
            let chromosome = GAChromosomeString(genes: randomGenes)
            chromosome.fitness = self.calculateFitness(chromosome)
            self.chromosomes.append(chromosome)
        }
    }
    
    // MARK: -
    
    
    // MARK: - Helper Methods
    
    private func generateRandomGene() -> Character
    {
        let numberOfCharacters = count(CharacterSet)
        let index = Int(arc4random_uniform(UInt32(numberOfCharacters)))
        
        return CharacterSet[index]
    }
    
    private func generateRandomGenes(geneLength: Int) -> String
    {
        var genes = ""
        
        let characterSetLength = count(CharacterSet)
        
        for _ in 0..<geneLength
        {
            let index = Int(arc4random_uniform(UInt32(characterSetLength)))
            genes += CharacterSet[index]
        }
        
        return genes
    }
    
    // MARK: -
    
    
    // MARK: - Fitness Methods
    
    private func getFittest() -> GAChromosomeString
    {
        var bestChromosome = self.chromosomes[0]
        
        let populationSize = count(self.chromosomes)
        
        for chromosome in self.chromosomes
        {
            if chromosome.fitness < bestChromosome.fitness
            {
                bestChromosome = chromosome
            }
        }
        
        return bestChromosome
    }
    
    private func calculateFitness(chromosome: GAChromosomeString) -> Int
    {
        var fitness = 0
        
        let geneLength = count(chromosome.genes)
        
        for i in 0..<geneLength
        {
            if Character(chromosome.genes[i]) == Character(self.targetGenes[i])
            {
                fitness += 1
            }
        }
        
        let targetGenesLength = count(self.targetGenes)
        return abs(fitness - targetGenesLength)
    }
    
    // MARK: -
    
    
    // MARK: - Mutation Methods
    
    private func mutate(chromosome: GAChromosomeString)
    {
        let targetLength = count(targetGenes)
        let pivot = Int(arc4random_uniform(UInt32(targetLength)))
        
        var genes = Array(chromosome.genes)
        genes[pivot] = self.generateRandomGene()
        
        var mutatedGenes = String()
        mutatedGenes.extend(genes)
        
        chromosome.genes = mutatedGenes
    }
    
    // MARK: -
    
    
    // MARK: - Selection Methods
    
    private func selectChromosome() -> GAChromosomeString
    {
        let chromosome: GAChromosomeString
        
        switch (self.selectionType)
        {
            case .GAPopulationSelectionTypeRouletteWheel:
                chromosome = self.rouletteWheelSelection()
            break
            
            case .GAPopulationSelectionTypeTournament:
                chromosome = self.tournamentSelection(self.tournamentSize)
            break
            
            default:
                chromosome = self.randomSelection()
            break
        }
        
        return chromosome
    }
    
    private func randomSelection() -> GAChromosomeString
    {
        let populationSize = count(self.chromosomes)
        
        let index = Int(arc4random_uniform(UInt32(populationSize)))
        return self.chromosomes[index]
    }
    
    private func rouletteWheelSelection() -> GAChromosomeString
    {
        let populationSize = count(self.chromosomes)
        
        var totalFitness = 0
        
        for chromosome in self.chromosomes
        {
            totalFitness += chromosome.fitness
        }
        
        let randomNumber = Double(Float(arc4random()) / Float(UINT32_MAX))
        var accumulatedNormalizedFitness = 0.0
        
        var chromosome = self.chromosomes[0]
        
        for i in 0..<populationSize
        {
            chromosome = self.chromosomes[i]
            
            accumulatedNormalizedFitness += (Double(chromosome.fitness) / Double(totalFitness))
            
            if randomNumber < accumulatedNormalizedFitness
            {
                break
            }
        }
        
        return chromosome
    }
    
    private func tournamentSelection(tournamentSize: Int) -> GAChromosomeString
    {
        var competitors = [GAChromosomeString]()
        
        let populationSize = count(self.chromosomes)
        
        for i in 0..<tournamentSize
        {
            let index = Int(arc4random_uniform(UInt32(populationSize)))
            competitors.append(self.chromosomes[index])
        }
        
        var strongestCompetitor = competitors[0]
        
        for i in 1..<tournamentSize
        {
            var competitor = self.chromosomes[i]
            
            if competitor.fitness < strongestCompetitor.fitness
            {
                strongestCompetitor = competitor
            }
        }
        
        return strongestCompetitor
    }
    
    // MARK: -
    
    
    // MARK: - Crossover Methods
    
    private func crossoverPopulation()
    {
        var elitismOffset = 0;
        let populationSize = count(self.chromosomes)
        
        var buffer = [GAChromosomeString]();
        
        if (self.elitismEnabled)
        {
            elitismOffset = Int(self.elitismPercentage * Double(populationSize))
            
            self.chromosomes.sort({$0.fitness < $1.fitness})
            
            for i in 0..<elitismOffset
            {
                let chromosome = self.chromosomes[i]
                buffer.append(chromosome)
            }
        }
        
        for var i = elitismOffset; i < populationSize; i += 2
        {
            let chromosomeA = self.selectChromosome()
            let chromosomeB = self.selectChromosome()
            
            let randomCrossover = Double(Float(arc4random()) / Float(UINT32_MAX))
            
            if randomCrossover < self.crossoverProbability
            {
                let offspring: (first: GAChromosomeString, second: GAChromosomeString)
                
                switch (self.crossoverType)
                {
                case .GAPopulationCrossoverTypeTwoPoint:
                    offspring = self.twoPointCrossover(chromosomeA, chromosomeB: chromosomeB)
                    break
                    
                default:
                    offspring = self.onePointCrossover(chromosomeA, chromosomeB: chromosomeB)
                    break
                }
                
                buffer.append(offspring.first)
                buffer.append(offspring.second)
            }
            else {
                buffer.append(chromosomeA)
                buffer.append(chromosomeB)
            }
        }
        
        self.chromosomes = Array(buffer)
    }
    
    private func onePointCrossover(chromosomeA: GAChromosomeString, chromosomeB: GAChromosomeString) -> (GAChromosomeString, GAChromosomeString)
    {
        let targetLength = Int(count(targetGenes))
        let pivot = Int(arc4random_uniform(UInt32(targetLength)))
        
        let genesToCrossOverA = chromosomeA.genes.substring(pivot, end: targetLength)
        let genesToCrossOverB = chromosomeB.genes.substring(pivot, end: targetLength)
        
        let crossedOverGenesA = chromosomeA.genes.substring(0, end: pivot) + genesToCrossOverB
        let crossedOverGenesB = chromosomeB.genes.substring(0, end: pivot) + genesToCrossOverA
        
        let offspringA = GAChromosomeString(genes: crossedOverGenesA)
        let offspringB = GAChromosomeString(genes: crossedOverGenesB)
        
        let randomMutation = Double(Float(arc4random()) / Float(UINT32_MAX))
        
        if randomMutation < self.mutationProbability
        {
            self.mutate(offspringA)
            self.mutate(offspringB)
        }
        
        offspringA.fitness = self.calculateFitness(offspringA)
        offspringB.fitness = self.calculateFitness(offspringB)
        
        return (offspringA, offspringB)
    }
    
    private func twoPointCrossover(chromosomeA: GAChromosomeString, chromosomeB: GAChromosomeString) -> (GAChromosomeString, GAChromosomeString)
    {
        let targetLength = count(self.targetGenes)
        
        var pivotA = Int(arc4random_uniform(UInt32(targetLength)))
        var pivotB = Int(arc4random_uniform(UInt32(targetLength)))
        
        if (pivotA > pivotB)
        {
            let temp = pivotA
            pivotA = pivotB
            pivotB = temp
        }
        
        let genesToCrossOverA = chromosomeA.genes.substring(pivotA, end: pivotB)
        let genesToCrossOverB = chromosomeB.genes.substring(pivotA, end: pivotB)
        
        let crossedOverGenesA = chromosomeA.genes.substring(0, end: pivotA) + genesToCrossOverB + chromosomeA.genes.substring(pivotB, end: targetLength)
        let crossedOverGenesB = chromosomeB.genes.substring(0, end: pivotA) + genesToCrossOverA + chromosomeA.genes.substring(pivotB, end: targetLength)
        
        let offspringA = GAChromosomeString(genes: crossedOverGenesA)
        let offspringB = GAChromosomeString(genes: crossedOverGenesB)
        
        let randomMutation = Double(Float(arc4random()) / Float(UINT32_MAX))
        
        if randomMutation < self.mutationProbability
        {
            self.mutate(offspringA)
            self.mutate(offspringB)
        }
        
        offspringA.fitness = self.calculateFitness(offspringA)
        offspringB.fitness = self.calculateFitness(offspringB)
        
        return (offspringA, offspringB)
    }
    
    // MARK: -
    
    
    // MARK: - Evolution Methods
    
    func evolve()
    {
        var generationCount = 0
        
        while (self.getFittest().fitness != 0)
        {
            self.crossoverPopulation()
            
            print("[Generation \(generationCount)]\n")
            print("Genes: \(self.getFittest().genes)\n")
            print("Fitness: \(self.getFittest().fitness)\n\n")
            
            generationCount++
        }
    }
    
    // MARK: -
}

