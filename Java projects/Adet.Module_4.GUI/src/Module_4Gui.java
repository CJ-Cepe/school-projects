/*
Cepe,Carl Joseph R.                         1/24/2021
BSCS 3-4
COMP 20133 Applications Development and Emerging Technologies
IDE: intelliJ IDEA

Module 4 activity/assessment                java GUI program

1. Create a java GUI program (with container and components) that will generate
the layout below with proper functionality.
*/
import javax.swing.*;
import java.awt.*;

public class Module_4Gui {
    public static void main(String[] args) {

        //FRAME
        JFrame mainFrame = new JFrame("Database Application Example");
        mainFrame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        mainFrame.setSize(600,350);
        //MENUBAR
        JMenuBar menuBar = new JMenuBar();
        JMenu file = new JMenu("File");
        JMenu help = new JMenu("Help");
        menuBar.add(file);
        menuBar.add(help);
        JMenuItem open = new JMenuItem("Open");
        JMenuItem saveAs = new JMenuItem("Save As");
        file.add(open);
        file.add(saveAs);
        //PANEL
        JPanel mainPanel = new JPanel(new BorderLayout());
        JPanel panel1 = new JPanel(new FlowLayout());
        JPanel panel2 = new JPanel(new GridBagLayout());
        GridBagConstraints gbc = new GridBagConstraints();
            //BUTTON
        JButton newButton = new JButton("New");
        JButton deleteButton = new JButton("Delete");
        JButton refreshButton = new JButton("Refresh");
        JButton saveButton = new JButton("Save");
        saveButton.setEnabled(false);
            //LABEL
        JLabel label1 = new JLabel("Student Id:");
        JLabel label2 = new JLabel("Stud First Name:");
        JLabel label3 = new JLabel("Stud Last Name:");
        JLabel label4 = new JLabel("Stud Date Of Birth:");
        JLabel label5 = new JLabel("Stud Address:");
        JLabel label6 = new JLabel("Stud Program:");
        JLabel label7 = new JLabel("Stud Marital Status:");
        JLabel label8 = new JLabel("Stud Country:");
            //TEXTFIELD
        JTextField tf1 = new JTextField(40);
        JTextField tf2 = new JTextField(40);
        JTextField tf3 = new JTextField(40);
        JTextField tf4 = new JTextField(40);
        JTextField tf5 = new JTextField(40);
        JTextField tf6 = new JTextField(40);
        JTextField tf7 = new JTextField(40);
        JTextField tf8 = new JTextField(40);

        panel1.add(newButton);
        panel1.add(deleteButton);
        panel1.add(refreshButton);
        panel1.add(saveButton);

        gbc.insets = new Insets(5,5,5,5);
        gbc.anchor = GridBagConstraints.FIRST_LINE_START;
        gbc.weightx =0.1; gbc.weighty = 0.1;
        gbc.fill = GridBagConstraints.HORIZONTAL;
        gbc.gridy = 0;
        gbc.gridx = 0;
        panel2.add(label1,gbc);
        gbc.gridy=GridBagConstraints.RELATIVE;
        panel2.add(label2,gbc);
        panel2.add(label3,gbc);
        panel2.add(label4,gbc);
        panel2.add(label5,gbc);
        panel2.add(label6,gbc);
        panel2.add(label7,gbc);
        panel2.add(label8,gbc);
        gbc.gridy = 0;
        gbc.gridx =GridBagConstraints.RELATIVE;
        panel2.add(tf1,gbc);
        gbc.gridy=1;
        panel2.add(tf2,gbc);
        gbc.gridy=2;
        panel2.add(tf3,gbc);
        gbc.gridy=3;
        panel2.add(tf4,gbc);
        gbc.gridy=4;
        panel2.add(tf5,gbc);
        gbc.gridy=5;
        panel2.add(tf6,gbc);
        gbc.gridy=6;
        panel2.add(tf7,gbc);
        gbc.gridy=7;
        panel2.add(tf8,gbc);

        mainPanel.add(panel1,BorderLayout.NORTH);
        mainPanel.add(panel2,BorderLayout.CENTER);
        mainFrame.add(menuBar,BorderLayout.NORTH);
        mainFrame.add(mainPanel,BorderLayout.CENTER);
        mainFrame.setVisible(true);
    }
}
