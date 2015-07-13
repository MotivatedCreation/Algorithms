import java.awt.Dimension;
import javax.swing.JFrame;
import javax.swing.JPanel;
import javax.swing.JLabel;
import javax.swing.JButton;
import javax.swing.JTextArea;
import javax.swing.JComboBox;
import javax.swing.JCheckBox;
import javax.swing.BoxLayout;
import javax.swing.JTextField;
import javax.swing.JScrollPane;
import javax.swing.border.TitledBorder;
import javax.swing.text.DefaultCaret;
import java.awt.event.ActionListener;
import java.awt.event.ActionEvent;
import java.awt.BorderLayout;

public class GUI extends JFrame implements ActionListener
{
	// Private Members
    	private final static long serialVersionUID = 1;

    	private final String RUN_ACTION_COMMAND = "Run";
    	private final String ELITISM_ACTION_COMMAND = "Elitism";
    	private final String SELECTION_TYPE_ACTION_COMMAND = "SelectionTypeChanged";

    	private JPanel selectionPanel = new JPanel();
    	private JPanel tournamentSizePanel = new JPanel();

    	private JTextArea outputTextArea = new JTextArea(24, 44);

    	private final String crossoverTypes[] = {"One Point", "Two Point"};
    	private final String selectionTypes[] = {"Tournament", "Roulette Wheel", "Random"};
    
    	// Public Members
    	public JCheckBox elitismCheckBox = new JCheckBox();
    	public JTextField targetGenesTextField = new JTextField(38);
    	public JTextField populationSizeTextField = new JTextField(8);
    	public JTextField tournamentSizeTextField = new JTextField(8);
    	public JTextField elitismPercentageTextField = new JTextField(3);
    	public JTextField mutationProbabilityTextField = new JTextField(3);
    	public JTextField crossoverProbabilityTextField = new JTextField(3);
    	public JComboBox crossoverTypeComboBox = new JComboBox(crossoverTypes);
    	public JComboBox selectionTypeComboBox = new JComboBox(selectionTypes);

