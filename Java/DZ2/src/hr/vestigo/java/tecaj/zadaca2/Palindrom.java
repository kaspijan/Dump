package hr.vestigo.java.tecaj.zadaca2;

import java.lang.Math;


/**
 * Class which finds palindroms.
 * Class contains a main method which finds and prints the palindroms.
 * Class was written as a solution to Task 3 of Homework 2 of Vestigo Java Course.
 * 
 * @author Šimun Šopar
 *
 */

public class Palindrom {
	
	/**
	 * The main method of the class.
	 * The method has a given string array from which it will find the palindroms, ignoring character cases and whitespaces. 
	 * The method prints the palindroms. If the palindrom's length is even, the palindrom will be printed as upper case, else it will be printed as it is in the initial array.
	 * @param args
	 * 			The args argument of the main method, does not expect any input to be given.
	 */
	
	public static void main(String[] args) {
		String[] Input = {"Bob", "civic", "Time", "rAdar", "lol", "DotA", "dEtarTrated", "sAiPpuaKivikauPPias", "rotoR", "solo", "kite",
				"Rick", "Evee", "discipline", "_wow_", "sTat"};
		
		String[] palindroms = new String[Input.length];
		
		boolean isPal = true;
		short palIndex = 0;
		
		for(int i = 0; i < Input.length; i++) {
			
			isPal = true;
			String s = Input[i];
			s = s.toLowerCase();
			s = s.replace(" ", "");
			
			for(int j = 0; j < (int)( Math.ceil(s.length() / 2) ); j++) {
				if(s.charAt(j) != s.charAt(s.length() - 1 - j)) {isPal = false; break;}
			}
			
			if(isPal == true) {
				if(s.length() % 2 == 0) palindroms[palIndex] = Input[i].toUpperCase();
				else palindroms[palIndex] = Input[i];
				palIndex++;
			}
				
		}
		
		for(int i = 0; i < palindroms.length; i++) {
			if(palindroms[i] == null) break;
			System.out.println(palindroms[i]);
		}
	}
	
}
