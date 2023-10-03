package hr.vestigo.java.tecaj.zadaca5;

import java.util.HashMap;
import java.util.ArrayList;

/**
 * ParkingLot class, describes a parking lot made up of parking spaces.
 * Allows parking incoming vehicles, as well as telling which vehicles are parked, and which spots are still empty.
 * @author Šimun
 *
 */
public class ParkingLot {
	
	
	private HashMap<VehicleType, HashMap<VehicleSize, Integer>>lotSize = new HashMap<VehicleType, HashMap<VehicleSize, Integer>>();
	
	//private Integer[] size = {0, 0, 0, 0};
	
	private HashMap<VehicleSize, HashMap<VehicleType, ArrayList<ParkingSpace>>> parkingAvailableBySize = 
			new HashMap<VehicleSize, HashMap<VehicleType, ArrayList<ParkingSpace>>>();
	
	/**
	 * Sets the parking lot by describing amount of certain parking spaces available.
	 * @param bigRegul
	 * Number of LARGE, REGULAR parking spaces.
	 * @param midRegul
	 * Number of MIDDLE, REGULAR parking spaces.
	 * @param smallRegul
	 * Number of SMALL REGULAR parking spaces.
	 * @param bigHand
	 * Number of LARGE, HANDICAPPED parking spaces.
	 * @param midHand
	 * Number of MIDDLE, HANDICAPPED parking spaces.
	 * @param smallHand
	 * Number of SMALL, HANDICAPPED parking spaces.
	 */
	public ParkingLot(int bigRegul, int midRegul, int smallRegul, int bigHand, int midHand, int smallHand) {
		
		lotSize.put(VehicleType.REGULAR, new HashMap<VehicleSize, Integer>());
		lotSize.get(VehicleType.REGULAR).put(VehicleSize.LARGE, bigRegul);
		lotSize.get(VehicleType.REGULAR).put(VehicleSize.MEDIUM, midRegul);
		lotSize.get(VehicleType.REGULAR).put(VehicleSize.SMALL, smallRegul);
		
		lotSize.put(VehicleType.HANDICAPPED, new HashMap<VehicleSize, Integer>());
		lotSize.get(VehicleType.HANDICAPPED).put(VehicleSize.LARGE, bigHand);
		lotSize.get(VehicleType.HANDICAPPED).put(VehicleSize.MEDIUM, midHand);
		lotSize.get(VehicleType.HANDICAPPED).put(VehicleSize.SMALL, smallHand);
		
		
		
		parkingAvailableBySize.put(VehicleSize.LARGE, new HashMap<VehicleType, ArrayList<ParkingSpace>>());
		parkingAvailableBySize.get(VehicleSize.LARGE).put(VehicleType.REGULAR, new ArrayList<ParkingSpace>());
		parkingAvailableBySize.get(VehicleSize.LARGE).put(VehicleType.HANDICAPPED, new ArrayList<ParkingSpace>());
		
		parkingAvailableBySize.put(VehicleSize.MEDIUM, new HashMap<VehicleType, ArrayList<ParkingSpace>>());
		parkingAvailableBySize.get(VehicleSize.MEDIUM).put(VehicleType.REGULAR, new ArrayList<ParkingSpace>());
		parkingAvailableBySize.get(VehicleSize.MEDIUM).put(VehicleType.HANDICAPPED, new ArrayList<ParkingSpace>());
		
		parkingAvailableBySize.put(VehicleSize.SMALL, new HashMap<VehicleType, ArrayList<ParkingSpace>>());
		parkingAvailableBySize.get(VehicleSize.SMALL).put(VehicleType.REGULAR, new ArrayList<ParkingSpace>());
		parkingAvailableBySize.get(VehicleSize.SMALL).put(VehicleType.HANDICAPPED, new ArrayList<ParkingSpace>());
		
	}
	
	
	
