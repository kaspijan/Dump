package hr.vestigo.java.tecaj.zadaca2;

/**
 * Class for searching the longest string inside three string arrays.
 * Class contains a method which will find the longest string.
 * Class was written as a solution to Task 2 of Homework 2 of Vestigo Java Course.
 * 
 * @author Šimun Šopar
 *
 */

public class LongestString {
	
	/**
	 * The main method of the class.
	 * The method has three given String arrays. The method parses through the arrays searching for the longest string.
	 * The array containing the longest string is then printed.
	 * @param args
	 * 			The args argument of the main method, does not expect any input to be given.
	 */
	
	public static void main(String[] args) {
		
		String[] arr1 = {"Nick", "Tommy", "Jerry", "Bobby", "Ricky", "Mickey", "Tom", "Jerry", "Tom"};
		String[] arr2 = {"Hello", "World", "Java", "Vestigo", "Open", "Close", "Stop", "Building"};
		String[] arr3 = {"Alien", "Rick", "Eleven", "One", "Dustin", "David", "Mack", "Jack", "Jerry", "Mike"};
		
		String[][] arr = {arr1, arr2, arr3};
		
		int[] lengths = {0, 0, 0};
		int[] maxLen = {0, 0};
		
		for(int i = 0; i < 3; i++) {
			//System.out.println(arr[i].length);
			for(int j = 0; j < arr[i].length; j++) {
				if(arr[i][j].length() > lengths[i]) lengths[i] = arr[i][j].length();
			}
			
			if(lengths[i] > maxLen[1]) {maxLen[0] = i; maxLen[1] = lengths[i];}
		}
		
		for(int i = 0; i < arr[maxLen[0]].length; i++) {
			System.out.print(arr[maxLen[0]][i] + " ");
		}
		
		
		
	}
}
