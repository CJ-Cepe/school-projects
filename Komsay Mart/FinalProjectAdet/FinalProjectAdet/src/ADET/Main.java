package ADET;

import javafx.application.Application;
import javafx.fxml.FXMLLoader;
import javafx.scene.Parent;
import javafx.scene.Scene;
import javafx.stage.Stage;
import javafx.stage.StageStyle;

public class Main extends Application {

    private static Stage guiStage;

    public static Stage getStage(){
        return guiStage;
    }

    private static double x,y = 0;

    @Override
    public void start(Stage primaryStage) throws Exception{
        Parent root = FXMLLoader.load(getClass().getResource("Home.fxml"));
        primaryStage.setTitle("Home");
        primaryStage.initStyle(StageStyle.UNDECORATED);

        //Lambda expression is a short block of code which takes in parameters and returns a value
        // para ma move natin yung borderless window
       root.setOnMousePressed(e -> {
            x = primaryStage.getX() - e.getScreenX();
            y = primaryStage.getY() - e.getScreenY();
        });
        root.setOnMouseDragged(e -> {
            primaryStage.setX(e.getScreenX() + x);
            primaryStage.setY(e.getScreenY() + y);
            primaryStage.setOpacity(0.8f);              //para sa opacity pag na drag yung app
        });
        root.setOnDragDone(e -> {
            primaryStage.setOpacity(1.0f);
        });
        root.setOnMouseReleased(e ->{
            primaryStage.setOpacity(1.0f);
        });

        primaryStage.setScene(new Scene(root, 1200, 700));
        primaryStage.show();

        guiStage=primaryStage;
    }


    public static void main(String[] args) {
        launch(args);
    }
}
