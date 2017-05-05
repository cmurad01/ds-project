#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <vector>

using namespace std;

// Function Protoypes
void openRoster(ifstream &, string, ifstream &, string);
//rosterData parseData(ifstream &source);
// Struct for roster data
struct rosterData {
	string number;
	string firstName;
	string lastName;
	string position;
	string height;
	string weight;
	string  year;
	string hometown;
	//string highSchool;	
};

int main() {
	rosterData arr[4], arr2[4];
	string number, firstName, lastName, position, height, weight, year, hometown; //highSchool;
	rosterData tempData;
	ifstream inRoster1, inRoster2;
	string roster1, roster2;
	cout << "Enter the name of the first roster: " << endl;
	cin >> roster1;
	cout << "Enter the name of the second roster: " << endl;
	cin >> roster2;
	openRoster(inRoster1, roster1, inRoster2, roster2);
	
	cout << "Number" << setw(20) << "First Name" << setw(10) << "Last Name" << setw(10) << "Position" << setw(10) << "Height" << setw(10) << "Weight" << setw(10) << "Year" << setw(40) << "Hometown/Highschool" << endl;
	for (int i = 0; i < 4; i++) {
		inRoster1 >> arr[i].number >> arr[i].firstName >> arr[i].lastName >> arr[i].position >> arr[i].height >> arr[i].weight >> arr[i].year >> arr[i].hometown; //>> arr[i].highSchool;
	}	
	for (int j = 0; j < 4; j++) {
		inRoster2 >> arr2[j].number >> arr2[j].firstName >> arr2[j].lastName >> arr2[j].position >> arr2[j].height >> arr2[j].weight >> arr2[j].year >> arr2[j].hometown;// >> arr2[j].highSchool;	}
	}
	for (int i = 0; i < 4; i++) {
		cout << arr[i].number << setw(20) << arr[i].firstName << setw(10) << arr[i].lastName << setw(10) << arr[i].position << setw(10) << arr[i].height << setw(10) << arr[i].weight << setw(10) << arr[i].year << setw(40) << arr[i].hometown << endl; //"/" << arr[i].highSchool << endl;//cout << "Name: " << arr[i].firstName << " " << arr[i].lastName << endl;//cout << "Position: " << arr[i].position << endl;
		//cout << "Height: " << arr[i].height << endl;
		//cout << "Weight: " << arr[i].weight << endl;
		//cout << "Year: " << arr[i].year << endl;
		//cout << "Hometown: " << arr[i].hometown << endl;
		//cout << "High school: " << arr[i].highSchool << endl;
	}
	for (int i = 0; i < 4; i++) {
		cout << arr2[i].number << setw(20) << arr2[i].firstName << setw(10) << arr2[i].lastName << setw(10) << arr2[i].position << setw(10) << arr2[i].height << setw(10) << arr2[i].weight << setw(10) << arr2[i].year << setw(40) << arr2[i].hometown << endl;//"/" << arr2[i].highSchool << endl;	}
	
}

void openRoster(ifstream &inRoster1, string roster1, ifstream &inRoster2, string roster2) {
	//cout << "Enter the name of the first roster: " << endl;
	//getline(cin, roster1);
	//cout << "Enter the name of the second roster: " << endl;
	//getline(cin, roster2);
	inRoster1.open(roster1.c_str()); // Open first roster
	inRoster2.open(roster2.c_str()); // Open second roster

	if (!inRoster1) {
		cout << "Error opening "  << roster1 <<  endl;
	return;
	}
	if (!inRoster2) {
		cout << "Error opening " << roster2 << endl;
		return;
	}
}


