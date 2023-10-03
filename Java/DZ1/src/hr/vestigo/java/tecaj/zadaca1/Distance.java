package hr.vestigo.java.tecaj.zadaca1;

import java.util.Scanner;
import java.io.IOException;

/**
 * Class for calculating the distance between two 2d points.
 * The class containts a method which calculates the distance between two 2d points.
 * Class was written as a solution to Task 4 of Homework 1 of Vestigo Java Course.
 * 
 * @author Šimun
 */

public class Distance {
	
	/**
	 * The main method of the class.
	 * The method takes input through Scanner object, the coordinates of the points. 
	 * The method then prints the distance between the points.
	 * @param args
	 * 			The args argument of the main method, does not expect any input to be given.
	 * @throws IOException
	 * 			If the I/O error occurs.
	 */
	
	public static void main(String[] args) throws IOException{
		Scanner sc = new Scanner(System.in);
		
		float coordinates[] = new float[4];
		String words[] = {"x", "y", "first", "second"};
		
		for(int i = 0; i < 4; i++) {
			System.out.println("Enter " + words[i % 2] + " coordinate of the " + words[2 + i/2] + " number:");
			coordinates[i] = sc.nextFloat();
		}
		
		double distance = Math.sqrt(Math.pow(coordinates[0] - coordinates[2], 2) + Math.pow(coordinates[1] - coordinates[3], 2));
		System.out.println("Distance between two points is: " + distance);
		
		sc.close();
		
	}
}
