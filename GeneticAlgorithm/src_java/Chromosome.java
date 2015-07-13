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
