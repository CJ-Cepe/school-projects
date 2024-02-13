/*
Cepe,Carl Joseph R.                         12/17/2020
BSCS 3-4
COMP 20133 Applications Development and Emerging Technologies
IDE: intelliJ IDEA

Module 3 activity/assessment                Shapes Area
*/
import java.util.Scanner;
public class Main {
    public static void main(String[] args) {
        char ans; Scanner scanner = new Scanner(System.in);
do {
    int choice; double temp1, temp2, temp3;
    System.out.print("-------------------------\n" +
            "Pick a shape to compute\n" +
            "-------------------------\n" +
            "Rectangle :      1       \n" +
            "Square    :      2       \n" +
            "Circle    :      3       \n" +
            "Triangle  :      4       \n" +
            "=========================\n" +
            " Enter choice(number): ");
    choice = scanner.nextInt();
    switch (choice) {
        case 1 -> {
            System.out.print("\nEnter Length: ");
            temp1 = scanner.nextDouble();
            System.out.print("Enter Breadth: ");
            temp2 = scanner.nextDouble();
            Quadrilateral rectangle = new Quadrilateral();
            System.out.println("Area of Rectangle: "+rectangle.area(temp1,temp2));
        }
        case 2 -> {
            System.out.print("\nEnter Edge: ");
            temp1 = scanner.nextDouble();
            Quadrilateral square = new Quadrilateral();
            System.out.println("Area of Square: "+square.area(temp1,temp1));
        }
        case 3 -> {
            System.out.print("\nEnter Radius :");
            temp1 = scanner.nextDouble();
            Circle circle = new Circle();
            System.out.println("Area of Circle: "+circle.area(temp1));
        }
        case 4 -> {
            System.out.print("\nEnter side 1 :");
            temp1 = scanner.nextDouble();
            System.out.print("Enter side 2 :");
            temp2 = scanner.nextDouble();
            System.out.print("Enter side 3 :");
            temp3 = scanner.nextDouble();
            Triangle triangle = new Triangle();
            System.out.println("Area of Triangle: "+triangle.area(temp1, temp2, temp3));
        }
        default -> System.out.println("Invalid input");
    }//switch
    System.out.print("Try Again(Y)? : ");
    ans = scanner.next().charAt(0);
}while(Character.toUpperCase(ans)=='Y');
        System.out.println("\n Bye thank you :)");
    }//main
}//class
