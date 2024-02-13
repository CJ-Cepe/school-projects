/*
Cepe,Carl Joseph R.                         11/19/2020
BSCS 3-4
COMP 20133 Applications Development and Emerging Technologies
IDE: intelliJ IDEA

Module 2 activity/assessment                Armstrong number

1. Write a java program to check whether the given number is armstrong number or
not.Armstrong Number in Java: A positive number is called armstrong number if it is equal to
the sum of cubes of its digits for example 0, 1, 153, 370, 371, 407 etc.
*/

import java.util.Scanner;
public class ArmstrongNumber {

    public static void main(String[] args) {
        System.out.println("*only accepts integer");
        Scanner scanner = new Scanner(System.in);
        char Again = 'Y';

        while(Character.toUpperCase(Again) == 'Y'){
            System.out.print("Input Number to test: ");          // ask for input

            long inputNumber = scanner.nextLong();               // holds the number to test
            int length = String.valueOf(inputNumber).length();   // converts the number to string to count its length
            long temp = inputNumber, sum = 0, currentNumber;     // other variables to use

            while (inputNumber > 0) {
                currentNumber = inputNumber % 10;
                sum = sum + (long) (Math.pow(currentNumber, length));
                inputNumber = inputNumber / 10;
            }

            if (sum == temp) {
                System.out.println(temp + " is an Armstrong Number");
            } else {
                System.out.println(temp + " is not an Armstrong Number");
            }
            System.out.print("Again(Y/N)?: ");
            Again = scanner.next().charAt(0);
            System.out.println("--------------------------------------------");
        }
       scanner.close();
    }
}
