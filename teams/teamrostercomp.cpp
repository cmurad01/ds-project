#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
	string Number, Name, Position, Height, Weight, Year,  Hometown, HighSchool;
  ifstream inFile1, inFile2;
  string myFile1, myFile2; // File names
  cout << "Enter the name of the first file: " << endl;
  getline(cin, myFile1);
	cout << "Enter the name of the second file: " << endl;
	getline(cin, myFile2);
  inFile1.open(myFile1.c_str()); // Open first file
	inFile2.open(myFile2.c_str()); // Open second file

	if (!inFile1) { // Check that first file exists
		cout << "Unable to open file " << myFile1 << ". Please enter another file and try again." << endl;
	return 0;			
	}	

	if (!inFile2) { // Check that second file exists
			cout << "Unable to open file " << myFile2 << ". Please enter another file and try again." << endl;
	return 0;
	}
	cout << myFile1 << " DATA" << endl;
  while (inFile1) {
    getline(inFile1, Number, ',');
    getline(inFile1, Name, ',');
		getline(inFile1, Position, ',');
    getline(inFile1, Height, ',');
    getline(inFile1, Weight, ',');
    getline(inFile1, Year, ',');
    getline(inFile1, Hometown, ',');
    getline(inFile1, HighSchool);
  
    cout << "NUMBER: " << Number << " NAME:" << Name << " POSITION:" << Position << " HT:" << Height << " WT:" << Weight << " YEAR:" << Year << " HOMETOWN/HIGH SCHOOL:" << Hometown << "/" << HighSchool << " High School" << endl;
  }
	cout << myFile2 << " DATA" << endl;
	while (inFile2) {
		//cout << myFile2 << " DATA" << endl; 
		getline(inFile2, Number, ',');
		getline(inFile2, Name, ',');
		getline(inFile2, Position, ',');
		getline(inFile2, Height, ',');
		getline(inFile2, Weight, ',');
		getline(inFile2, Year, ',');
		getline(inFile2, Hometown, ',');
		getline(inFile2, HighSchool);
		
		cout << "NUMBER: " << Number << " NAME:" << Name << " POSITION:" << Position << " HT:" << Height << " WT:" << Weight << " YEAR:" << Year << " HOMETOWN/HIGH SCHOOL:" << Hometown << "/" << HighSchool << " High School" << endl;
	}

	string str1, str2;
  inFile1.close();
	inFile2.close();
}
