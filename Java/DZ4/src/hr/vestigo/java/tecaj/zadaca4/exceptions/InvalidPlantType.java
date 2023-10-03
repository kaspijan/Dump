package hr.vestigo.java.tecaj.zadaca4.exceptions;

/**
 * InvalidPlantType class, extends Exception.
 * Is raised when plants are trying to be planted on the wrong place.
 * @author Šimun
 *
 */

public class InvalidPlantType extends Exception{
	/**
	 * Constructor of class.
	 * @param plantType
	 * plant type (tree or flower usually)
	 * @param parcelType
	 * Parcel type (flowerbed or orchard usually)
	 */
	public InvalidPlantType(String plantType, String parcelType) {
		System.out.println("You cannot plant " + plantType + " on a " + parcelType + " parcel.");
	}
	
	/**
	 * Constructor of class.
	 */
	public InvalidPlantType() {}
}
