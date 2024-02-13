package ADET;

import ADET.Main;
import javafx.fxml.FXMLLoader;
import javafx.scene.Parent;
import javafx.scene.Scene;

public class Functions {

    private static double x,y = 0;
    public void changeScene(String SceneName){
       try{
           FXMLLoader itemPageLoader = new FXMLLoader(getClass().getResource(SceneName +".fxml"));
           Parent root = (Parent) itemPageLoader.load();
           Main.getStage().setScene(new Scene(root));      //change scene
           Main.getStage().setTitle(SceneName);


           //Lambda expression is a short block of code which takes in parameters and returns a value
           // para ma move natin yung borderless window
           root.setOnMousePressed(e -> {
               x = Main.getStage().getX() - e.getScreenX();
               y = Main.getStage().getY() - e.getScreenY();
           });
           root.setOnMouseDragged(e -> {
               Main.getStage().setX(e.getScreenX() + x);
               Main.getStage().setY(e.getScreenY() + y);
               Main.getStage().setOpacity(0.8f);                    //para sa opacity pag na drag yung app
           });
           root.setOnDragDone(e -> {
               Main.getStage().setOpacity(1.0f);
           });
           root.setOnMouseReleased(e ->{
               Main.getStage().setOpacity(1.0f);
           });

       }catch(java.io.IOException exception){
           System.out.println("Cant load window");
           exception.printStackTrace();
       }//try catch
   }

   public  void changeTitle(String title){
        Main.getStage().setTitle(title);            //change title
   }
}
