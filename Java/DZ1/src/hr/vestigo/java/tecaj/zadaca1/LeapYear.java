package hr.vestigo.java.tecaj.zadaca1;

import java.util.Scanner;
import java.io.IOException;


/**
 * Class for determining whether a year is leap or not.
 * The class containts a method which calculates which year is leap and which is not.
 * Class was written as a solution to Task 1 of Homework 1 of Vestigo Java Course.
 * 
 * @author Šimun
 */

public class LeapYear {
	/**
	 * The main method of the class.
	 * The method takes numerical input, a year, through Scanner object and prints true if the year is leap, and false if not.
	 * @param args
	 * 			The args argument of the main method, does not expect any input to be given.
	 * @throws IOException
	 * 			If the I/O error occurs.
	 */
	public static void main(String[] args) throws IOException{
		
		Scanner sc = new Scanner(System.in);
		
		System.out.print("Please enter a year: ");
		int year = sc.nextInt();
		
		System.out.print("Given year is leap: " + (year % 4 == 0));
		
		sc.close();
	}
}
