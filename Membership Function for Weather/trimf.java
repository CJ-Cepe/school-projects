public class trimf {

    public double input;
    public double mf;
    private double trim_down_offset;
    private double trim_down_slope;
    private double trim_pt1;
    private double trim_pt2;
    private double trim_pt3;
    private double trim_up_offset;
    private double trim_up_slope;

    public trimf(){
    }
    public void finalize() throws Throwable {
    }

   //==============================GETTERS===================================================

        public double getMf(){
            if((input < trim_pt1) || (input >= trim_pt3))
            {
                mf =0;
            }
            else if ((input >= trim_pt1) && (input < trim_pt2))
            {
                mf= trim_up_slope * input + trim_up_offset;
            }
            else if ((input >= trim_pt2) && (input < trim_pt3))
            {
                mf= trim_down_slope * input + trim_down_offset;
            }
            return mf;
        }

    public double getInput(){
        return input;
    }

    //---Getters Points------------------
    public double getTrim_pt1() {
        return trim_pt1;
    }

    public double getTrim_pt2() {
        return trim_pt2;
    }

    public double getTrim_pt3() {
        return trim_pt3;
    }

    //---Getters Offset and Slope---------

    public double getTrim_up_offset() {
        return trim_up_offset;
    }

    public double getTrim_up_slope() {
        return trim_up_slope;
    }

    public double getTrim_down_offset() {
        return trim_down_offset;
    }

    public double getTrim_down_slope() {
        return trim_down_slope;
    }

    //==============================SETTERS===================================================

    public void setInput(double input){
        this.input = input;
    }

    //---Setters Points------------------
    public void setTrim_pt1(double trim_pt1) {
        this.trim_pt1 = trim_pt1;
    }

    public void setTrim_pt2(double trim_pt2) {
        this.trim_pt2 = trim_pt2;
    }

    public void setTrim_pt3(double trim_pt3) {
        this.trim_pt3 = trim_pt3;
    }

    //---Setters Offset and Slope--------
    public void setTrim_up_offset(double trim_up_offset) {
        this.trim_up_offset = trim_up_offset;
    }

    public void setTrim_up_slope(double trim_up_slope) {
        this.trim_up_slope = trim_up_slope;
    }

    public void setTrim_down_offset(double trim_down_offset) {
        this.trim_down_offset = trim_down_offset;
    }

    public void setTrim_down_slope(double trim_down_slope) {
        this.trim_down_slope = trim_down_slope;
    }
}//trimf Class
