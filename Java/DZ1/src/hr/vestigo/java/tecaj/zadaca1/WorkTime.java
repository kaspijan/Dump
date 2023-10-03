package hr.vestigo.java.tecaj.zadaca1;

import java.util.Scanner;
import java.io.IOException;
import java.util.Arrays;

/**
 * Class for determining whether the shop is closed in a given time.
 * The class containts a method which determines whether the shop is closed or open.
 * Class was written as a solution to Task 5 of Homework 1 of Vestigo Java Course.
 * 
 * @author Šimun
 */

public class WorkTime {
	
	/**
	 * The main method of the class.
	 * The method takes input through Scanner object, the hour and day of interest. 
	 * The method then prints true if the ship is open, false if not.
	 * @param args
	 * 			The args argument of the main method, does not expect any input to be given.
	 * @throws IOException
	 * 			If the I/O error occurs.
	 */
	
	public static void main(String[] args) throws IOException{
		
		Scanner sc = new Scanner(System.in);
		
		System.out.println("Please enter an hour:");
		int hour = sc.nextInt();
		
		System.out.println("Please enter a day:");
		String day = sc.next();
		day = day.toLowerCase();
		
		String workdays[] = {"monday","tuesday","wednesday","thursday","friday"};
		
		
		System.out.println("On a given day and time store is open: " + (Arrays.asList(workdays).contains(day) && hour >= 8 && hour <= 16) );
		sc.close();
	}
}
