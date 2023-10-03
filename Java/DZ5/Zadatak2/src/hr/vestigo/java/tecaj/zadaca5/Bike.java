package hr.vestigo.java.tecaj.zadaca5;

/**
 * Bike class, describing a motor-bike kind of vehicle.
 * A bike objects VehicleSize is SMALL.
 * @author Šimun
 */

public class Bike implements Vehicle {
	private VehicleSize bikeSize = VehicleSize.SMALL;
	private VehicleType bikeType = null;
	
	/**
	 * Constructor of class.
	 * Sets the VehicleType of the class.
	 * @param type
	 * VehicleType of the bike.
	 */
	public Bike(VehicleType type) {
		bikeType = type;
	}
	
	public VehicleSize getSize() {
		return bikeSize;
	}
	
	public VehicleType getType() {
		return bikeType;
	}
}
