//Oscar Damaszk
// 4/6/2025
//The purpose of this project is to convert an input text file of cities with fahrenheit temperatures
//into an output text file of the same cities with celsius temperatures

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
	//Constant for converting from Fahrenheit to Celcius
	const double FAHRENHEIT_TO_CELCIUS = 5.0 / 9.0;

	//Open the input file
	cout << "Opening file: FahrenheitTemperature.txt" << endl;
	ifstream inputFile("FahrenheitTemperature.txt");

	//Check to see if the file has been opened successfully
	if (!inputFile) {
		cout << "Error: Unable to open input file." << endl;
		return 1; //1 indicates error
	}

	//Open the output file
	cout << "Opening file:  CelciusTemperature.txt" << endl;
	ofstream outputFile("CelsiusTemperature.txt");

	//Check to see if the file has been opened successfully
	if (!outputFile) {
		cout << "Error: Unable to open output file." << endl;
		return 1; //1 indicates error
	}

	//Read and store data from input file
	string city;
	int fahrenheit;
	while (inputFile >> city >> fahrenheit) {
		//Convert fahrenheit to celsius using formula of C = (F - 32) * (5/9)
		double celsius = (fahrenheit - 32.0) * FAHRENHEIT_TO_CELCIUS;

		//Write the city and Celsius temperature to the output file
		outputFile << city << " " << celsius << endl;
	}

	//Close the input and output files
	inputFile.close();
	outputFile.close();

	cout << "Fahrenheit to Celsius conversion completed. Data written to CelsiusTemperature.txt." << endl;

	return 0;
}