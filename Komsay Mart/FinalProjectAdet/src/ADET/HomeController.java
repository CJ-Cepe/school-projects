package ADET;

import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.fxml.FXMLLoader;
import javafx.fxml.Initializable;
import javafx.scene.Parent;
import javafx.scene.Scene;
import javafx.scene.control.Button;
import javafx.stage.Stage;

import java.net.URL;
import java.util.ResourceBundle;

public class HomeController extends Main implements Initializable {

    @FXML
    private Button itemButton;

    @FXML
    private Button reportButton;

    @FXML
    private Button transactionButton;

    @FXML
    private Button exchangeButton;

    @FXML
    private Button refundButton;

    @FXML
    void itemButtonClick(ActionEvent event){
        Functions function = new Functions();
        function.changeScene("ItemPage");
        function.changeTitle("Items");
    }//itemButtonClick

    @FXML
    void refundButtonAction(ActionEvent event){
       Functions function = new Functions();
       function.changeScene("Refund");
       function.changeTitle("Refund");
    }//RefundButtonAction



    @Override
    public void initialize(URL url, ResourceBundle resourceBundle) {

    }
}
