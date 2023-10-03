package hr.vestigo.java.tecaj.zadaca4.plants;

/**
 * Tree class.
 * Implements Plantable interface.
 * Describes plant type: trees.
 * @author Šimun
 *
 */
public class Tree implements Plantable{
	private int waterDosage;
	private String plantName;
	
	/**
	 * Constructor of class. 
	 * @param plantName
	 * The name of the  tree type.
	 */
	public Tree(String plantName) {
		waterDosage = 0;
		this.plantName = plantName;
	}
	
	public void addWater() {
		waterDosage++;
		if(waterDosage > 2) {
		waterDosage = 2;
		}
	}
	
	/**
	 * Returns name of the tree type in lower case if the tree was watered 1 or less times, in upper case if watered 2 or more times.
	 */
	public String toString() {
		if(waterDosage == 2) {
			System.out.print(plantName.toUpperCase());
			return plantName.toUpperCase();
		}
		else {
			System.out.print(plantName.toLowerCase());
			return plantName.toLowerCase();
		}
	}
	
	/**
	 * Prints plant name. Can be useful with certain exceptions.
	 * @return
	 * String of the plant name surrounded with asterix.
	 */
	public String getPlantName() {
		return "*" + plantName + "*";
	}
	
}
