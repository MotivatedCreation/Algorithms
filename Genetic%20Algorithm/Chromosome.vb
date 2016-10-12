Public Class Chromosome

    Public genes As String = ""
    Public fitness As Integer = 0

    Public Sub New(ByRef genes As String)
        Me.genes = genes
    End Sub

    Overrides Function ToString() As String
        Return "Genes: " + genes + "\nFitness: " + fitness
    End Function

End Class
