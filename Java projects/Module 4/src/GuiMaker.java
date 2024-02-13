/*
Cepe,Carl Joseph R.                         1/2/2021
BSCS 3-4
COMP 20133 Applications Development and Emerging Technologies
IDE: intelliJ IDEA

Module 4 activity/assessment                java GUI program

1. Create a java GUI program (with container and components) that will generate
the layout below with proper functionality.
*/

import javax.swing.*;
import java.awt.*;

public class GuiMaker {
    private JFrame frame;

public GuiMaker(){
    MakeGui();
}

    public static void main(String[] args){
        GuiMaker guiTest = new GuiMaker();
    }// method psvm

private void MakeGui(){

//Frame
    frame = new JFrame("Database Application Example");
    frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
    frame.setSize(600,310);


//Menu
   JMenuBar menuBar = new JMenuBar();
   JMenu fileMenu = new JMenu("File");
   JMenu helpMenu = new JMenu("Help");
   JMenuItem openMenuItem = new JMenuItem("Open");
   JMenuItem saveAsMenuItem = new JMenuItem("Save As");
    menuBar.add(fileMenu);
    menuBar.add(helpMenu);
    fileMenu.add(openMenuItem);
    fileMenu.add(saveAsMenuItem);
    frame.getContentPane().add(menuBar,BorderLayout.NORTH);


//Buttons
    JButton newButton = new JButton("New");
    JButton deleteButton = new JButton("Delete");
    JButton refreshButton = new JButton("Refresh");
    JButton saveButton = new JButton("Save");
    //panel for buttons
    JPanel panel2 = new JPanel();
    panel2.add(newButton);
    panel2.add(deleteButton);
    panel2.add(refreshButton);
    panel2.add(saveButton);
    frame.getContentPane().add(panel2,BorderLayout.CENTER);


//Labels and Text fields
    JPanel panel = new JPanel();
    panel.setLayout(new GridBagLayout());
    GridBagConstraints GBC = new GridBagConstraints();

    GBC.insets = new Insets(3,5,3,5);
    GBC.weightx=0;
    GBC.weighty=1;
    GBC.anchor = GridBagConstraints.WEST;

    JLabel label1 = new JLabel("Student Id:");
    GBC.gridy=1;
    GBC.gridx=0;
    panel.add(label1,GBC);
    JLabel label2 = new JLabel("Stud First Name:");
    GBC.gridy=2;
    GBC.gridx=0;
    panel.add(label2,GBC);
    JLabel label3 = new JLabel("Stud Last Name:");
    GBC.gridy=3;
    GBC.gridx=0;
    panel.add(label3,GBC);
    JLabel label4 = new JLabel("Stud Date Of Birth:");
    GBC.gridy=4;
    GBC.gridx=0;
    panel.add(label4,GBC);
    JLabel label5 = new JLabel("Stud Address:");
    GBC.gridy=5;
    GBC.gridx=0;
    panel.add(label5,GBC);
    JLabel label6 = new JLabel("Stud Program:");
    GBC.gridy=6;
    GBC.gridx=0;
    panel.add(label6,GBC);
    JLabel label7 = new JLabel("Stud Marital Status:");
    GBC.gridy=7;
    GBC.gridx=0;
    panel.add(label7,GBC);
    JLabel label8 = new JLabel("Stud Country");
    GBC.gridy=8;
    GBC.gridx=0;
    panel.add(label8,GBC);

    GBC.weightx=1;
    GBC.fill = GridBagConstraints.HORIZONTAL;

    JTextField tf1 = new JTextField(15);
    GBC.gridy=1;
    GBC.gridx=1;
    panel.add(tf1,GBC);
    JTextField tf2 = new JTextField(15);
    GBC.gridy=2;
    GBC.gridx=1;
    panel.add(tf2,GBC);
    JTextField tf3 = new JTextField(15);
    GBC.gridy=3;
    GBC.gridx=1;
    panel.add(tf3,GBC);
    JTextField tf4 = new JTextField(15);
    GBC.gridy=4;
    GBC.gridx=1;
    panel.add(tf4,GBC);
    JTextField tf5 = new JTextField(15);
    GBC.gridy=5;
    GBC.gridx=1;
    panel.add(tf5,GBC);
    JTextField tf6 = new JTextField(15);
    GBC.gridy=6;
    GBC.gridx=1;
    panel.add(tf6,GBC);
    JTextField tf7 = new JTextField(15);
    GBC.gridy=7;
    GBC.gridx=1;
    panel.add(tf7,GBC);
    JTextField tf8 = new JTextField(15);
    GBC.gridy=8;
    GBC.gridx=1;
    panel.add(tf8,GBC);

    frame.getContentPane().add(panel,BorderLayout.SOUTH);
    frame.setVisible(true); //frame setting as visible
}//method MakerGui
}//class GuiMaker
