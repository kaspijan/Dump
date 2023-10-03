package hr.vestigo.java.tecaj.zadaca2;

import java.util.Random;
import java.util.Arrays;


/**
 * Class for dividing an array into three sub-arrays.
 * Class contains a method which divides an array into subarrays and, if necessary, sorts the subarrays.
 * Class was written as a solution to Task 1 of Homework 1 of Vestigo Java Course
 * 
 * @author Šimun Šopar
 *
 */

public class Subarray {
	
	/**
	 * The main method of the class.
	 * The method has a given integer array which it will split into three subarrays of random sizes. 
	 * The method will then sort the subarray if its length is even and then it will print the subarrays.
	 * @param args
	 * 			The args argument of the main method, does not expect any input to be given.
	 */
	
	public static void main(String[] args) {
		int Input[] = {9, 8, 937, 912, 1961, 24, 7, 61, 7285, 17, 826, 175, 8123, 4373, 3, 92, 99, 897, 32, 50, 1, 67, 24};
		
		Random rand = new Random();
		int size1 = 1 + rand.nextInt((int)((Input.length - 4) / 2));
		int size2 = 1 + rand.nextInt((int)((Input.length - 4) / 2));
		size2 += size1;
		
		int[] Output1 = Arrays.copyOfRange(Input, 0, size1);
		int[] Output2 = Arrays.copyOfRange(Input, size1, size2);
		int[] Output3 = Arrays.copyOfRange(Input, size2, Input.length);
		
		if(Output1.length % 2 == 0) Arrays.sort(Output1);
		if(Output2.length % 2 == 0) Arrays.sort(Output2);
		if(Output3.length % 2 == 0) Arrays.sort(Output3);
		
		for(int i = 0; i < Output1.length; i++) System.out.print(Output1[i] + " ");
		System.out.println();
		
		for(int i = 0; i < Output2.length; i++) System.out.print(Output2[i] + " ");
		System.out.println();
		
		for(int i = 0; i < Output3.length; i++) System.out.print(Output3[i] + " ");
		System.out.println();
	}
}
