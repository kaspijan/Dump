package hr.vestigo.java.tecaj.zadaca4;

import hr.vestigo.java.tecaj.zadaca4.plants.*;
import hr.vestigo.java.tecaj.zadaca4.gardener.*;
import hr.vestigo.java.tecaj.zadaca4.garden.*;
import hr.vestigo.java.tecaj.zadaca4.exceptions.NoRoomInGardenException;

import java.io.IOException;
import java.util.Scanner;

/**
 * Main class of the problem, is responsible for starting and running the garden calculation.
 * Class was written as a solution to Homework 4 of Vestigo Java Course.
 * @author Šimun
 *
 */

public class Main {
	
	/**
	 * The main method of the class.
	 * The method creates Garden and Gardener objects and takes instructions through standard input.
	 * The instructions can be to plant a plant, to water the garden, to observe and to quit calculation.
	 * @param args 
	 * The args argument of the main method, does not expect any input to be given.
	 * @throws IOException
	 * IOException is thrown if an error occurs in instruction input.
	 */
	
	public static void main(String args[]) throws IOException{
		Garden garden = new Garden("FFOF");
		Gardener gardener = new Gardener();
		
		String possiblePlantCommands = "ACDFTRJVIMOBPSNEKH";
		
		Scanner in = new Scanner(System.in);
		availablePlants plants = new availablePlants();
		//InputStreamReader in = new InputStreamReader(System.in);
		
		
		System.out.println("Welcome to the garden.\nThe gardener is in. Here you can plant and water plants, and admire the view.");
		
		System.out.println("\nGarden overview:");
		gardener.admirePlants(garden);
		
		System.out.println("\nYou can operate the gardener by using commands:");
		System.out.println("\tPX - Plant X[type of plant] (Available flowers commands are " + possiblePlantCommands.substring(0, 9) + 
				", available trees are " + possiblePlantCommands.substring(9, 18) + ")");
		System.out.println("\tW - Water all plants");
		System.out.println("\tL - Look at the garden");
		System.out.println("\tQ - Quit");
		
		String command = null;
		
		while( (command = in.nextLine()) != null && !command.equals("Q")) {
			if(command.equals("W")) 
				gardener.waterPlants(garden);
			
			else if(command.equals("L"))
				gardener.admirePlants(garden);
			
			else if(command.charAt(0) == 'P') {
				if(possiblePlantCommands.indexOf(command.charAt(1)) != -1) {
					try {
						plantParser(command.charAt(1), garden, gardener, plants);	
					}
					catch (NoRoomInGardenException e) {
						
					}
				}
				
				else 
					System.out.println("The gardener does not have that plant available.");
			}
		}
		
		System.out.println("The gardener is now out. Thank you for visiting.");
		in.close();
	}
	
	private static void plantParser(char plant, Garden garden, Gardener gardener, availablePlants plants) throws NoRoomInGardenException{
		switch (plant) {
			case 'A':
				gardener.plant(garden, plants.new Amaranthus());
				break;
			case 'C':
				gardener.plant(garden, plants.new Calendula());
				break;
			case 'D':
				gardener.plant(garden, plants.new Daffodil());
				break;
			case 'F':
				gardener.plant(garden, plants.new Freesia());
				break;
			case 'T':
				gardener.plant(garden, plants.new Tulip());
				break;
			case 'R':
				gardener.plant(garden, plants.new Rose());
				break;
			case 'J':
				gardener.plant(garden, plants.new Jasmine());
				break;
			case 'V':
				gardener.plant(garden, plants.new Violet());
				break;
			case 'I':
				gardener.plant(garden, plants.new Iris());
				break;
				
				
			case 'M':
				gardener.plant(garden, plants.new Magnolia());
				break;
			case 'O':
				gardener.plant(garden, plants.new Oak());
				break;
			case 'B':
				gardener.plant(garden, plants.new Beech());
				break;
			case 'P':
				gardener.plant(garden, plants.new Pine());
				break;
			case 'S':
				gardener.plant(garden, plants.new Spruce());
				break;
			case 'N':
				gardener.plant(garden, plants.new Negundo());
				break;
			case 'E':
				gardener.plant(garden, plants.new Elm());
				break;
			case 'K':
				gardener.plant(garden, plants.new Chestnut());
				break;
			case 'H':
				gardener.plant(garden, plants.new Hawthorn());
				break;
			
		}
	}
	
}
