import java.sql.*;

public class MainClass {

    static final String DB_URL = "D:\\JAVA\\Module51.accdb";

    public static void main(String[] args) {

        try {
            Connection connect = DriverManager.getConnection(DB_URL);
            Statement stmt = connect.createStatement();
            String sql="SELECT Player.[ID], Player.[PLAYER_ID], Player.[Name], Player.[Age], Player.[Matches], Player.[Wins], Player.[Loss]\n" +
                    "FROM Player;";
            ResultSet rs=stmt.executeQuery(sql);
        }
        catch(SQLException exception){
            exception.printStackTrace();
        }





    }//main method

}//main class
