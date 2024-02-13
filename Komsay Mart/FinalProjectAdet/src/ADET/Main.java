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
       /* primaryStage.initStyle(StageStyle.UNDECORATED);


            //Lambda expression is a short block of code which takes in parameters and returns a value
            // para ma move natin yung borderless window
        root.setOnMousePressed(event ->{
                x = event.getSceneX();
                y = event.getSceneY();
                });
        root.setOnMouseDragged(event ->{
                primaryStage.setX(event.getSceneX()-x);
                primaryStage.setY(event.getSceneY()-y);
                });*/
        primaryStage.setScene(new Scene(root, 1200, 700));
        primaryStage.show();
        guiStage=primaryStage;
    }


    public static void main(String[] args) {
        launch(args);
    }
}
