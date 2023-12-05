/*
	Brayden Dean
	C++ 2023
	Due: December/01/2023
	Lab 6
	Create a program that reads in a file of binary numbers, converts them to decimal numbers, and outputs
	the binary and decimal numbers to the screen. It should read each character one at a time using the get() function.
	Any inputed character that is not a 1 or 0 should be considered a bad digit and outputed as such. Spaces at the
	beginning of the line should be ignored, but spaces in the middle of the line should be considered bad digits.
*/

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

int main() {
	//Initialize variables
	std::string binary;
	int decimal = 0;
	int width = 25;
	char bin;
	bool valid = true;

	//Open file
	std::ifstream BinaryIn;
	BinaryIn.open("BinaryIn.dat");

	//Check if file opened
	if (!BinaryIn) {
		std::cout << "Error opening file" << std::endl;
		return 1;
	}

	//Output header
	std::cout << std::setw(width) << std::left << "Binary Number" << std::right << "Decimal Equivalent" << std::endl;
	std::cout << std::setw(width) << std::left << "-------------" << std::right << "------------------" << std::endl;

	//Method 1
	//Read in file
	BinaryIn.get(bin);
	//Loop through file
	while (BinaryIn) {
		//Check for spaces at beginning of line
		while (bin == ' ') {
			binary += bin;
			BinaryIn.get(bin);
		}
		//Loop through binary numbers
		while (bin == '1' || bin == '0') {
			//Calculate decimal number
			binary += bin;
			if (bin == '1') {
				decimal *= 2;
				decimal += 1;
			}
			else if (bin == '0') {
				decimal *= 2;
				decimal += 0;
			}
			//Get next binary number
			BinaryIn.get(bin);
			//Check for bad digit
			if (bin != '1' && bin != '0' && bin != '\n') {
				valid = false;
				break;
			}
			//Check for end of file
			if (BinaryIn.eof()) break;
		}

		//Add rest of line to binary string if bad digit
		while (bin != '\n') {
			if (BinaryIn.eof()) break;
			binary += bin;
			BinaryIn.get(bin);
		}
		//Output binary and decimal numbers
		if (valid) {
			std::cout << std::setw(width) << std::left << binary << std::right << decimal << std::endl;
		}
		//Output binary and bad digit
		else {
			std::cout << std::setw(width) << std::left << binary << std::right << "Bad digit on input" << std::endl;
			valid = true;
		}
		//Reset variables
		binary = "";
		decimal = 0;
		BinaryIn.get(bin);
	}

	////Method 2
	////Read in file
	//BinaryIn.get(bin);
	////Loop through file
	//while (BinaryIn) {
	//	//Add characters to binary string
	//	while (bin != '\n') {
	//		binary += bin;
	//		BinaryIn.get(bin);
	//		if (BinaryIn.eof()) break;
	//	}

	//	//Output binary number
	//	std::cout << std::left << std::setw(width) << binary;

	//	//Calculate decimal number
	//	for (char& c : binary) {
	//		decimal *= 2;
	//		//Check for 1 or 0
	//		if (c == '1') {
	//			decimal += 1;
	//		}
	//		else if (c == '0') {
	//			decimal += 0;
	//		}
	//		//Output for bad digit
	//		else {
	//			std::cout << std::right << std::fixed << "Bad digit on input" << std::endl;
	//			valid = false;
	//			break;
	//		}
	//	}	
	//	//Output decimal number if valid binary number
	//	if (valid) {
	//		std::cout << std::right << std::fixed << decimal << std::endl;
	//	}
	//	//Reset variables
	//	decimal = 0;
	//	valid = true;
	//	binary = "";
	//	BinaryIn.get(bin);
	//}

	////Method 3
	////Read in file, skipping spaces
	//std::getline(BinaryIn >> std::ws, binary);
	////Loop through file
	//while (BinaryIn){
	//	//Reset decimal number
	//	decimal = 0;
	//	//Output binary number
	//	std::cout << std::left << std::setw(width) << binary;
	//	//Calculate decimal number
	//	for (char& c : binary) {
	//		decimal *= 2;
	//		//Check for 1 or 0
	//		if (c == '1') {
	//			decimal += 1;
	//		}
	//		else if (c == '0') {
	//			decimal += 0;
	//		}
	//		//Output for bad digit
	//		else {
	//			std::cout << std::right << std::fixed << "Bad digit on input" << std::endl;
	//			valid = false;
	//			break;
	//		}
	//	}
	//	//Output decimal number if valid binary number
	//	if (valid) {
	//		std::cout << std::right << std::fixed << decimal << std::endl;
	//	}
	//	//Reset variables and get next line
	//	std::getline(BinaryIn >> std::ws, binary);
	//	valid = true;
	//}

	//Close file
	BinaryIn.close();

	return 0;
}