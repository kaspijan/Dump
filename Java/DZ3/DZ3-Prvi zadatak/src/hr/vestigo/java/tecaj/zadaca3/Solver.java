package hr.vestigo.java.tecaj.zadaca3;

import java.lang.Math;
import java.util.ArrayList;

/**
 * Solver class. This is the class that runs all the calculations.
 * Class contains method solver which runs the computation.
 * @author Šimun
 *
 */

public class Solver {

	private int start;
	private int stop;
	
	
	public Solver() {
		start = 1;
		stop = 4;
	}
	
	/**
	 * The solver method of the class.
	 * The method parses through numbers from 1 to 9999 and returns 2- and 4-digit numbers that are palindroms, as well as 1- and 3-digit prime numbers.
	 */
	public void solver() {
		ArrayList<Integer> primes = eratosten((int)(Math.pow(10, stop)));
		for(int i = start; i <= stop; i++) {
			
			if(i % 2 == 0) {
				for(int j = (int)(Math.pow(10, i-1)); j < Math.pow(10, i); j++) {
					if(isPalindrom(j) == true) System.out.println(j);
				}
			}
			
			else {
				for(int j = 0; j < primes.size(); j++) {
					if(primes.get(j) >= Math.pow(10, i)) break;
					if((int)(primes.get(j) / Math.pow(10, i)) == 0 && primes.get(j) >= Math.pow(10, i-1)) System.out.println(primes.get(j));
				}
			}
			
			
		}
	}
	
	private boolean isPalindrom(int x) {
		String query = String.valueOf(x);
		StringBuilder reverseQuery = new StringBuilder();
		reverseQuery.append(query);
		reverseQuery.reverse();
		return reverseQuery.toString().equals(query);
	}
	
	private ArrayList<Integer> eratosten(int stop) {
		ArrayList<Integer> primes = new ArrayList<Integer>();
		for(int i = 2; i <= stop; i++) primes.add(i);
		for(int i = 0; i < primes.size(); i++) {
			int currentInt = primes.get(i);
			for(int j = i + 1; j < primes.size(); j++) {
				if(primes.get(j) % currentInt == 0) {
					primes.remove(j);
					j--;
				}
			}
		}
		return primes;
	}
	
	
	
}
