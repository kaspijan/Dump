package hr.vestigo.java.tecaj.zadaca3;

/**
 * Main class of the problem, is responsible for starting the computation.
 * Class contains a method which will start running the computation.
 * Class was written as a solution to Task 1 of Homework 3 of Vestigo Java Education.
 * 
 * @author Šimun
 *
 */

public class Main {

	/**
	 * The main method of the class.
	 * The method creates a Solver object and runs solver calculation which will print all 1-digit and 3-digit prime numbers, as well as all 2-digit and
	 * 4-digit palindrome numbers.
	 * @param args 
	 * The args argument of the main method, does not expect any input to be given.
	 */
	public static void main(String[] args) {
		
		Solver solv = new Solver();
		solv.solver();
		
	}
	
}
