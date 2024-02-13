public class Triangle extends Shapes {
    double area(double a, double b, double c){
        double s = (a+b+c)/2;
        double Area = Math.sqrt(s*(s-a)*(s-b)*(s-c));
        return Area;
    }
}
