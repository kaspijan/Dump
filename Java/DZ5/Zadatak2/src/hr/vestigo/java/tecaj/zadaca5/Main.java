package hr.vestigo.java.tecaj.zadaca5;

public class Main {

	public static void main(String[] args) {
		
		String input = "AAAAAATTTTTTTTCCCKTKBBBC";
		
		ParkingLot parkingLot = new ParkingLot(10, 24, 9, 0, 5, 0);
		
		for(int i = 0; i < input.length(); i++) {
			if(input.charAt(i) == 'M') parkingLot.park(new Bike(VehicleType.HANDICAPPED));
			else if(input.charAt(i) == 'A') parkingLot.park(new Car(VehicleType.HANDICAPPED));
			else if(input.charAt(i) == 'K') parkingLot.park(new Truck(VehicleType.HANDICAPPED));
			else if(input.charAt(i) == 'B') parkingLot.park(new Bike(VehicleType.REGULAR));
			else if(input.charAt(i) == 'C') parkingLot.park(new Car(VehicleType.REGULAR));
			else if(input.charAt(i) == 'T') parkingLot.park(new Truck(VehicleType.REGULAR));
		}
		
		
		parkingLot.getEmptySpaces();
		
	}
	
}
