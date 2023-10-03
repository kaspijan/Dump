package hr.vestigo.java.tecaj.zadaca4.exceptions;

/**
 * SpaceOccupiedException class, extends Exception
 * Is raised when a space in garden is alread occupied by a plant.
 * @author Šimun
 *
 */

public class SpaceOccupiedException extends Exception{
	/**
	 * Constructor of class, pritns an error message.
	 * @param spaceIndex
	 * Position of plant
	 * @param plantName
	 * Name of plant.
	 */
	public SpaceOccupiedException(Integer spaceIndex, String plantName) {
		System.out.println("The parcel space " + spaceIndex.toString() + " is already occupied by a " + plantName);
	}
	
	/**
	 * Constructor of class.
	 */
	public SpaceOccupiedException () {}
}
