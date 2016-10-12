Imports System
Imports System.Text


Enum CrossoverType
    OnePoint
    TwoPoint
End Enum

Enum SelectionType
    Tournament
    RouletteWheel
    Random
End Enum


Public Class GeneticAlgorithm

    Public elitism = True
    Public elitismPercentage = 0.25
    Public tournamentSize = 2
    Public mutationProbability = 0.25
    Public crossoverProbability = 0.95
    Public crossoverType
    Public selectionType

    Private targetGenes As String
    Private chromosomes As Chromosome()
    Const CHARACTER_SET = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789 ~`!@#$%^&*()_-+=[]{}|;:,.<>?\"""

    Sub New(ByRef populationSize As Integer, ByRef targetGenes As String)
        Me.targetGenes = targetGenes
        chromosomes = New Chromosome(populationSize) {}

        For i = 0 To populationSize
            Dim randomGenes = generateRandomGenes(Me.targetGenes.Length)
            Dim chromosome = New Chromosome(randomGenes)
            chromosome.fitness = calculateFitness(chromosome)
            chromosomes(i) = chromosome
        Next

    End Sub

    Public Sub mutate(ByRef chromosome As Chromosome)
        Dim targetLength = targetGenes.Length
        Dim pivot = CInt(Math.Ceiling(Rnd() * targetLength))

        Dim genes = New StringBuilder(chromosome.genes)
        genes(pivot) = generateRandomGene()

        chromosome.genes = genes.ToString()
    End Sub

    Public Function selection() As Chromosome
        Dim chromosome = chromosomes(0)

        Select Case selectionType
            Case selectionType.Tournament
                chromosome = rouletteWheelSelection()

            Case selectionType.RouletteWheel
                chromosome = tournamentSelection(tournamentSize)

            Case selectionType.Random
                chromosome = randomSelection()

        End Select

        Return chromosome

    End Function

    Function tournamentSelection(ByRef tournamentSize) As Chromosome

        Dim competitors(tournamentSize) As Chromosome
        Dim populationSize = chromosomes.Length

        For i = 0 To tournamentSize
            Dim index = CInt(Math.Ceiling(Rnd() * populationSize))
            competitors(i) = chromosomes(i)
        Next

        Dim strongestCompetitor = competitors(0)

        For i = 1 To tournamentSize
            Dim competitor = chromosomes(i)

            If competitor.fitness < strongestCompetitor.fitness Then
                strongestCompetitor = competitor
            End If
        Next

        Return strongestCompetitor

    End Function

    Function rouletteWheelSelection() As Chromosome
        Dim totalFitness = 0

        For Each chromosome As Chromosome In chromosomes
            totalFitness += chromosome.fitness
        Next

        Dim randomNumber = Rnd()
        Dim accumulatedNormalizedFitness = 0

        Dim selectedChromosome = chromosomes(0)

        For Each chromosome In chromosomes
            accumulatedNormalizedFitness += (chromosome.fitness / totalFitness)

            If randomNumber < accumulatedNormalizedFitness Then
                selectedChromosome = chromosome
                Exit For
            End If
        Next

        Return selectedChromosome

    End Function

    Function randomSelection() As Chromosome
        Dim populationSize = chromosomes.Length
        Dim randomIndex = CInt(Math.Ceiling(Rnd() * populationSize))

        Return chromosomes(randomIndex)
    End Function

    Sub crossover()

        Select Case crossoverType

            Case crossoverType.OnePoint
                onePointCrossover()

            Case crossoverType.TwoPoint
                twoPointCrossover()

        End Select

    End Sub

    Private Sub onePointCrossover()
        Dim buffer(chromosomes.Length) As Chromosome

        Dim populationSize = chromosomes.Length
        Dim targetLength = targetGenes.Length
        Dim elitismOffset = (elitismPercentage * populationSize)

        If elitism Then
            Array.Sort(chromosomes)

            For i = 0 To elitismOffset
                buffer(i) = chromosomes(i)
            Next
        End If

        For i = elitismOffset To populationSize Step 2
            Dim pivot = CInt(Math.Ceiling(Rnd() * targetLength))

            Dim chromosomeA = selection()
            Dim chromosomeB = selection()

            If Rnd() < crossoverProbability Then
                Dim genesToCrossoverA = chromosomeA.genes.Substring(pivot, targetLength)
                Dim genesToCrossoverB = chromosomeB.genes.Substring(pivot, targetLength)

                Dim crossedoverGenesA = chromosomeA.genes.Substring(0, pivot) + genesToCrossoverB
                Dim crossedoverGenesB = chromosomeB.genes.Substring(0, pivot) + genesToCrossoverA

                Dim offspring = New Chromosome(crossedoverGenesA)
                Dim offspring2 = New Chromosome(crossedoverGenesB)

                If Rnd() < mutationProbability Then
                    mutate(offspring)
                    mutate(offspring2)
                End If

                offspring.fitness = calculateFitness(offspring)
                offspring2.fitness = calculateFitness(offspring2)

                buffer(i) = offspring
                buffer(i + 1) = offspring2
            Else
                buffer(i) = chromosomeA
                buffer(i + 1) = chromosomeB
            End If
        Next

        chromosomes = buffer
    End Sub

    Private Sub twoPointCrossover()
        Dim buffer(chromosomes.Length) As Chromosome

        Dim populationSize = chromosomes.Length
        Dim targetLength = targetGenes.Length
        Dim elitismOffset = (elitismPercentage * populationSize)

        If elitism Then
            Array.Sort(chromosomes)

            For i = 0 To elitismOffset
                buffer(i) = chromosomes(i)
            Next
        End If

        For i = elitismOffset To populationSize Step 2
            Dim pivotA = CInt(Math.Ceiling(Rnd() * targetLength))
            Dim pivotB = CInt(Math.Ceiling(Rnd() * targetLength))

            If pivotA > pivotB Then
                Dim temp = pivotA
                pivotA = pivotB
                pivotB = temp
            End If

            Dim chromosomeA = selection()
            Dim chromosomeB = selection()

            If Rnd() < crossoverProbability Then
                Dim genesToCrossoverA = chromosomeA.genes.Substring(pivotA, pivotB)
                Dim genesToCrossoverB = chromosomeB.genes.Substring(pivotA, pivotB)

                Dim crossedoverGenesA = chromosomeA.genes.Substring(0, pivotA) + genesToCrossoverB + chromosomeA.genes.Substring(pivotB, targetLength)
                Dim crossedoverGenesB = chromosomeB.genes.Substring(0, pivotA) + genesToCrossoverA + chromosomeA.genes.Substring(pivotB, targetLength)

                Dim offspring = New Chromosome(crossedoverGenesA)
                Dim offspring2 = New Chromosome(crossedoverGenesB)

                If Rnd() < mutationProbability Then
                    mutate(offspring)
                    mutate(offspring2)
                End If

                offspring.fitness = calculateFitness(offspring)
                offspring2.fitness = calculateFitness(offspring2)

                buffer(i) = offspring
                buffer(i + 1) = offspring2
            Else
                buffer(i) = chromosomeA
                buffer(i + 1) = chromosomeB
            End If
        Next

        chromosomes = buffer
    End Sub

    Function calculateFitness(ByRef chromosome As Chromosome) As Integer
        Dim fitness = 0

        For i = 0 To chromosome.genes.Length
            If chromosome.genes.ToCharArray()(i) = targetGenes.ToCharArray()(i) Then
                fitness += 1
            End If
        Next

        Return Math.Abs(fitness - targetGenes.Length)

    End Function

    Function getFittest() As Chromosome
        Dim fittestChromosome = chromosomes(0)

        For Each chromosome In chromosomes
            If fittestChromosome.fitness < chromosome.fitness Then
                fittestChromosome = chromosome
            End If
        Next

        Return fittestChromosome

    End Function

    Function generateRandomGene() As Char

        Dim index = CInt(Math.Ceiling(Rnd() * CHARACTER_SET.Length))

        Return CHARACTER_SET.ToCharArray()(index)

    End Function

    Function generateRandomGenes(ByRef length As Integer) As String

        Dim buffer = New StringBuilder()
        Dim charactersLength = CHARACTER_SET.Length

        For i = 0 To length
            Dim index = CInt(Math.Ceiling(Rnd() * charactersLength))
            buffer.Append(CHARACTER_SET.ToCharArray()(index))
        Next

        Return buffer.ToString()

    End Function

End Class
