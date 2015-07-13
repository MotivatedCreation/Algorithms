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

public class Chromosome implements Comparable<Chromosome>
{
	// Private members
	private int fitness;
	private String genes;
	
	// Getter methods
	public int getFitness()
	{
		return this.fitness;
	}
	
	public String getGenes()
	{
		return this.genes;
	}
	
	// Setter Methods
	public void setFitness(int theFitness)
	{
		this.fitness = theFitness;
	}

	public void setGenes(String theGenes)
    	{
        	this.genes = theGenes;
    	}
	
	// Constructors
	public Chromosome(String theGenes)
	{
		this.genes = theGenes;
	}
	
	// Overrides
    	@Override
	public String toString()
	{
		return "Genes: " + this.genes + "\nFitness: " + this.fitness;
	}

	public int compareTo(Chromosome chromosome)
	{
		if (this.fitness > chromosome.getFitness())
			return 1;
		else if (this.fitness < chromosome.getFitness())
			return -1;
		else
			return 0;
	}
}
