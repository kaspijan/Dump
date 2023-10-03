package hr.vestigo.java.tecaj.zadaca5;

/**
 * Car class, describing a car kind of vehicle.
 * A car objects VehicleSize is MEDIUM.
 * @author Šimun
 */

public class Car implements Vehicle{
	private VehicleSize carSize = VehicleSize.MEDIUM;
	private VehicleType carType = null;
	
	/**
	 * Constructor of class.
	 * Sets the VehicleType of the class.
	 * @param type
	 * VehicleType of the car.
	 */
	public Car(VehicleType type) {
		carType = type;
	}
	
	public VehicleSize getSize() {
		return carSize;
	}
	
	public VehicleType getType() {
		return carType;
	}
	
}
