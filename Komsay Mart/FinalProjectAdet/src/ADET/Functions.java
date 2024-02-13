package ADET;

import javafx.fxml.FXMLLoader;
import javafx.scene.Parent;
import javafx.scene.Scene;

public class Functions {
    public void changeScene(String SceneName){
       try{
           FXMLLoader itemPageLoader = new FXMLLoader(getClass().getResource(SceneName +".fxml"));
           Parent root = (Parent) itemPageLoader.load();
           Main.getStage().setScene(new Scene(root));      //change scene
           Main.getStage().setTitle(SceneName);

       }catch(java.io.IOException exception){
           System.out.println("Cant load window");
           exception.printStackTrace();
       }//try catch
   }

   public  void changeTitle(String title){
        Main.getStage().setTitle(title);            //change title
   }
}
