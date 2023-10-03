package hr.vestigo.java.tecaj.zadaca5;

import java.util.ArrayList;
import java.util.Collections;
import java.util.LinkedHashMap;

/**
 * Main class of the problem, is responsible for running the calculation.
 * Class was written as a solution to Task 1 of Homework 5 of Vestigo Java Course.
 * @author Šimun
 *
 */

public class Main {
	
	/**
	 * The main method of the class. 
	 * The method takes input from a TestString object and finds the most common word in each input string.
	 * The method excludes the most common words from counting, which are gathered in an array called commonWords.
	 * @param args
	 * The args argument of the main method, does not expect any input to be given.
	 */
	public static void main(String args[]) {
		TestStrings input = new TestStrings();
		input.fillList();
		
		
		String[] commonWords = {"the", "a", "or", "an", "it", 
				"and", "but", "is", "are", "of", "on", "to", "was", "were", 
				"in", "that", "i", "your", "his", "their", "her", "you", "me", "all"};
		
		ArrayList<String> commonWordsList = new ArrayList<String>();
		Collections.addAll(commonWordsList, commonWords);
		
		int index = 1;
		for(String s : input.testStrings) {
			LinkedHashMap<String, Integer> wordFrequency = new LinkedHashMap<String, Integer>();
			s = s.toLowerCase();
			s = s.replace("\n", " ");
			s = s.replace(".", "");
			s = s.replace(",", "");
			String[] words = s.split(" ");
			
			for(String w : words) {
				if(!commonWordsList.contains(w) && !w.equals("")) {
					if(!wordFrequency.containsKey(w)) 
						wordFrequency.put(w, 1);
					else
						wordFrequency.put(w, wordFrequency.get(w) + 1);
				}		
			}
			
			int maxFrequency = 0;
			String maxString = "";
			for(String key : wordFrequency.keySet()){
				if(wordFrequency.get(key) > maxFrequency) {
					maxString = key;
					maxFrequency = wordFrequency.get(key);
				}
			}
			System.out.println("U " + index + ". tekstu najèešæa rijeè je " + maxString + ", pojavljuje se " + maxFrequency + " puta.");
			System.out.println();
			index++;
		}
	}
}
