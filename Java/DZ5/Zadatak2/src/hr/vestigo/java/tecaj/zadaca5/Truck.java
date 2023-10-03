package hr.vestigo.java.tecaj.zadaca5;

/**
 * Truck class, describing a truck kind of vehicle.
 * A truck objects VehicleSize is LARGE.
 * @author Šimun
 *
 */
public class Truck implements Vehicle{
	private VehicleSize truckSize = VehicleSize.LARGE;
	private VehicleType truckType = null;
	
	/**
	 * Constructor of class.
	 * Sets the VehicleType of the class.
	 * @param type
	 * VehicleType of the truck.
	 */
	public Truck(VehicleType type) {
		truckType = type;
	}
	
	public VehicleSize getSize() {
		return truckSize;
	}
	
	public VehicleType getType() {
		return truckType;
	}
}
