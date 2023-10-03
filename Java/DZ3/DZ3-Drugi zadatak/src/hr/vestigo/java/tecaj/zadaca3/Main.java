package hr.vestigo.java.tecaj.zadaca3;


/**
 * The Main class of the problem.
 * The class runs the football game calculation.
 * Class contains a main method which starts the calculation and a nested class FootballGame which runs necessary calculations.
 * Class was written as a solution to Task 2 of Homework 3 of Vestigo Java Course.
 * @author Šimun
 *
 */

public class Main {

	/**
	 * A nested FootballGame class which runs all the necessary calculations.
	 * The class contains a method playGame which will run the calculations.
	 * the playGame method is called upon initializing an instance of FootballGame class.
	 * @author Šimun
	 *
	 */
	public static class FootballGame {
	
		/**
		 * Constructor of class.
		 * When called, it will run the playGame method.
		 */
		public FootballGame() {
			playGame();
			}
		
		/**
		 * numOfPlayers is a constant containing information on number of players in a football game.
		 */
		final static int numOfPlayers = 22;
		private Team blue = new Team("blue", 55, 87);
		private Team white = new Team("white", 56, 80);
		
		/**
		 * Method playGame which runs the calculations. It checks that both teams have correct attack and defense stats.
		 * Then it determines the winning team and the team with most exclusions (hrv. iskljuèenje, nisam siguran u prijevod).
		 * It then prints the winning team, number of goals and exlusions and whether they had more or less exlusions then the other team.
		 * In case of a tie, it will print number of goals of both teams and a team with more exlusions, with number of exlusions listed.
		 */
		public void playGame() {
			
			
			String blueColor = blue.getColor();
			String whiteColor = white.getColor();
			
			int blueAtk = blue.getAttack();
			int whiteAtk = white.getAttack();
			
			int blueDef = blue.getDefense();
			int whiteDef = white.getDefense();
			
			if(!(blue.checkStats(blueAtk, blueDef) && white.checkStats(whiteAtk, whiteDef))) {
				System.out.println("Invalid attack or defense statistics. Should be in range 1 - 100.");
				return;
			}
			
			
			int goal1 = blue.numOfScoredGoals(blueAtk);
			int goal2 = white.numOfScoredGoals(whiteAtk);
			
			int excl1 = blue.numOfExclusions(blueDef);
			int excl2 = white.numOfExclusions(whiteDef);
			
			if(goal1 > goal2) {
				System.out.println("The winning team had " + blueColor + " uniforms, they scored " + String.valueOf(goal1) + " goals, with " + String.valueOf(excl1) + " exclusions.");
				if(excl1 > excl2) System.out.println("They had more exclusions then the other team");
				else if(excl1 < excl2) System.out.println("They had less exclusions then the other team");
				else System.out.println("They had the same number of exclusions as the other team");
			}
			else if(goal1 < goal2) {
				System.out.println("The winning team had " + whiteColor + " uniforms, they scored " + String.valueOf(goal2) + " goals, with " + String.valueOf(excl2) + " exclusions.");
				if(excl1 < excl2) System.out.println("They had more exclusions then the other team");
				else if(excl1 > excl2) System.out.println("They had less exclusions then the other team");
				else System.out.println("They had the same number of exclusions as the other team");
			}
			else {
				System.out.println("The game was a tie with " + String.valueOf(goal1) + " goals.");
				if(excl1 > excl2) System.out.println("The " + blueColor + " team had more exclusions, " + String.valueOf(excl1));
				else if(excl1 < excl2) System.out.println("The " + whiteColor + " team had more exclusions, " + String.valueOf(excl2));
				else System.out.println("They had the same number of exclusions, " + String.valueOf(excl1));
			}
			
		}
		
	}
	
	
	/**
	 * the main method of the class.
	 * It constructs a new FootballGame object, which will run the necessary calculation.
	 * @param args
	 * The args parameter of the method. The method does not expect any input to be given.
	 */
	public static void main(String[] args) {
		FootballGame Game = new FootballGame();
	}
	
}

