package day4;

import java.io.*;

public class PartOne {

	public static void main(String[] args) throws IOException {

		File file = new File("src\\day4\\input.txt");
		BufferedReader br = new BufferedReader(new FileReader(file));

		String str;
		Integer counter = 0;

		while ((str = br.readLine()) != null) {

			String[] pairs = str.split(",");
			
			//get both pairs in the string
			String pair1 = pairs[0];
			String pair2 = pairs[1];
			
			//first get each number in each pair, then convert those strings to ints
			String str_pair1first, str_pair1second, str_pair2first, str_pair2second;
			Integer int_pair1first, int_pair1second, int_pair2first, int_pair2second;

			System.out.println("Comparing " + pair1 + " and " + pair2);
			
			//get each number in each pair to strings
			str_pair1first = pair1.split("-")[0];
			str_pair1second = pair1.split("-")[1];
			str_pair2first = pair2.split("-")[0];
			str_pair2second = pair2.split("-")[1];
			
			//strings to integers
			int_pair1first = Integer.parseInt(str_pair1first);
			int_pair1second = Integer.parseInt(str_pair1second);
			int_pair2first = Integer.parseInt(str_pair2first);
			int_pair2second = Integer.parseInt(str_pair2second);
			
			//if pair1 contains pair2
			if ((int_pair1first <= int_pair2first) && (int_pair1second >= int_pair2second)) {
				System.out.println(pair1 + " contains " + pair2);
				counter++;
			} //else if pair2 contains pair1
			else if ((int_pair2first <= int_pair1first) && (int_pair2second >= int_pair1second)) {
				System.out.println(pair2 + " contains " + pair1);
				counter++;
			}
		}

		System.out.println(counter);
	}
}
