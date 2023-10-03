package hr.vestigo.java.tecaj.zadaca4.garden;

import java.util.ArrayList;
import hr.vestigo.java.tecaj.zadaca4.plants.Plantable;
import hr.vestigo.java.tecaj.zadaca4.exceptions.*;
import hr.vestigo.java.tecaj.zadaca4.plants.Tree;

/**
 * Garden class. Describes the garden which consists of plots.
 * @author Šimun
 *
 */

public class Garden {
	private ArrayList <Plot> parcels = new ArrayList<Plot>();
	
	
	/**
	 * Constructor of the class.
	 * Takes a layout of plots and constructs garden with those plots.
	 * @param gardenLayout
	 * String which is array of letters 'F'(Flowerbed) and 'O'(Orchard), which describe types and positions of plots in garden.
	 */
	public Garden(String gardenLayout) {
		for(int i = 0; i < gardenLayout.length(); i++) {
			if(gardenLayout.charAt(i) == 'F')
				parcels.add(new Flowerbed());
			else
				parcels.add(new Orchard());
		}
	}
	
	
	
	/**
	 * Method which prints all the plants in the garden in a formatted way. 
	 * @return
	 * String "0"
	 */
	public String toString() {
		for(int i = 0; i < parcels.size(); i++) {
			if(parcels.get(i) instanceof Flowerbed)
				System.out.println(String.valueOf(i) + ". Flowerbed");
			else
				System.out.println(String.valueOf(i) + ". Orchard");

			parcels.get(i).toString();
		}
		
		return "0";
	}
	
	/**
	 * Waters all plants in the garden.
	 */
	public void addWater() {
		for(int i = 0; i < parcels.size(); i++) {
			parcels.get(i).addWater();
		}
	}
	
	/**
	 * Plants a plant on available spot
	 * @param p
	 * Plantable to be planted.
	 * @return
	 * 0 if the planting was succesful, -1 if planting was unsuccesful and the plant was Tree object, -2 if planting was unsuccesful and the plant 
	 * was Flower object.
	 */
	public int plant(Plantable p) {
		for(int i = 0; i < parcels.size(); i++) {
			for(int j = 0; j < Plot.capacity; j++) {
				try {
					parcels.get(i).addPlant(j, p);
					return 0;
				}
				catch (InvalidPlantType e) {
					break;
				}
				catch (SpaceOccupiedException e) {
					continue;
				}
			}
		}
		if(p instanceof Tree)
			return -1;
		else
			return -2;
	}
	
}
