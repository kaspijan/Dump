package hr.vestigo.java.tecaj.zadaca2;

/**
 * Class which calculates the sum of first 30 even natural numbers and determines which of those numbers ends in 4.
 * Class contains method main which runs this calculation.
 * Class was written as solution to Task 5 of Homework 2 of Vestigo Java Course.
 * 
 * @author Šimun Šopar
 *
 */

public class Suma {
	
	/**
	 * The main method of the class.
	 * The method parses through the first 30 even natural numbers, determining which number ends in digit 4. 
	 * The method also calculates the sum of the first 30 even natural numbers.
	 * The sum and the numbers ending with 4 are then printed.
	 * @param args
	 * 			The args argument of the main method, does not expect any input to be given.
	 */
	
	public static void main(String[] args) {
		
		int stop = 30;
		int divider = 10;
		int endingDigit = 4;
		int[] IsDivisible = new int[(int)(2*stop/divider) + 1];
		short divisibleIndex = 0;
		
		int suma = 0;
		
		
		
		for(int i = 1; i <= stop; i++) {
			suma += 2*i;
			if((2*i) % divider == endingDigit) {IsDivisible[divisibleIndex] = 2*i; divisibleIndex ++;}
		}
		
		System.out.println(suma);
		for(int i = 0; i < IsDivisible.length; i++) {
			if(IsDivisible[i] == 0) break;
			System.out.print(IsDivisible[i] + " ");
		}
		
	}
}
