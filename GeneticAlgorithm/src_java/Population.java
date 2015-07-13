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

import java.util.ArrayList;
import java.util.Collections;
import java.util.Random;

enum CrossoverType
{
	CrossoverTypeOnePoint,
	CrossoverTypeTwoPoint
}

enum SelectionType
{
	SelectionTypeTournament,
	SelectionTypeRouletteWheel,
	SelectionTypeRandom
}

public class Population
{
	// Public Members
	public boolean elitism = true;
	public double elitismPercentage = 0.25;
	public int tournamentSize = 2;

	/**
	* The probability of individual chromosomes being mutated.
	*/
	public double mutationProbability = 0.25;

	/**
	* The probability of crossover between two chromosomes.
	*/
	public double crossoverProbability = 0.8;

	/**
	* The type of crossover function (e.g. CrossoverTypeOnePoint, CrossoverTypeTwoPoint).
	*/
	public CrossoverType crossoverType = CrossoverType.CrossoverTypeOnePoint;

	/**
	* The type of selection function (e.g. SelectionTypeTournament).
	*/
	public SelectionType selectionType = SelectionType.SelectionTypeTournament;

	// Private Members
	private String targetGenes;
	private Random random = new Random();
	private ArrayList<Chromosome> chromosomes = new ArrayList<Chromosome>();
	private final String CHARACTER_SET = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789 ~`!@#$%^&*()_-+=[]{}|;:,.<>?\"";
	
	// Constructors
	/**
	*
	* @param thePopulationSize
	* The size of the population.
	* @param theTargetGenes
	* The target genes.
	*/
	public Population(int thePopulationSize, String theTargetGenes)
	{
		this.targetGenes = theTargetGenes;

		for (int i = 0; i < thePopulationSize; i++)
		{
			String genes = generateRandomGenes(targetGenes.length());

			Chromosome chromosome = new Chromosome(genes);
            		chromosome.setFitness(calculateFitness(chromosome));
			this.chromosomes.add(chromosome);
		}
	}

	// Mutation Methods
	public void mutate(Chromosome chromosome)
	{
        	int targetLength = this.targetGenes.length();
        	int pivot = random.nextInt(targetLength);

        	StringBuilder genes = new StringBuilder(chromosome.getGenes());
        	genes.setCharAt(pivot, generateRandomGene());

        	chromosome.setGenes(genes.toString());
	}

	// Selection Methods
	public Chromosome selection()
	{
		Chromosome chromosome;

        	switch (this.selectionType)
        	{
            		case SelectionTypeRouletteWheel:
            		{
                		chromosome = rouletteWheelSelection();
            		}
            		break;

            		case SelectionTypeTournament:
            		{
                		chromosome = tournamentSelection(tournamentSize);
            		}
            		break;

            		case SelectionTypeRandom:
            		default:
            		{
                		chromosome = randomSelection();
            		}
            		break;
        	}

		return chromosome;
    	}

    	public Chromosome tournamentSelection(int theTournamentSize)
    	{
    		Chromosome competitors[] = new Chromosome[theTournamentSize];
    	
        	int populationSize = this.chromosomes.size();

        	for (int i = 0; i < theTournamentSize; i++)
        	{
        		int index = random.nextInt(populationSize);
        		competitors[i] = this.chromosomes.get(index);
        	}
        
        	Chromosome strongestCompetitor = competitors[0];
        
        	for (int i = 1; i < theTournamentSize; i++)
        	{
            		Chromosome competitor = this.chromosomes.get(i);

            		if (competitor.getFitness() < strongestCompetitor.getFitness())
                		strongestCompetitor = competitor;
        	}
        
        	return strongestCompetitor;
    	}

    	public Chromosome rouletteWheelSelection()
    	{
        	int totalFitness = 0;

        	for (Chromosome chromosome : this.chromosomes)
            		totalFitness += chromosome.getFitness();

        	double randomNumber = Math.random();
        	double accumulatedNormalizedFitness = 0;

        	Chromosome chromosome = null;

        	for (Chromosome theChromosome : this.chromosomes)
        	{
            		accumulatedNormalizedFitness += (theChromosome.getFitness() / (double)totalFitness);

            		if (randomNumber < accumulatedNormalizedFitness)
            		{
                		chromosome = theChromosome;
                		break;
            		}
        	}

        	return chromosome;
    	}

    	public Chromosome randomSelection()
    	{
        	int populationSize = this.chromosomes.size();

        	int index = random.nextInt(populationSize);

        	return this.chromosomes.get(index);
    	}

    	// Crossover Methods
    	public void crossover()
    	{
        	switch (this.crossoverType)
        	{
            		case CrossoverTypeTwoPoint:
            		{
        			twoPointCrossover();
            		}
            		break;

            		case CrossoverTypeOnePoint:
            		default:
            		{
                		onePointCrossover();
            		}
            		break;
        	}
    	}

	private void onePointCrossover()
	{
        	ArrayList<Chromosome> buffer = new ArrayList<Chromosome>();

		int populationSize = this.chromosomes.size();
		int targetLength = this.targetGenes.length();
        	int elitismOffset = (int)(this.elitismPercentage * populationSize);

        	if (this.elitism)
        	{
            		Collections.sort(this.chromosomes);

            		for (int i = 0; i < elitismOffset; i++)
                		buffer.add(this.chromosomes.get(i));
        	}

		for (int i = elitismOffset; i < populationSize; i += 2)
		{
            		int pivot = random.nextInt(targetLength);

            		Chromosome chromosomeA = selection();
            		Chromosome chromosomeB = selection();

            		if (Math.random() < this.crossoverProbability)
            		{
                		String genesToCrossOverA = chromosomeA.getGenes().substring(pivot, targetLength);
                		String genesToCrossOverB = chromosomeA.getGenes().substring(pivot, targetLength);

                		String crossedOverGenesA = chromosomeA.getGenes().substring(0, pivot) + genesToCrossOverB;
                		String crossedOverGenesB = chromosomeB.getGenes().substring(0, pivot) + genesToCrossOverA;

                		Chromosome offspring = new Chromosome(crossedOverGenesA);
                		Chromosome offspring2 = new Chromosome(crossedOverGenesB);

                		if (Math.random() < this.mutationProbability)
                		{
                    			mutate(offspring);
                    			mutate(offspring2);
                		}

                		offspring.setFitness(calculateFitness(offspring));
                		offspring2.setFitness(calculateFitness(offspring2));

                		buffer.add(offspring);
                		buffer.add(offspring2);
            		}
            		else {
                		buffer.add(chromosomeA);
                		buffer.add(chromosomeB);
            		}
		}

		this.chromosomes = buffer;
	}

    	private void twoPointCrossover()
    	{
        	ArrayList<Chromosome> buffer = new ArrayList<Chromosome>();

        	int populationSize = this.chromosomes.size();
        	int targetLength = this.targetGenes.length();

        	for (int i = 0; i < populationSize; i += 2)
        	{
            		int pivotA = random.nextInt(targetLength);
            		int pivotB = random.nextInt(targetLength);

            		if (pivotA > pivotB)
            		{
                		int temp = pivotA;
                		pivotA = pivotB;
                		pivotB = temp;
            		}

            		Chromosome chromosomeA = selection();
            		Chromosome chromosomeB = selection();

            		if (Math.random() < this.crossoverProbability)
            		{
                		String genesToCrossOverA = chromosomeA.getGenes().substring(pivotA, pivotB);
                		String genesToCrossOverB = chromosomeA.getGenes().substring(pivotA, pivotB);

                		String crossedOverGenesA = chromosomeA.getGenes().substring(0, pivotA) + genesToCrossOverB + chromosomeA.getGenes().substring(pivotB, targetLength);
                		String crossedOverGenesB = chromosomeB.getGenes().substring(0, pivotA) + genesToCrossOverA + chromosomeA.getGenes().substring(pivotB, targetLength);

                		Chromosome offspring = new Chromosome(crossedOverGenesA);
		                Chromosome offspring2 = new Chromosome(crossedOverGenesB);

                		if (Math.random() < this.mutationProbability)
                		{
                			mutate(offspring);
                    			mutate(offspring2);
                		}

                		offspring.setFitness(calculateFitness(offspring));
                		offspring2.setFitness(calculateFitness(offspring2));

                		buffer.add(offspring);
                		buffer.add(offspring2);
            		}
            		else {
                		buffer.add(chromosomeA);
                		buffer.add(chromosomeB);
            		}
        	}

        	this.chromosomes = buffer;
    	}
	
	// Fitness Methods
    	private int calculateFitness(Chromosome theChromosome)
    	{
        	int fitness = 0;

        	for (int i = 0; i < theChromosome.getGenes().length(); i++)
            		if (theChromosome.getGenes().charAt(i) == this.targetGenes.charAt(i))
                		fitness += 1;

        	return Math.abs(fitness - targetGenes.length());
    	}
	
	// Helper Methods
    	/**
     	*
     	* @return
     	* The fittest chromosome in the population.
     	*/
    	public Chromosome getFittest()
    	{
        	Chromosome bestChromosome = this.chromosomes.get(0);

        	for (Chromosome chromosome : this.chromosomes)
            		if (chromosome.getFitness() < bestChromosome.getFitness())
                		bestChromosome = chromosome;

        	return bestChromosome;
    	}

    	private char generateRandomGene()
    	{
        	return CHARACTER_SET.charAt(random.nextInt(CHARACTER_SET.length()));
    	}

	private String generateRandomGenes(int theLength)
	{
        	StringBuilder buffer = new StringBuilder();

		int charactersLength = CHARACTER_SET.length();

		for (int i = 0; i < theLength; i++)
		{
			int index = random.nextInt(charactersLength);
			buffer.append(CHARACTER_SET.charAt(index));
		}

		return buffer.toString();
	}
	
	// Overrides
    	/**
     	*
     	* @return
     	* The string representation of the population.
     	*/
    	@Override
	public String toString()
	{
		StringBuilder string = new StringBuilder();
		
		for (Chromosome chromosome : this.chromosomes)
		{
			string.append(chromosome.toString());
			string.append("\n");
		}
		
		return string.toString();
	}
}
