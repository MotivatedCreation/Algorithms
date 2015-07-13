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

public class GeneticAlgorithm
{
	// Private Members
	private static GUI gui = new GUI();
	private static Population population;
	private final static boolean ELITISM = true;
	private final static int TOURNAMENT_SIZE = 2;
	private final static int POPULATION_SIZE = 333;
	private final static int ELITISM_PERCENTAGE = 25;
	private final static int MUTATION_PROBABILITY = 20;
	private final static int CROSSOVER_PROBABILITY = 95;
	private final static String EXAMPLE_GENES = "CSCI 421 - Design and Analysis of Algorithms";

	public static void main(String[] args)
	{
        	gui.elitismCheckBox.setSelected(ELITISM);
        	gui.targetGenesTextField.setText(EXAMPLE_GENES);
        	gui.elitismPercentageTextField.setEnabled(ELITISM);
        	gui.tournamentSizeTextField.setText(String.format("%d", TOURNAMENT_SIZE));
        	gui.populationSizeTextField.setText(String.format("%d", POPULATION_SIZE));
        	gui.elitismPercentageTextField.setText(String.format("%d", ELITISM_PERCENTAGE));
        	gui.mutationProbabilityTextField.setText(String.format("%d", MUTATION_PROBABILITY));
        	gui.crossoverProbabilityTextField.setText(String.format("%d", CROSSOVER_PROBABILITY));
        	gui.crossoverTypeComboBox.setSelectedIndex(CrossoverType.CrossoverTypeOnePoint.ordinal());
        	gui.selectionTypeComboBox.setSelectedIndex(SelectionType.SelectionTypeTournament.ordinal());
	}

	public static void evolvePopulation()
	{
        	int generationCount = 0;

        	boolean elitism = gui.elitismCheckBox.isSelected();
        	String targetGenes = gui.targetGenesTextField.getText();
        	int tournamentSize = Integer.parseInt(gui.tournamentSizeTextField.getText());
        	int elitismRate = Integer.parseInt(gui.elitismPercentageTextField.getText());
        	int populationSize = Integer.parseInt(gui.populationSizeTextField.getText());
        	int mutationRate = Integer.parseInt(gui.mutationProbabilityTextField.getText());
        	int crossoverRate = Integer.parseInt(gui.crossoverProbabilityTextField.getText());
        	CrossoverType crossoverType = CrossoverType.values()[gui.crossoverTypeComboBox.getSelectedIndex()];
        	SelectionType selectionType = SelectionType.values()[gui.selectionTypeComboBox.getSelectedIndex()];

        	population = new Population(populationSize, targetGenes);
        	population.crossoverProbability = ((double)crossoverRate / 100);
        	population.mutationProbability = ((double)mutationRate / 100);
        	population.tournamentSize = tournamentSize;
        	population.crossoverType = crossoverType;
        	population.selectionType = selectionType;
        	population.elitism = elitism;

        	if (population.elitism)
        		population.elitismPercentage = ((double)elitismRate / 100);
        	else
        		population.elitismPercentage = 0;

        	while (population.getFittest().getFitness() != 0)
        	{
        		population.crossover();

        		gui.println("[Generation " + generationCount + "]");
        		gui.println(population.getFittest().toString());
        		gui.println("");

        		generationCount++;
        	}
	}

	public static void toggleElitism()
	{
        	boolean elitism = gui.elitismCheckBox.isSelected();
        	int elitismRate = Integer.parseInt(gui.elitismPercentageTextField.getText());

        	gui.elitismPercentageTextField.setEnabled(elitism);

        	if (population != null)
        	{
        		population.elitism = elitism;

        		if (population.elitism)
        			population.elitismPercentage = ((double)elitismRate / 100);
        		else
        			population.elitismPercentage = 0;
        	}
	}

	public static void run()
	{
        	gui.clear();

        	double startTime = System.currentTimeMillis();

        	evolvePopulation();

        	double endTime = System.currentTimeMillis();
        	double elapsedTime = endTime - startTime;

        	gui.println("Time Elapsed: " + elapsedTime + " milliseconds");
	}
}
