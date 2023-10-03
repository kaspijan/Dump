package hr.vestigo.java.tecaj.zadaca4.plants;

/**
 * Tree class.
 * Implements Plantable interface.
 * Describes plant type: trees.
 * @author Šimun
 *
 */
public class Flower implements Plantable{
	private int waterDosage;
	private String plantName;
	
	/**
	 * Constructor of class. 
	 * @param plantName
	 * The name of the flower type.
	 */
	public Flower(String plantName){
		waterDosage = 0;
		this.plantName = plantName;
	}
	
	public void addWater() {
		waterDosage++;
		if(waterDosage > 1) {
			waterDosage = 1;
		}
	}
	
	/**
	 * Returns name of the flower type in lower case if the flower was watered 0 times, in upper case if watered 1 or more times.
	 */
	public String toString() {
		if(waterDosage == 1) {
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
