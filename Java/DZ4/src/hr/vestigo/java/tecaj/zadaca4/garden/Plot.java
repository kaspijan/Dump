package hr.vestigo.java.tecaj.zadaca4.garden;

import hr.vestigo.java.tecaj.zadaca4.plants.*;
import hr.vestigo.java.tecaj.zadaca4.exceptions.*;

/**
 * Plot interface. 
 * Interface which describes one garden plot in which plants can be planted.
 * @author Šimun
 *
 */

public interface Plot {
	/**
	 * capacity is a constant, number of plants that can be planted on one plot.
	 */
	final int capacity = 4;
	
	/**
	 * Method that adds a plant p on the i-th place in the plot (i starts at 0).
	 * @param i
	 * Position in plot where the plant is to be planted.
	 * @param p
	 * Plantable to be planted.
	 * @return
	 * true if the plant was succesfully planted.
	 * @throws InvalidPlantType
	 * Exception thrown in case the plant type does not match the plot type.
	 * @throws SpaceOccupiedException
	 * Exception thrown in case the space i is already occupied.
	 */
	public boolean addPlant(int i, Plantable p) throws InvalidPlantType, SpaceOccupiedException;
	
	/**
	 * Method which returns what plant is planted on position i.
	 * @param i 
	 * Position on the plot for which we inquire the planted plant.
	 * @return
	 * Plantable at position i. If no plant is planted, returns null.
	 */
	public Plantable getPlant(int i);
	
	/**
	 * Counts the number of plants on the plot.
	 * @return
	 * Number of plants on plot.
	 */
	public int countPlants();
	
	/**
	 * Method which waters all plants on plot.
	 */
	public void addWater();
	
	/**
	 * Method which prints all the plants on the plot in a formatted way.
	 * @return
	 * Some trivial string (e.g. "0").
	 */
	public String toString();
	
}
