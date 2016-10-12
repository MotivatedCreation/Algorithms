Public Class Main

    Private geneticAlgorithm As GeneticAlgorithm
    Private elitism = True
    Private tournamentSize = 2
    Private populationSize = 333
    Private elitismPercentage = 0.25
    Private mutationProbability = 0.25
    Private crossoverProbability = 0.95
    Private exampleTargetGenes = "CSCI 421 - Design and Analysis of Algorithms"

    Sub evolvePopulation()
        Dim generationCount = 0
        Dim targetGenes = TargetGenesTextBox.Text
        'Dim tournamentSize = 
        Dim elitismRate = Convert.ToInt32(ElitismPercentageTextBox.Text)
        Dim populationSize = Convert.ToInt32(PopulationSizeTextBox.Text)
        Dim mutationRate = Convert.ToDouble(MutationProbabilityTextBox.Text)
        Dim crossoverRate = Convert.ToDouble(CrossoverProbabilityTextBox.Text)
        Dim crossoverType = CrossoverTypeComboBox.SelectedItem
        Dim selectionType = SelectionTypeComboBox.SelectedItem

        geneticAlgorithm = New GeneticAlgorithm(populationSize, targetGenes)
        geneticAlgorithm.crossoverProbability = (crossoverRate / 100)
        geneticAlgorithm.mutationProbability = (mutationRate / 100)
        'geneticAlgorithm.tournamentSize = tournamentSize
        'geneticAlgorithm.crossoverType = CrossoverType
        'geneticAlgorithm.selectionType = SelectionType
        geneticAlgorithm.elitism = elitism

        If geneticAlgorithm.elitism Then
            geneticAlgorithm.elitismPercentage = (elitismRate / 100)

        Else
            geneticAlgorithm.elitismPercentage = 0
        End If

        While geneticAlgorithm.getFittest().fitness <> 0
            geneticAlgorithm.crossover()

            generationCount += 1

        End While
    End Sub

    Private Sub RunButton_Click(sender As Object, e As EventArgs) Handles RunButton.Click
        evolvePopulation()
    End Sub

End Class