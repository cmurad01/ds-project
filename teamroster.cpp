#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    string Number, Name, Position, Height, Weight, Year,  Hometown, HighSchool;
    ifstream inFile;
    string myFile;
    cout << "Enter the name of a file: " << endl;
    getline(cin, myFile);
    inFile.open(myFile.c_str());
    while (inFile) {
        getline(inFile, Number, ',');
        getline(inFile, Name, ',');
        getline(inFile, Position, ',');
        getline(inFile, Height, ',');
        getline(inFile, Weight, ',');
        getline(inFile, Year, ',');
        getline(inFile, Hometown, ',');
        getline(inFile, HighSchool);
  
        cout << "NUMBER: " << Number << " NAME:" << Name << " POSITION:" << Position << " HT:" << Height << " WT:" << Weight << " YEAR:" << Year << " HOMETOWN/HIGH SCHOOL:" << Hometown << "/" << HighSchool << endl;
    }
    inFile.close();
}