    	public GUI()
    	{
        	JPanel panel = new JPanel(new BorderLayout());
        	this.add(panel);
        
        	JPanel targetGenesPanel = new JPanel();
        	panel.add(targetGenesPanel, BorderLayout.NORTH);
        
        	JLabel inputLabel = new JLabel("Target Genes:");
        	targetGenesPanel.add(inputLabel);
        
        	targetGenesPanel.add(targetGenesTextField);

        	JPanel settingsPanel = new JPanel();
        	settingsPanel.setLayout(new BoxLayout(settingsPanel, BoxLayout.PAGE_AXIS));
        	panel.add(settingsPanel, BorderLayout.EAST);
        
        	JPanel populationPanel = new JPanel();
        	settingsPanel.add(populationPanel);
        
        	TitledBorder populationTitleBorder = new TitledBorder("Population");
        	populationPanel.setBorder(populationTitleBorder);
        
        	JLabel populationSizeLabel = new JLabel("Population Size:");
        	populationPanel.add(populationSizeLabel);

        	populationPanel.add(populationSizeTextField);
        
        	JPanel mutationPanel = new JPanel();
        	settingsPanel.add(mutationPanel);
        
        	TitledBorder mutationTitleBorder = new TitledBorder("Mutation");
        	mutationPanel.setBorder(mutationTitleBorder);
        
        	JLabel mutationProbabilityLabel = new JLabel("Mutation Probability (%):");
        	mutationPanel.add(mutationProbabilityLabel);

        	mutationPanel.add(mutationProbabilityTextField);

        	selectionPanel.setLayout(new BoxLayout(selectionPanel, BoxLayout.PAGE_AXIS));
        	settingsPanel.add(selectionPanel);

        	TitledBorder selectionTitleBorder = new TitledBorder("Selection");
        	selectionPanel.setBorder(selectionTitleBorder);

        	JPanel selectionTypePanel = new JPanel();
        	selectionPanel.add(selectionTypePanel);

        	JLabel selectionTypeLabel = new JLabel("Selection Type:");
        	selectionTypePanel.add(selectionTypeLabel);

        	selectionTypeComboBox.addActionListener(this);
        	selectionTypeComboBox.setActionCommand(SELECTION_TYPE_ACTION_COMMAND);
        	selectionTypePanel.add(selectionTypeComboBox);

        	selectionPanel.add(tournamentSizePanel);

        	JLabel tournamentSizeLabel = new JLabel("Tournament Size:");
        	tournamentSizePanel.add(tournamentSizeLabel);

        	tournamentSizePanel.add(tournamentSizeTextField);

        	JPanel crossoverPanel = new JPanel();
        	crossoverPanel.setLayout(new BoxLayout(crossoverPanel, BoxLayout.PAGE_AXIS));
        	settingsPanel.add(crossoverPanel);
        
        	TitledBorder crossoverTitleBorder = new TitledBorder("Crossover");
        	crossoverPanel.setBorder(crossoverTitleBorder);
        
        	JPanel crossoverProbabilityPanel = new JPanel();
        	crossoverPanel.add(crossoverProbabilityPanel);
        
        	JLabel crossoverProbabilityLabel = new JLabel("Crossover Probability (%):");
        	crossoverProbabilityPanel.add(crossoverProbabilityLabel);

        	crossoverProbabilityPanel.add(crossoverProbabilityTextField);

        	JPanel crossoverTypePanel = new JPanel();
        	crossoverPanel.add(crossoverTypePanel);
        
        	JLabel crossoverTypeLabel = new JLabel("Crossover Type:");
        	crossoverTypePanel.add(crossoverTypeLabel);

        	crossoverTypePanel.add(crossoverTypeComboBox);

        	JPanel elitismPanel = new JPanel();
        	elitismPanel.setLayout(new BoxLayout(elitismPanel, BoxLayout.PAGE_AXIS));
        	settingsPanel.add(elitismPanel);
        
        	TitledBorder elitismTitleBorder = new TitledBorder("Elitism");
        	elitismPanel.setBorder(elitismTitleBorder);
        
        	JPanel elitismEnabledPanel = new JPanel();
        	elitismPanel.add(elitismEnabledPanel);
        
        	JLabel elitismLabel = new JLabel("Elitism:");
        	elitismEnabledPanel.add(elitismLabel);
        
        	elitismCheckBox.addActionListener(this);
        	elitismCheckBox.setActionCommand(ELITISM_ACTION_COMMAND);
        	elitismEnabledPanel.add(elitismCheckBox);

        	JPanel elitismPercentagePanel = new JPanel();
        	elitismPanel.add(elitismPercentagePanel);
        
        	JLabel elitismPercentageLabel = new JLabel("Elitism (%):");
        	elitismPercentagePanel.add(elitismPercentageLabel);

        	elitismPercentagePanel.add(elitismPercentageTextField);

        	outputTextArea.setFocusable(false);
        	DefaultCaret caret = (DefaultCaret)outputTextArea.getCaret();
        	caret.setUpdatePolicy(DefaultCaret.ALWAYS_UPDATE);

        	JScrollPane scrollPane = new JScrollPane(outputTextArea, JScrollPane.VERTICAL_SCROLLBAR_ALWAYS, JScrollPane.HORIZONTAL_SCROLLBAR_ALWAYS);
        	panel.add(scrollPane);

        	JPanel runButtonPanel = new JPanel();
        	panel.add(runButtonPanel, BorderLayout.SOUTH);
        
        	JButton runButton = new JButton(RUN_ACTION_COMMAND);
        	runButton.addActionListener(this);
        	runButton.setActionCommand(RUN_ACTION_COMMAND);
        	runButtonPanel.add(runButton);

        	this.setResizable(false);
        	this.setPreferredSize(new Dimension(600, 600));
        	this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

        	this.pack();
        	this.setVisible(true);
    	}

    	public void println(String string)
    	{
        	outputTextArea.append("\n");
        	outputTextArea.append(string);
    	}

    	public void clear()
    	{
        	outputTextArea.setText("");
    	}

    	public void actionPerformed(ActionEvent event)
    	{
        	String actionCommand = event.getActionCommand();

        	if (actionCommand.equals(RUN_ACTION_COMMAND))
        	{
        		GeneticAlgorithm.run();
        	}
        	else if (actionCommand.equals(ELITISM_ACTION_COMMAND))
        	{
        		GeneticAlgorithm.toggleElitism();
        	}
        	else if (actionCommand.equals(SELECTION_TYPE_ACTION_COMMAND))
        	{
        		int selectionTypeTournament = SelectionType.SelectionTypeTournament.ordinal();

        		if (this.selectionTypeComboBox.getSelectedIndex() == selectionTypeTournament)
        		{
                		this.selectionPanel.add(this.tournamentSizePanel);
                		this.selectionPanel.revalidate();
        		}
        		else {
                		this.selectionPanel.remove(this.tournamentSizePanel);
                		this.selectionPanel.revalidate();
        		}
        	}
    	}
}
