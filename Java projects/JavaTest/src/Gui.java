import javax.swing.*;
import java.awt.*;      //BorderLayout.North/South/etc

public class Gui {
    public static void main(String[] args){
        JFrame frame = new JFrame("GUI");
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setSize(300,300);

        JMenuBar menuBar = new JMenuBar();
        JMenu menuFile = new JMenu("File");
        JMenu menuHelp = new JMenu("Help");
        JMenuItem menuItemOpen = new JMenuItem("Open");
        JMenuItem menuItemSaveAs = new JMenuItem("Save As");

        menuFile.add(menuItemOpen);
        menuFile.add(menuItemSaveAs);
        menuBar.add(menuFile);
        menuBar.add(menuHelp);


        JPanel panelSouth = new JPanel();
        JLabel labelEnterText = new JLabel("Enter Text");
        JTextField textField = new JTextField(10);
        JButton buttonSend = new JButton("Send");
        JButton buttonReset = new JButton("Reset");

        panelSouth.add(labelEnterText);
        panelSouth.add(textField);
        panelSouth.add(buttonSend);
        panelSouth.add(buttonReset);

        JTextArea textAreaCenter = new JTextArea();

        frame.getContentPane().add(BorderLayout.NORTH, menuBar);
        frame.getContentPane().add(BorderLayout.CENTER, textAreaCenter);
        frame.getContentPane().add(BorderLayout.SOUTH, panelSouth);




/*      JButton button1 = new JButton("Press 1");
        JButton button2 = new JButton("Press 2");
        frame.getContentPane().add(button1);
        frame.add(button2);*/

        frame.setVisible(true);


/*
        LAYOUT MANAGER:  arrange java gui components inside a container

            BorderLayout: default for contentPane (frame, applets, dialogs)
                BoxLayout
                CardLayout
            FlowLayout: default for every JPanel. layout components in a single row
            GridBagLayout: placing components within a grid. allowing to span more than one cell
                GridLayout grid with equal size
                GroupLayout
                SpringLayout specify precise relationship

        Event: change in the state of an object
               generated as a result of user interaction with the graphical user interface components.

               TYPES OF EVENTS
                Foreground events: direct interaction of the user. Consequences
                                    clicking on a button, moving the mouse, entering
                                    a character through keyboard, selecting an item from list,
                                    scrolling the page, etc.
                Background events: require interaction of the end user.
                                    Operating system interrupts, hardware or software failure,
                                    timer expiration, and operation completion are some examples
                                    of background events.

         Event Handling: mechanism that controls the event and decides what should happen if an event occurs
            Event handler: executed when an event occurs
            Delegation Event Model: This model defines the standard mechanism to generate and handle the events
                    KEY PARTICIPANTS
                        Source: The source is an object on which the event occurs.
                                responsible for providing information of the occurred
                                    event to it's handler.
                        Listener: Also known as the Event Handler
                                  responsible for generating a response to a event
                                  needs to be registered with the source object
                                  so that the listener can receive the vent notification

            The benefit of this approach is that the user interface logic is completely separated
            from the logic that generates the event.

      Steps Involved in Event Handling
Step 1 − The user clicks the button and the event is generated.
Step 2 − The object of concerned event class is created automatically and information about the
            source and the event get populated within the same object.
Step 3 − Event object is forwarded to the method of the registered listener class.
Step 4 − The method is gets executed and returns.

      Points to Remember About the Listener
 In order to design a listener class, you have to develop some listener interfaces. These
    Listener interfaces forecast some public abstract callback methods, which must be
    implemented by the listener class.
 If you do not implement any of the predefined interfaces, then your class cannot act as a
    listener class for a source object.

         Callback Methods: callback methods represent an event method.
                           In response to an event, java jre will fire callback method.

setActionCommand()

This method changes the action command string, but does not affect the string used to label the button.

getActionCommand()

The action command identifies the button. Thus, when using two or more buttons within the same
application, the action command gives you an easy way to determine which button was pressed.


*/



    }
}
