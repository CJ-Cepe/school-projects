public class trapmf {

    public double input;
    public double mf;
    private double trapm_offset;
    private double trapm_slope;
    private double trapm_pt1;
    private double trapm_pt2;

    public trapmf(){
    }
    public void finalize() throws Throwable {
    }

    //==============================GETTERS===================================================

        public double getMf() {
            if(input < trapm_pt1)
            {
                mf=1;
            }
            else if(input >= trapm_pt2)
            {
                mf=0;
            }
            else if((input >= trapm_pt1) && (input < trapm_pt2))
            {
                mf=trapm_slope * input + trapm_offset;
            }
            return mf;
        }

    public double getInput() {
        return input;
    }

    //---Getters Points------------------
    public double getTrapm_pt1() {
        return trapm_pt1;
    }

    public double getTrapm_pt2() {
        return trapm_pt2;
    }

    //---Getters Offset and Slope---------
    public double getTrapm_offset() {
        return trapm_offset;
    }

    public double getTrapm_slope() {
        return trapm_slope;
    }


    //==============================SETTERS===================================================

    public void setInput(double input) {
        this.input = input;
    }

    //---Setters Points------------------
    public void setTrapm_pt1(double trapm_pt1) {
        this.trapm_pt1 = trapm_pt1;
    }

    public void setTrapm_pt2(double trapm_pt2) {
        this.trapm_pt2 = trapm_pt2;
    }

    //---Setters Offset and Slope---------
    public void setTrapm_offset(double trapm_offset) {
        this.trapm_offset = trapm_offset;
    }

    public void setTrapm_slope(double trapm_slope) {
        this.trapm_slope = trapm_slope;
    }

}//trapmf Class
