package hr.vestigo.java.tecaj.zadaca4.gardener;

//import hr.vestigo.java.tecaj.zadaca4.garden.Plot;
import hr.vestigo.java.tecaj.zadaca4.garden.Garden;
import hr.vestigo.java.tecaj.zadaca4.plants.Plantable;
import hr.vestigo.java.tecaj.zadaca4.exceptions.NoRoomInGardenException;


/**
 * Gardener class. Gardener takes care of the garden (or multiple gardens).
 * @author Šimun
 *
 */

public class Gardener {
	/**
	 * Constructor of class.
	 */
	public Gardener() {}
	
	/**
	 * Method which plants a plant in a garden.
	 * @param g
	 * Garden where the plant is to be planted.
	 * @param p
	 * Plantable to be planted.
	 * @throws NoRoomInGardenException
	 * Exception that is thrown in case no more room is unavailble for a certain type of plants.
	 */
	public void plant(Garden g, Plantable p) throws NoRoomInGardenException {
		int planted = g.plant(p);
		if(planted == -1)
			throw new NoRoomInGardenException("trees");
		else if(planted == -2)
			throw new NoRoomInGardenException("flowers");
	}
	
	/**
	 * Waters all plants in garden g.
	 * @param g
	 * Garden where plants are watered.
	 */
	public void waterPlants(Garden g) {
		g.addWater();
	}
	
	/**
	 * Prints all the plants in garden.
	 * @param g
	 * The garden where plants are watered.
	 */
	public void admirePlants(Garden g) {
		g.toString();
	}
}
