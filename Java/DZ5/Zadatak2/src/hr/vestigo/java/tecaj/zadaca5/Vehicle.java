package hr.vestigo.java.tecaj.zadaca5;

/**
 * Vehicle interface.
 * Describes general vehicles.
 * @author Šimun
 *
 */

public interface Vehicle {
	/**
	 * Method returns size of the vehicle.
	 * @return
	 * Size of the vehicle.
	 */
	VehicleSize getSize();
	
	/**
	 * Method returns type of the vehicle.
	 * @return
	 * Type of the vehicle.
	 */
	VehicleType getType();
	
}
