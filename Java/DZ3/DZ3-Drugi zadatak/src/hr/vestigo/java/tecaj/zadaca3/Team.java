package hr.vestigo.java.tecaj.zadaca3;

/**
 * Team class. It contains all relevant information and methods for handling football teams.
 * The class contains methods getColor, getAttack and getDefense which return Color, Attack and Defense attributes respectively, as well as
 * numOfScoredGoals and numOfExlusions which calculate and return scored goals and exlusions of the team.
 * @author Šimun
 *
 */
public class Team {
	private String uniformColor;
	private int defenseStats;
	private int attackStats;
	
	/**
	 * Constructor of class
	 * @param color
	 * Color of uniform.
	 * @param def
	 * Defense stat.
	 * @param atk
	 * Attack stat.
	 */
	public Team(String color, int def, int atk) {
		uniformColor = color;
		defenseStats = def;
		attackStats = atk;
	}
	
	/**
	 * A method that checks whether the attack and defense staticstics are valid.
	 * @param attack
	 * The attack statistic to check.
	 * @param defense
	 * The defense statistic to check.
	 * @return
	 * A boolean value, true if statistics are valid, false otherwise.
	 */
	public boolean checkStats(int attack, int defense) {
		return attack >= 1 && attack <= 100 && defense >= 1 && defense <= 100;
	}
	
	/**
	 * A method that calculated number of scored goals.
	 * @param attack
	 * The attack statistic for which a number of goal is calculated.
	 * @return
	 * Returns integer, number of scored goals.
	 */
	public int numOfScoredGoals(int attack) {
		return attack / 10;
	}
	
	/**
	 * A method that calculated number of exlusions.
	 * @param defense
	 * The defense statistic for which a number of exlusions is calculated.
	 * @return
	 * Returns integer, number of exlusions.
	 */
	public int numOfExclusions(int defense) {
		return (100 - defense)/5;
	}
	
	/**
	 * Method that returns uniform color of the team.
	 * @return
	 * Uniform color of the team.
	 */
	public String getColor() {
		return uniformColor;
	}
	
	/**
	 * Method that returns defense stat of the team.
	 * @return
	 * Defense stat of the team.
	 */
	public int getDefense() {
		return defenseStats;
	}
	
	/**
	 * Method that returns attack stat of the team.
	 * @return
	 * Attack stat of the team.
	 */
	public int getAttack() {
		return attackStats;
	}
	
}