	/**
	 * Method which tries to park a vehicle on available space.
	 * @param vehicle
	 * The vehicle to park.
	 * @return
	 * Returns the parking space where vehicle is parked. None if there is no space for vehicle.
	 */
	public ParkingSpace park(Vehicle vehicle) {
		return this.tryToPark(vehicle);
	}
	
	private ParkingSpace tryToPark(Vehicle vehicle) {
		
		System.out.println("Parking vehicle of type " + vehicle.getType() + " and of size " + vehicle.getSize());
		
		if(vehicle.getType() == VehicleType.HANDICAPPED) {
			if(vehicle.getSize() == VehicleSize.SMALL) {
				if(parkingAvailableBySize.get(VehicleSize.SMALL).get(VehicleType.HANDICAPPED).size() < lotSize.get(VehicleType.HANDICAPPED).get(VehicleSize.SMALL)) {
					parkingAvailableBySize.get(VehicleSize.SMALL).get(VehicleType.HANDICAPPED).add(new ParkingSpace(vehicle.getSize(), vehicle.getType()));
					System.out.println("Parked at SMALL HANDICAPPED spot.\n");
					return parkingAvailableBySize.get(VehicleSize.SMALL).get(VehicleType.HANDICAPPED)
							.get(parkingAvailableBySize.get(VehicleSize.SMALL).get(VehicleType.HANDICAPPED).size() - 1);
				}
			}
			
			if(vehicle.getSize() == VehicleSize.SMALL || vehicle.getSize() == VehicleSize.MEDIUM) {
				if(parkingAvailableBySize.get(VehicleSize.MEDIUM).get(VehicleType.HANDICAPPED).size() < lotSize.get(VehicleType.HANDICAPPED).get(VehicleSize.MEDIUM)) {
					parkingAvailableBySize.get(VehicleSize.MEDIUM).get(VehicleType.HANDICAPPED).add(new ParkingSpace(vehicle.getSize(), vehicle.getType()));
					System.out.println("Parked at MEDIUM HANDICAPPED spot.\n");
					return parkingAvailableBySize.get(VehicleSize.MEDIUM).get(VehicleType.HANDICAPPED)
							.get(parkingAvailableBySize.get(VehicleSize.MEDIUM).get(VehicleType.HANDICAPPED).size() - 1);
				}
			}
			
			if(vehicle.getSize() == VehicleSize.SMALL || vehicle.getSize() == VehicleSize.MEDIUM || vehicle.getSize() == VehicleSize.LARGE) {
				if(parkingAvailableBySize.get(VehicleSize.LARGE).get(VehicleType.HANDICAPPED).size() < lotSize.get(VehicleType.HANDICAPPED).get(VehicleSize.LARGE)) {
					parkingAvailableBySize.get(VehicleSize.LARGE).get(VehicleType.HANDICAPPED).add(new ParkingSpace(vehicle.getSize(), vehicle.getType()));
					System.out.println("Parked at LARGE HANDICAPPED spot.\n");
					return parkingAvailableBySize.get(VehicleSize.LARGE).get(VehicleType.HANDICAPPED)
							.get(parkingAvailableBySize.get(VehicleSize.LARGE).get(VehicleType.HANDICAPPED).size() - 1);
				}
			}
		}
		
		
		if(vehicle.getType() == VehicleType.HANDICAPPED || vehicle.getType() == VehicleType.REGULAR) {
			if(vehicle.getSize() == VehicleSize.SMALL) {
				if(parkingAvailableBySize.get(VehicleSize.SMALL).get(VehicleType.REGULAR).size() < lotSize.get(VehicleType.REGULAR).get(VehicleSize.SMALL)) {
					parkingAvailableBySize.get(VehicleSize.SMALL).get(VehicleType.REGULAR).add(new ParkingSpace(vehicle.getSize(), vehicle.getType()));
					System.out.println("Parked at SMALL REGULAR spot.\n");
					return parkingAvailableBySize.get(VehicleSize.SMALL).get(VehicleType.REGULAR)
							.get(parkingAvailableBySize.get(VehicleSize.SMALL).get(VehicleType.REGULAR).size() - 1);
				}
			}
			
			if(vehicle.getSize() == VehicleSize.SMALL || vehicle.getSize() == VehicleSize.MEDIUM) {
				if(parkingAvailableBySize.get(VehicleSize.MEDIUM).get(VehicleType.REGULAR).size() < lotSize.get(VehicleType.REGULAR).get(VehicleSize.MEDIUM)) {
					parkingAvailableBySize.get(VehicleSize.MEDIUM).get(VehicleType.REGULAR).add(new ParkingSpace(vehicle.getSize(), vehicle.getType()));
					System.out.println("Parked at MEDIUM REGULAR spot.\n");
					return parkingAvailableBySize.get(VehicleSize.MEDIUM).get(VehicleType.REGULAR)
							.get(parkingAvailableBySize.get(VehicleSize.MEDIUM).get(VehicleType.REGULAR).size() - 1);
				}
			}
			
			if(vehicle.getSize() == VehicleSize.SMALL || vehicle.getSize() == VehicleSize.MEDIUM || vehicle.getSize() == VehicleSize.LARGE) {
				if(parkingAvailableBySize.get(VehicleSize.LARGE).get(VehicleType.REGULAR).size() < lotSize.get(VehicleType.REGULAR).get(VehicleSize.LARGE)) {
					parkingAvailableBySize.get(VehicleSize.LARGE).get(VehicleType.REGULAR).add(new ParkingSpace(vehicle.getSize(), vehicle.getType()));
					System.out.println("Parked at LARGE REGULAR spot.\n");
					return parkingAvailableBySize.get(VehicleSize.LARGE).get(VehicleType.REGULAR)
							.get(parkingAvailableBySize.get(VehicleSize.LARGE).get(VehicleType.REGULAR).size() - 1);
				}
			}
		}
			
		System.out.println("No space for this vehicle type.");
		return null;
	}
	
