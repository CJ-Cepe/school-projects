import java.util.Scanner;

public class Fuzzy_Engine {

    //===Temporary holders==============
    private double temp;                       //hahawak sa result nung scanner.nextDouble
    private double cover;
    //====INPUT==========================
    //TEMP
    private trapmf freezing = new trapmf();
    private trimf cool = new trimf();
    private trimf warm = new trimf();
    private sTrapmf hot = new sTrapmf();

    //COVER
    private trapmf sunny = new trapmf();
    private trimf partly = new trimf();
    private sTrapmf overcast = new sTrapmf();
    //==================================
    public Fuzzy_Engine(){                      //pwede nating alisin
    }
    public void finalize() throws Throwable {
    }

    public static void main(String[] args) {        //holy main!!!
        Fuzzy_Engine fuzzy = new Fuzzy_Engine();
        fuzzy.input();
        fuzzy.initialize();

        fuzzy.output();
        fuzzy.rules();
    }

    public void input(){
        Scanner scanner = new Scanner(System.in);
        System.out.println("====INPUT=====");
        System.out.println("Temperature (°F):");
        temp=scanner.nextDouble();
        System.out.println("Cloud Cover (%):");
        cover=scanner.nextDouble();
    }

    public void initialize(){
    //initialize Temp
       freezing.setTrapm_pt1(30);
       freezing.setTrapm_pt2(50);
       freezing.setTrapm_offset(2.5);
       freezing.setTrapm_slope(-0.05);

       cool.setTrim_pt1(30);
       cool.setTrim_pt2(50);
       cool.setTrim_pt3(70);
       cool.setTrim_up_offset(-1.5);
       cool.setTrim_up_slope(0.05);
       cool.setTrim_down_offset(3.5);
       cool.setTrim_down_slope(-0.05);

       warm.setTrim_pt1(50);
       warm.setTrim_pt2(70);
       warm.setTrim_pt3(90);
       warm.setTrim_up_offset(-2.5);
       warm.setTrim_up_slope(0.05);
       warm.setTrim_down_offset(4.5);
       warm.setTrim_down_slope(-0.05);

       hot.setsTrapm_pt1(70);
       hot.setsTrapm_pt2(90);
       hot.setsTrapm_offset(-3.5);
       hot.setsTrapm_slope(0.05);

    //initialize Cover
       sunny.setTrapm_pt1(20);
       sunny.setTrapm_pt2(40);
       sunny.setTrapm_offset(2);
       sunny.setTrapm_slope(-0.05);

       partly.setTrim_pt1(20);
       partly.setTrim_pt2(50);
       partly.setTrim_pt3(80);
       partly.setTrim_up_offset(-0.666666667);
       partly.setTrim_up_slope(0.033333333);
       partly.setTrim_down_offset(2.666666667);
       partly.setTrim_down_slope(-0.033333333);

       overcast.setsTrapm_pt1(60);
       overcast.setsTrapm_pt2(80);
       overcast.setsTrapm_offset(-3);
       overcast.setsTrapm_slope(0.05);

    //Initializing input---------
       freezing.setInput(temp);
       cool.setInput(temp);
       warm.setInput(temp);
       hot.setInput(temp);

       sunny.setInput(cover);
       partly.setInput(cover);
       overcast.setInput(cover);
    }//initialize

    public void output(){
        System.out.println("====OUTPUT====");
        System.out.println("Temp" + "\n" +
                            "Freezing = " + freezing.getMf() +"\n"+
                            "Cool =" + cool.getMf() +"\n" +
                            "Warm =" + warm.getMf() +"\n" +
                            "Hot =" + hot.getMf() +"\n"
                          );
        System.out.println("Cover" + "\n" +
                "Sunny = " + sunny.getMf() +"\n"+
                "Partly =" + partly.getMf() +"\n" +
                "Overcast =" + overcast.getMf() +"\n"
        );
    }//output

    public void rules(){
        System.out.println("====RULES====");
        if(sunny.getMf()>warm.getMf())
        {
            System.out.println("Sunny("+sunny.getMf()+") AND Warm("+warm.getMf()+") ==>" +warm.getMf() +" Fast");
        }
        else if(sunny.getMf()<warm.getMf())
        {
            System.out.println("Sunny("+sunny.getMf()+") AND Warm("+warm.getMf()+") ==>" +sunny.getMf() +" Fast");
        }
        else if(sunny.getMf()==warm.getMf())
        {
            System.out.println("Sunny("+sunny.getMf()+") AND Warm("+warm.getMf()+") ==>" +sunny.getMf() +" Fast");
        }

        if(partly.getMf()>cool.getMf())
        {
            System.out.println("Cloudy("+partly.getMf()+") AND Cool("+cool.getMf()+") ==>" +cool.getMf() +" Slow");
        }
        else if(partly.getMf()<cool.getMf())
        {
            System.out.println("Cloudy("+partly.getMf()+") AND Cool("+cool.getMf()+") ==>" +partly.getMf() +" Slow");
        }
        else if(partly.getMf()==cool.getMf())
        {
            System.out.println("Cloudy("+partly.getMf()+") AND Cool("+cool.getMf()+") ==>" +partly.getMf() +" Slow");
        }
    }
}//Fuzzy Engine class
