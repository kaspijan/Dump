package hr.vestigo.java.tecaj.zadaca5;

/**ParkingSpace class.
 * Describes specific parking space.
 * @author Šimun
 *
 */
public class ParkingSpace implements Space{
	
	private boolean isTaken = false;
	private VehicleType  vehicleType = null;
	private VehicleSize vehicleSize = null;
	
	/**
	 * Constructor of class. Generates a parking space of a certain type and size.
	 * @param size
	 * VechicleSize variable describing the size of the parking space.
	 * @param type
	 * VechicleType variable describing the type of parking space.
	 */
	public ParkingSpace(VehicleSize size, VehicleType type) {
		vehicleType = type;
		vehicleSize = size;
		this.setIsTaken(true);
	}
	
	public boolean getIsTaken() {
		return isTaken;
	}
	
	public void setIsTaken(boolean state) {
		isTaken = state;
	}
	/**
	 * Method returns parkign space type.
	 * @return
	 * Type of parking space.
	 */
	VehicleType getType() {
		return vehicleType;
	}
	
	/**
	 * Method returns parking space size.
	 * @return
	 * Size of parking space.
	 */
	VehicleSize getSize() {
		return vehicleSize;
	}
	
	
	
}
