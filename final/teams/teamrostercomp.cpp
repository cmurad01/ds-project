#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
	string Number, Number2, Name, Name2,  Position, Position2, Height, Height2, Weight, Weight2, Year, Year2, Hometown, Hometown2, HighSchool, HighSchool2;
	ifstream inFile1, inFile2;
  string myFile1, myFile2; // File names
  cout << "Enter the name of the first file: " << endl;
  getline(cin, myFile1);
	cout << "Enter the name of the second file: " << endl;
	getline(cin, myFile2);
  inFile1.open(myFile1.c_str()); // Open first file
	inFile2.open(myFile2.c_str()); // Open second file
	ofstream compfile("rosters.txt");
	
	if (!inFile1) { // Check that first file exists
		cout << "Unable to open file " << myFile1 << ". Please enter another file and try again." << endl;
	return 0;			
	}	

	if (!inFile2) { // Check that second file exists
			cout << "Unable to open file " << myFile2 << ". Please enter another file and try again." << endl;
	return 0;
	}
	//cout << myFile1 << " DATA" << endl;
  while (inFile1) {
    getline(inFile1, Number, ',');
    getline(inFile1, Name, ',');
		getline(inFile1, Position, ',');
    getline(inFile1, Height, ',');
    getline(inFile1, Weight, ',');
    getline(inFile1, Year, ',');
    getline(inFile1, Hometown, ',');
    getline(inFile1, HighSchool);
  
    compfile << "NUMBER: " << Number << " NAME:" << Name << " POSITION:" << Position << " HT:" << Height << " WT:" << Weight << " YEAR:" << Year << " HOMETOWN/HIGH SCHOOL:" << Hometown << "/" << HighSchool << " High School" << endl;
  }
	//cout << myFile2 << " DATA" << endl;
	while (inFile2) {
		//cout << myFile2 << " DATA" << endl;
		string Number2; 
		getline(inFile2, Number2, ',');
		getline(inFile2, Name2, ',');
		getline(inFile2, Position2, ',');
		getline(inFile2, Height2, ',');
		getline(inFile2, Weight2, ',');
		getline(inFile2, Year2, ',');
		getline(inFile2, Hometown2, ',');
		getline(inFile2, HighSchool2);
		
		compfile << "NUMBER: " << Number2 << " NAME:" << Name2 << " POSITION:" << Position2 << " HT:" << Height2 << " WT:" << Weight2 << " YEAR:" << Year2 << " HOMETOWN/HIGH SCHOOL:" << Hometown2 << "/" << HighSchool2 << " High School" << endl;
	}
	//bool isSame = true;
	while (!inFile1.eof() || !inFile2.eof()) {
		//string Number, Number2; //Name1, Name2, Pos1, Pos2, Height1, Height2, Weight1, Weight2, Year1, Year2, Home1, Home2, High1, High2
  	if (Number == Number2) {
			cout << "The same: " << Number2 << endl;
		}
	}
	inFile1.close();
	inFile2.close();
	return 0;
}
