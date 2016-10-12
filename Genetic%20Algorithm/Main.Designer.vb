<Global.Microsoft.VisualBasic.CompilerServices.DesignerGenerated()> _
Partial Class Main
    Inherits System.Windows.Forms.Form

    'Form overrides dispose to clean up the component list.
    <System.Diagnostics.DebuggerNonUserCode()> _
    Protected Overrides Sub Dispose(ByVal disposing As Boolean)
        Try
            If disposing AndAlso components IsNot Nothing Then
                components.Dispose()
            End If
        Finally
            MyBase.Dispose(disposing)
        End Try
    End Sub

    'Required by the Windows Form Designer
    Private components As System.ComponentModel.IContainer

    'NOTE: The following procedure is required by the Windows Form Designer
    'It can be modified using the Windows Form Designer.  
    'Do not modify it using the code editor.
    <System.Diagnostics.DebuggerStepThrough()> _
    Private Sub InitializeComponent()
        Me.Label1 = New System.Windows.Forms.Label()
        Me.TargetGenesTextBox = New System.Windows.Forms.TextBox()
        Me.RichTextBox1 = New System.Windows.Forms.RichTextBox()
        Me.RunButton = New System.Windows.Forms.Button()
        Me.GroupBox1 = New System.Windows.Forms.GroupBox()
        Me.PopulationSizeTextBox = New System.Windows.Forms.TextBox()
        Me.Label2 = New System.Windows.Forms.Label()
        Me.GroupBox2 = New System.Windows.Forms.GroupBox()
        Me.MutationProbabilityTextBox = New System.Windows.Forms.TextBox()
        Me.Label3 = New System.Windows.Forms.Label()
        Me.GroupBox3 = New System.Windows.Forms.GroupBox()
        Me.SelectionTypeComboBox = New System.Windows.Forms.ComboBox()
        Me.Label4 = New System.Windows.Forms.Label()
        Me.GroupBox4 = New System.Windows.Forms.GroupBox()
        Me.CrossoverTypeComboBox = New System.Windows.Forms.ComboBox()
        Me.Label6 = New System.Windows.Forms.Label()
        Me.CrossoverProbabilityTextBox = New System.Windows.Forms.TextBox()
        Me.Label5 = New System.Windows.Forms.Label()
        Me.GroupBox5 = New System.Windows.Forms.GroupBox()
        Me.ElitismPercentageTextBox = New System.Windows.Forms.TextBox()
        Me.ElitismCheckBox = New System.Windows.Forms.CheckBox()
        Me.Label7 = New System.Windows.Forms.Label()
        Me.GroupBox1.SuspendLayout()
        Me.GroupBox2.SuspendLayout()
        Me.GroupBox3.SuspendLayout()
        Me.GroupBox4.SuspendLayout()
        Me.GroupBox5.SuspendLayout()
        Me.SuspendLayout()
        '
        'Label1
        '
        Me.Label1.AutoSize = True
        Me.Label1.Location = New System.Drawing.Point(12, 9)
        Me.Label1.Name = "Label1"
        Me.Label1.Size = New System.Drawing.Size(75, 13)
        Me.Label1.TabIndex = 0
        Me.Label1.Text = "Target Genes:"
        '
        'TargetGenesTextBox
        '
        Me.TargetGenesTextBox.Location = New System.Drawing.Point(93, 6)
        Me.TargetGenesTextBox.Name = "TargetGenesTextBox"
        Me.TargetGenesTextBox.Size = New System.Drawing.Size(523, 20)
        Me.TargetGenesTextBox.TabIndex = 1
        Me.TargetGenesTextBox.Text = "CSCI 421 - Design and Analysis of Algorithms"
        '
        'RichTextBox1
        '
        Me.RichTextBox1.Location = New System.Drawing.Point(15, 32)
        Me.RichTextBox1.Name = "RichTextBox1"
        Me.RichTextBox1.ReadOnly = True
        Me.RichTextBox1.Size = New System.Drawing.Size(311, 396)
        Me.RichTextBox1.TabIndex = 2
        Me.RichTextBox1.Text = ""
        '
        'RunButton
        '
        Me.RunButton.Location = New System.Drawing.Point(277, 447)
        Me.RunButton.Name = "RunButton"
        Me.RunButton.Size = New System.Drawing.Size(75, 23)
        Me.RunButton.TabIndex = 3
        Me.RunButton.Text = "Run"
        Me.RunButton.UseVisualStyleBackColor = True
        '
        'GroupBox1
        '
        Me.GroupBox1.Controls.Add(Me.PopulationSizeTextBox)
        Me.GroupBox1.Controls.Add(Me.Label2)
        Me.GroupBox1.Location = New System.Drawing.Point(332, 32)
        Me.GroupBox1.Name = "GroupBox1"
        Me.GroupBox1.Size = New System.Drawing.Size(284, 55)
        Me.GroupBox1.TabIndex = 4
        Me.GroupBox1.TabStop = False
        Me.GroupBox1.Text = "Population"
        '
        'PopulationSizeTextBox
        '
        Me.PopulationSizeTextBox.Location = New System.Drawing.Point(94, 17)
        Me.PopulationSizeTextBox.Name = "PopulationSizeTextBox"
        Me.PopulationSizeTextBox.Size = New System.Drawing.Size(184, 20)
        Me.PopulationSizeTextBox.TabIndex = 1
        Me.PopulationSizeTextBox.Text = "333"
        '
        'Label2
        '
        Me.Label2.AutoSize = True
        Me.Label2.Location = New System.Drawing.Point(7, 20)
        Me.Label2.Name = "Label2"
        Me.Label2.Size = New System.Drawing.Size(83, 13)
        Me.Label2.TabIndex = 0
        Me.Label2.Text = "Population Size:"
        '
        'GroupBox2
        '
        Me.GroupBox2.Controls.Add(Me.MutationProbabilityTextBox)
        Me.GroupBox2.Controls.Add(Me.Label3)
        Me.GroupBox2.Location = New System.Drawing.Point(332, 93)
        Me.GroupBox2.Name = "GroupBox2"
        Me.GroupBox2.Size = New System.Drawing.Size(284, 60)
        Me.GroupBox2.TabIndex = 5
        Me.GroupBox2.TabStop = False
        Me.GroupBox2.Text = "Mutation"
        '
        'MutationProbabilityTextBox
        '
        Me.MutationProbabilityTextBox.Location = New System.Drawing.Point(128, 23)
        Me.MutationProbabilityTextBox.Name = "MutationProbabilityTextBox"
        Me.MutationProbabilityTextBox.Size = New System.Drawing.Size(148, 20)
        Me.MutationProbabilityTextBox.TabIndex = 3
        Me.MutationProbabilityTextBox.Text = "25"
        '
        'Label3
        '
        Me.Label3.AutoSize = True
        Me.Label3.Location = New System.Drawing.Point(6, 26)
        Me.Label3.Name = "Label3"
        Me.Label3.Size = New System.Drawing.Size(119, 13)
        Me.Label3.TabIndex = 2
        Me.Label3.Text = "Mutation Probability (%):"
        '
        'GroupBox3
        '
        Me.GroupBox3.Controls.Add(Me.SelectionTypeComboBox)
        Me.GroupBox3.Controls.Add(Me.Label4)
        Me.GroupBox3.Location = New System.Drawing.Point(332, 159)
        Me.GroupBox3.Name = "GroupBox3"
        Me.GroupBox3.Size = New System.Drawing.Size(284, 57)
        Me.GroupBox3.TabIndex = 6
        Me.GroupBox3.TabStop = False
        Me.GroupBox3.Text = "Selection"
        '
        'SelectionTypeComboBox
        '
        Me.SelectionTypeComboBox.FormattingEnabled = True
        Me.SelectionTypeComboBox.Items.AddRange(New Object() {"Random", "Tournament", "RouleteWheel"})
        Me.SelectionTypeComboBox.Location = New System.Drawing.Point(94, 22)
        Me.SelectionTypeComboBox.Name = "SelectionTypeComboBox"
        Me.SelectionTypeComboBox.Size = New System.Drawing.Size(184, 21)
        Me.SelectionTypeComboBox.TabIndex = 5
        '
        'Label4
        '
        Me.Label4.AutoSize = True
        Me.Label4.Location = New System.Drawing.Point(7, 25)
        Me.Label4.Name = "Label4"
        Me.Label4.Size = New System.Drawing.Size(81, 13)
        Me.Label4.TabIndex = 4
        Me.Label4.Text = "Selection Type:"
        '
        'GroupBox4
        '
        Me.GroupBox4.Controls.Add(Me.CrossoverTypeComboBox)
        Me.GroupBox4.Controls.Add(Me.Label6)
        Me.GroupBox4.Controls.Add(Me.CrossoverProbabilityTextBox)
        Me.GroupBox4.Controls.Add(Me.Label5)
        Me.GroupBox4.Location = New System.Drawing.Point(332, 222)
        Me.GroupBox4.Name = "GroupBox4"
        Me.GroupBox4.Size = New System.Drawing.Size(284, 100)
        Me.GroupBox4.TabIndex = 7
        Me.GroupBox4.TabStop = False
        Me.GroupBox4.Text = "Crossover"
        '
        'CrossoverTypeComboBox
        '
        Me.CrossoverTypeComboBox.FormattingEnabled = True
        Me.CrossoverTypeComboBox.Items.AddRange(New Object() {"One Point", "Two Point"})
        Me.CrossoverTypeComboBox.Location = New System.Drawing.Point(94, 58)
        Me.CrossoverTypeComboBox.Name = "CrossoverTypeComboBox"
        Me.CrossoverTypeComboBox.Size = New System.Drawing.Size(184, 21)
        Me.CrossoverTypeComboBox.TabIndex = 6
        '
        'Label6
        '
        Me.Label6.AutoSize = True
        Me.Label6.Location = New System.Drawing.Point(6, 61)
        Me.Label6.Name = "Label6"
        Me.Label6.Size = New System.Drawing.Size(84, 13)
        Me.Label6.TabIndex = 6
        Me.Label6.Text = "Crossover Type:"
        '
        'CrossoverProbabilityTextBox
        '
        Me.CrossoverProbabilityTextBox.Location = New System.Drawing.Point(138, 24)
        Me.CrossoverProbabilityTextBox.Name = "CrossoverProbabilityTextBox"
        Me.CrossoverProbabilityTextBox.Size = New System.Drawing.Size(140, 20)
        Me.CrossoverProbabilityTextBox.TabIndex = 5
        Me.CrossoverProbabilityTextBox.Text = "95"
        '
        'Label5
        '
        Me.Label5.AutoSize = True
        Me.Label5.Location = New System.Drawing.Point(7, 27)
        Me.Label5.Name = "Label5"
        Me.Label5.Size = New System.Drawing.Size(125, 13)
        Me.Label5.TabIndex = 4
        Me.Label5.Text = "Crossover Probability (%):"
        '
        'GroupBox5
        '
        Me.GroupBox5.Controls.Add(Me.ElitismPercentageTextBox)
        Me.GroupBox5.Controls.Add(Me.ElitismCheckBox)
        Me.GroupBox5.Controls.Add(Me.Label7)
        Me.GroupBox5.Location = New System.Drawing.Point(332, 328)
        Me.GroupBox5.Name = "GroupBox5"
        Me.GroupBox5.Size = New System.Drawing.Size(284, 100)
        Me.GroupBox5.TabIndex = 8
        Me.GroupBox5.TabStop = False
        Me.GroupBox5.Text = "Elitism"
        '
        'ElitismPercentageTextBox
        '
        Me.ElitismPercentageTextBox.Location = New System.Drawing.Point(71, 55)
        Me.ElitismPercentageTextBox.Name = "ElitismPercentageTextBox"
        Me.ElitismPercentageTextBox.Size = New System.Drawing.Size(207, 20)
        Me.ElitismPercentageTextBox.TabIndex = 9
        Me.ElitismPercentageTextBox.Text = "25"
        '
        'ElitismCheckBox
        '
        Me.ElitismCheckBox.AutoSize = True
        Me.ElitismCheckBox.Checked = True
        Me.ElitismCheckBox.CheckState = System.Windows.Forms.CheckState.Checked
        Me.ElitismCheckBox.Location = New System.Drawing.Point(10, 28)
        Me.ElitismCheckBox.Name = "ElitismCheckBox"
        Me.ElitismCheckBox.Size = New System.Drawing.Size(55, 17)
        Me.ElitismCheckBox.TabIndex = 7
        Me.ElitismCheckBox.Text = "Elitism"
        Me.ElitismCheckBox.UseVisualStyleBackColor = True
        '
        'Label7
        '
        Me.Label7.AutoSize = True
        Me.Label7.Location = New System.Drawing.Point(9, 58)
        Me.Label7.Name = "Label7"
        Me.Label7.Size = New System.Drawing.Size(56, 13)
        Me.Label7.TabIndex = 6
        Me.Label7.Text = "Elitism (%):"
        '
        'Main
        '
        Me.AutoScaleDimensions = New System.Drawing.SizeF(6.0!, 13.0!)
        Me.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font
        Me.ClientSize = New System.Drawing.Size(628, 492)
        Me.Controls.Add(Me.GroupBox5)
        Me.Controls.Add(Me.GroupBox4)
        Me.Controls.Add(Me.GroupBox3)
        Me.Controls.Add(Me.GroupBox2)
        Me.Controls.Add(Me.GroupBox1)
        Me.Controls.Add(Me.RunButton)
        Me.Controls.Add(Me.RichTextBox1)
        Me.Controls.Add(Me.TargetGenesTextBox)
        Me.Controls.Add(Me.Label1)
        Me.Name = "Main"
        Me.Text = "Genetic Algorithm"
        Me.GroupBox1.ResumeLayout(False)
        Me.GroupBox1.PerformLayout()
        Me.GroupBox2.ResumeLayout(False)
        Me.GroupBox2.PerformLayout()
        Me.GroupBox3.ResumeLayout(False)
        Me.GroupBox3.PerformLayout()
        Me.GroupBox4.ResumeLayout(False)
        Me.GroupBox4.PerformLayout()
        Me.GroupBox5.ResumeLayout(False)
        Me.GroupBox5.PerformLayout()
        Me.ResumeLayout(False)
        Me.PerformLayout()

    End Sub
    Friend WithEvents Label1 As System.Windows.Forms.Label
    Friend WithEvents TargetGenesTextBox As System.Windows.Forms.TextBox
    Friend WithEvents RichTextBox1 As System.Windows.Forms.RichTextBox
    Friend WithEvents RunButton As System.Windows.Forms.Button
    Friend WithEvents GroupBox1 As System.Windows.Forms.GroupBox
    Friend WithEvents PopulationSizeTextBox As System.Windows.Forms.TextBox
    Friend WithEvents Label2 As System.Windows.Forms.Label
    Friend WithEvents GroupBox2 As System.Windows.Forms.GroupBox
    Friend WithEvents MutationProbabilityTextBox As System.Windows.Forms.TextBox
    Friend WithEvents Label3 As System.Windows.Forms.Label
    Friend WithEvents GroupBox3 As System.Windows.Forms.GroupBox
    Friend WithEvents GroupBox4 As System.Windows.Forms.GroupBox
    Friend WithEvents SelectionTypeComboBox As System.Windows.Forms.ComboBox
    Friend WithEvents Label4 As System.Windows.Forms.Label
    Friend WithEvents CrossoverTypeComboBox As System.Windows.Forms.ComboBox
    Friend WithEvents Label6 As System.Windows.Forms.Label
    Friend WithEvents CrossoverProbabilityTextBox As System.Windows.Forms.TextBox
    Friend WithEvents Label5 As System.Windows.Forms.Label
    Friend WithEvents GroupBox5 As System.Windows.Forms.GroupBox
    Friend WithEvents ElitismPercentageTextBox As System.Windows.Forms.TextBox
    Friend WithEvents ElitismCheckBox As System.Windows.Forms.CheckBox
    Friend WithEvents Label7 As System.Windows.Forms.Label

End Class
