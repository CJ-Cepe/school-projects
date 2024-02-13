package ADET.Controller;

import ADET.Functions;
import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.scene.control.Button;

public class ItemPageController {

        @FXML
        private Button addButton;

        @FXML
        private Button searchButton;

        @FXML
        private Button editButton;

        @FXML
        void addButtonAction(ActionEvent event){
                Functions function = new Functions();
                function.changeScene("AddNewItems");
                function.changeTitle(" Add Items");
        }//addButtonAction
        @FXML
        void editButtonAction(ActionEvent event){
                Functions function = new Functions();
                function.changeScene("EditItems");
                function.changeTitle(" Edit Items");
        }
        @FXML
        void searchButtonAction(ActionEvent event){
                Functions function = new Functions();
                function.changeScene("SearchItems");
                function.changeTitle(" Search Items");
        }

}//class end
