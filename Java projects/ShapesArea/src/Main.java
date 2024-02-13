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
        char ans;
do {
    int choice;
    Scanner scanner = new Scanner(System.in);
    Scanner scanner2 = new Scanner(System.in);
    Scanner scanner3 = new Scanner(System.in);
    double temp1, temp2, temp3, AreaValue ;

    System.out.print("Shapes\n Rectangle: 1\n Square: 2\n Circle: 3\n Triangle: 4\n");
    System.out.print("enter your choice :");
    choice = scanner.nextInt();

    switch (choice) {
        case 1:
            System.out.print("Enter length :");
            temp1 = scanner2.nextDouble();
            System.out.print("Enter breadth :");
            temp2 = scanner2.nextDouble();
            Rectangle rectangle = new Rectangle();
            AreaValue = rectangle.area(temp1, temp2);
            System.out.println("Area of rectangle is :" + AreaValue);
            break;
        case 2:
            System.out.print("Enter edge :");
            temp1 = scanner2.nextDouble();
            Square square = new Square();
            AreaValue = square.area(temp1);
            System.out.println("Area of Square is :" + AreaValue);
            break;
        case 3:
            System.out.print("Enter radius :");
            temp1 = scanner2.nextDouble();
            Circle circle = new Circle();
            AreaValue = circle.area(temp1);
            System.out.println("Area of circle is :" + AreaValue);
            break;
        case 4:
            System.out.print("Enter side 1 :");
            temp1 = scanner2.nextDouble();
            System.out.print("Enter side 2 :");
            temp2 = scanner2.nextDouble();
            System.out.print("Enter side 3 :");
            temp3 = scanner2.nextDouble();
            Triangle triangle = new Triangle();
            AreaValue = triangle.area(temp1, temp2, temp3);
            System.out.println("Area of Triangle is :" + AreaValue);
            break;
        default:
            System.out.println("invalid input");
    }
    System.out.print("Again (Y) :");
    ans=scanner3.next().charAt(0);
    System.out.println("-----------------------------------------------");

        }while(Character.toUpperCase(ans)=='Y');

        System.out.println("Thank you :)");
    }
}


