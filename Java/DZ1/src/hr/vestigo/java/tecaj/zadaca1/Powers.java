package hr.vestigo.java.tecaj.zadaca1;

import java.io.IOException;
import java.util.Scanner;


/**
 * Class for calculating the power of a number.
 * The class containts a method which calculates the power of a number.
 * Class was written as a solution to Task 2 of Homework 1 of Vestigo Java Course.
 * 
 * @author Šimun
 */

public class Powers {
	
	/**
	 * The main method of the class.
	 * The method takes a float input, the base which power is to be calculated, and an integer input, the exponent to which the base is raised, through Scanner object.
	 * The method then prints the base raised to the exponent as a float.
	 * @param args
	 * 			The args argument of the main method, does not expect any input to be given.
	 * @throws IOException
	 * 			If the I/O error occurs.
	 */
	
	public static void main(String[] args) throws IOException{
		
		Scanner sc = new Scanner(System.in);
		
		System.out.println("Please enter a number:");
		float base = sc.nextFloat();
		
		System.out.println("Please enter a potency:");
		int powr = sc.nextInt();
		
		System.out.println(powr + ". potency of given number is: " + (Math.pow(base, powr)));
		
		sc.close();
	}
}
