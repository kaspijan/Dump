package hr.vestigo.java.tecaj.zadaca4.exceptions;

/**
 * NoRoomInGardenException class, extend Exception.
 * Is raised when a certain plant type cannot be planted anymore in the garden.
 * @author Šimun
 *
 */

public class NoRoomInGardenException extends Exception{
	/**
	 * Constructor of class.
	 * Prints an error message.
	 */
	public NoRoomInGardenException() {
		System.out.println("No room for new plants in the garden.");
	}
	
	/**
	 * Constructor of class.
	 * Prints an error message.
	 * @param plantType
	 * Plant type (usually tree or flower) for which there are no more room.
	 */
	public NoRoomInGardenException(String plantType) {
		System.out.println("No room for new " + plantType + " in the garden.");
	}
}
