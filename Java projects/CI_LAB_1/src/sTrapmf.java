public class sTrapmf {
    public double input;
    public double mf;
    private double sTrapm_offset;
    private double sTrapm_slope;
    private double sTrapm_pt1;
    private double sTrapm_pt2;

    public sTrapmf(){                               //pwede na nating alisin
    }
    public void finalize() throws Throwable {
    }

    //==============================GETTERS===================================================
    public double getMf() {
        if(input < sTrapm_pt1)
        {
            mf=0;
        }
        else if(input >= sTrapm_pt2)
        {
            mf=1;
        }
        else if((input >= sTrapm_pt1) && (input < sTrapm_pt2))
        {
            mf=sTrapm_slope * input + sTrapm_offset;
        }
        return mf;
    }

    public double getInput() {
        return input;
    }

    //---Getters Points------------------
    public double getsTrapm_pt1() {
        return sTrapm_pt1;
    }

    public double getsTrapm_pt2() {
        return sTrapm_pt2;
    }

    //---Getters Offset and Slope---------
    public double getsTrapm_offset() {
        return sTrapm_offset;
    }

    public double getsTrapm_slope() {
        return sTrapm_slope;
    }

    //==============================SETTERS===================================================

    public void setInput(double input) {
        this.input = input;
    }

    //---Setters Points------------------
    public void setsTrapm_pt1(double sTrapm_pt1) {
        this.sTrapm_pt1 = sTrapm_pt1;
    }

    public void setsTrapm_pt2(double sTrapm_pt2) {
        this.sTrapm_pt2 = sTrapm_pt2;
    }

    //---Setters Offset and Slope--------
    public void setsTrapm_offset(double sTrapm_offset) {
        this.sTrapm_offset = sTrapm_offset;
    }

    public void setsTrapm_slope(double sTrapm_slope) {
        this.sTrapm_slope = sTrapm_slope;
    }

}//sTrapmf Class
