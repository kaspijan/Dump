package hr.vestigo.java.tecaj.zadaca5;

/**
 * Space interface. 
 * Describes a parking space.
 * @author Šimun
 *
 */
public interface Space {
	/**
	 * Method which tells user if a parking space is already taken.
	 * @return
	 * True if the space is taken.
	 */
	boolean getIsTaken();
	
	/**
	 * Method that changes the state of the parking space.
	 * @param state
	 * The state to which to set parking lot vacancy.
	 */
	void setIsTaken(boolean state);
}
