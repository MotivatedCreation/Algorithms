Public Class GeneticAlgorithm

    Private targetGenes As String
    Private chromosomes As Chromosome()

    Sub New(ByRef populationSize As Integer, ByRef targetGenes As String)
        Me.targetGenes = targetGenes
        chromosomes = New Chromosome(populationSize) {}

        For i As Integer = 0 To populationSize
            Dim randomGenes = GenerateRandomGenes(Me.targetGenes.Length)
            Dim chromosome As Chromosome = New Chromosome(randomGenes)
            chromosome.fitness = CalculateFitness(chromosome)
            chromosomes(i) = chromosome
        Next

    End Sub

    Public Sub mutate(ByRef chromosome As Chromosome)
        Dim targetLength = targetGenes.Length
        Dim pivot = CInt(Math.Ceiling(Rnd() * targetLength)) + 0

        Dim genes = chromosome.genes
    End Sub

    Function GenerateRandomGenes(ByRef length As Integer)

        Return ""

    End Function

    Function CalculateFitness(ByRef chromosome As Chromosome)

        Return 0

    End Function
End Class
