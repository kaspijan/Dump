package hr.vestigo.java.tecaj.zadaca2;

import java.util.ArrayList;

/**
 * Class for finding characters present in word 'EDUKACIJA' in a character matrix.
 * Class contains a method which finds the corresponding characters.
 * Class was written as a solution to Task 4 of Homework 2 of Vestigo Java Course.
 * 
 * @author Šimun Šopar
 *
 */

public class Education {
	
	/**
	 * The main method of the class.
	 * The method has a given array of character arrays. The method parses through the array and checks if the elements can be found inside the work 'EDUKACIJA'.
	 * The method then prints the corresponding characters.
	 * @param args
	 * 			The args argument of the main method, does not expect any input to be given.
	 */
	
	public static void main(String[] args) {
		String keyWord = "EDUKACIJA";
		
		char[][] charMatrix = {{'K', 'A', '5', 'V', 'S', '1', 'Z'}, {'D', 'A', '3', 'E', 'L'}, {'A', 'W', 'S', 'C', '6'},
				{'O', 'T', '9'}, {'Y', 'Z', '1', 'I', 'S'}, {'4', 'R', 'T', 'G', 'S'}, {'A', 'B', '0', 'I', 'S'}};
		
		ArrayList<Character> Output = new ArrayList<Character>();
		
		for(int i = 0; i < charMatrix.length; i++) {
			for(int j = 0; j < charMatrix[i].length; j++) {
				if(keyWord.indexOf(charMatrix[i][j]) != -1) Output.add(charMatrix[i][j]); 
			}
		}
		
		System.out.println(Output);
		
	}
}
