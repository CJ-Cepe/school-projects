

public class Player {
    private int playerID;
    private int age;
    private int matches;
    private String name;
    private int noWin;
    private int noLose;

    public Player(int playerID, String name, int age, int matches,int noWin, int noLose){
        this.playerID=playerID;
        this.age=age;
        this.matches=matches;
        this.name=name;
        this.noWin=noWin;
        this.noLose=noLose;
    }
    public Player(){
    }
    public void setPlayerID(int playerID) {
        this.playerID = playerID;
    }
    public void setAge(int age) {
        this.age = age;
    }
    public void setMatches(int matches) {
        this.matches = matches;
    }
    public void setName(String name){
        this.name = name;
    }
    public void setNoWin(int noWin){
        this.noWin = noWin;
    }
    public void setNoLose(int noLose) {
        this.noLose = noLose;
    }
    public int getAge() {
        return age;
    }
    public int getMatches() {
        return matches;
    }
    public int getPlayerID() {
        return playerID;
    }
    public int getNoWin() {
        return noWin;
    }
    public int getNoLose() {
        return noLose;
    }
    public String getName() {
        return name;
    }


}// class Player