	/**
	 * Prints all empty parking lot spaces.
	 */
	public void getEmptySpaces() {
		boolean isFull = true;
		for(VehicleSize size: parkingAvailableBySize.keySet()) {
			for(VehicleType type: parkingAvailableBySize.get(size).keySet()) {
				System.out.println("For vehicle of type " + type + " and size " + size + " there is " + 
						String.valueOf(lotSize.get(type).get(size)- parkingAvailableBySize.get(size).get(type).size()));
				if(lotSize.get(type).get(size)- parkingAvailableBySize.get(size).get(type).size() != 0)
					isFull = false;
			}
		}
		
		System.out.println("\nIs the parking lot full: " + isFull);
	}
	
	/**
	 * Prints all the spaces that are taken, as well as the vehicle that is parked on a space.
	 */
	public void getFullSpaces() {
		//boolean isFull = true;
		for(VehicleSize size: parkingAvailableBySize.keySet()) {
			for(VehicleType type: parkingAvailableBySize.get(size).keySet()) {
				System.out.println("Parking space of type " + type + " and size " + size + " contains these vehicles:");
				for(int i = 0; i < parkingAvailableBySize.get(size).get(type).size(); i++) {
					System.out.println("Vehicle of type " + parkingAvailableBySize.get(size).get(type).get(i).getType() + " and of size " 
							+ parkingAvailableBySize.get(size).get(type).get(i).getSize());
				}
			System.out.println();
			}
		}
		
		//System.out.println("\nIs the parking lot full: " + isFull + "\n");
	}
	
	/*
	public void isFull() {
		boolean isFull = true;
		for(VehicleSize size: parkingAvailableBySize.keySet()) {
			for(VehicleType type: parkingAvailableBySize.get(size).keySet()) {
				for(int i = 0; i < parkingAvailableBySize.get(size).get(type).size(); i++) {
					if(lotSize.get(type).get(size)- parkingAvailableBySize.get(size).get(type).size() != 0)
						isFull = false;
				}
			System.out.println();
			}
		}
		
		System.out.println("\nIs the parking lot full: " + isFull + "\n");
	}
	*/
	
	
	
}
