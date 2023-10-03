package hr.vestigo.java.tecaj.zadaca1;

import java.util.Scanner;
import java.io.IOException;

/**
 * Class for calculating the sum of digits of 5 digit number.
 * The class containts a method which calculates the digit sum of a five digit number.
 * Class was written as a solution to Task 3 of Homework 1 of Vestigo Java Course.
 * 
 * @author Šimun
 */

public class DigitSum {

	/**
	 * The main method of the class.
	 * The method takes input, the five digit number, through Scanner object. 
	 * The method then prints the sum of the digits.
	 * @param args
	 * 			The args argument of the main method, does not expect any input to be given.
	 * @throws IOException
	 * 			If the I/O error occurs.
	 */
	
	
	public static void main(String[] args) throws IOException{
	
		Scanner sc = new Scanner(System.in);
		
		System.out.print("Please enter a five digit number: ");
		
		String digits = sc.next();
		int sum = 0;
		
		for(int i = 0; i < 5; i++) {
			sum += (int)(digits.charAt(i) - '0');
		}
		
		sc.close();
		
		System.out.println("Sum of digits is: " + sum);
	}
}
