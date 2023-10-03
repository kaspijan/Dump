package hr.vestigo.java.tecaj.zadaca4.garden;

import hr.vestigo.java.tecaj.zadaca4.plants.*;
import hr.vestigo.java.tecaj.zadaca4.exceptions.*;



/**
 * Flowerbed class, a type of Plot dedicated to planting flowers.
 * Implements Plot interface.
 * Only Plantables of class Flower can be planted here.
 * @author Šimun
 *
 */
public class Flowerbed implements Plot{
	
	private Plantable plants[] = new Plantable[capacity];
	
	public Flowerbed() {
		for (int i = 0; i < capacity; i++) {
			plants[i] = null;
		}
	}
	
	public boolean addPlant(int i, Plantable p) throws InvalidPlantType, SpaceOccupiedException {
		if(!(p instanceof Flower)) {
			//throw new InvalidPlantType("TREE", "FLOWERBED");
			throw new InvalidPlantType();
		}
		else {
			
			if (plants[i] == null) {
				plants[i] = p;
				return true;
			}
			else {
				//Flower tmpFlower = (Flower)plants[i];
				//throw new SpaceOccupiedException(i, tmpFlower.getPlantName());
				throw new SpaceOccupiedException();
			}
		}	
	}
	
	public Plantable getPlant(int i) {
		return plants[i];
	}
	
	public int countPlants() {
		int counter = 0;
		for(int i = 0; i < capacity; i++) {
			if(plants[i] != null) 
				counter++;
		}
		return counter;
	}
	
	public String toString() {
		System.out.print("\t");
		for(int i = 0; i < capacity; i++) {
			if(plants[i] == null) 
				System.out.print(String.valueOf(i) + ". *empty* |");
			else {
				System.out.print(String.valueOf(i) + ". ");
				Flower tmpFlower = (Flower)plants[i];
				tmpFlower.toString(); //možda treba dodati neki string u koji sprema output, vidjet æemo
				System.out.print(" |");
			}
				
		}
		System.out.println();
		return "0";
	}
	
	public void addWater() {
		for(int i = 0; i < capacity; i++) {
			if(plants[i] != null)
				plants[i].addWater();
		}
	}
	
}
