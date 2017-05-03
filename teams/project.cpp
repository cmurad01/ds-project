// Brynne DuBois and Cat Murad 
// Professor Scott and Professor Kumar
// CSE 20312
// May 5, 2017
// Project
// project.cpp

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <stdio.h>
#include <string.h>

using namespace std;

// Function Prototypes
void openRoster(ifstream &, string, ifstream &, string); // Open two rosters (for comparision)
void openOneRoster(ifstream &, string); // Open one roster
void fullRosterPrint(ifstream &, string); // Print one full roster
void positionRosterPrint(ifstream &, string); // Print one roster by specified position
// Struct for roster data
struct rosterData {
	string num; // Player number
	string fName; // Player first name
	string lName; // Player last name
	string pos; // Player position
	string ht; // Player height
	string wt; // Player weight
	string yr; // Player year (FR, SO, JR, SR, GS)
	string homehs; // Player hometown and high school
};

int main() {
	// Create a while loop to display menu options to the user
	int choice;
	while (choice != 7 ) {
		cout << "Welcome to the SEC Football Roster Analyst" << endl;
		cout << "To begin, please select an option:" << endl;
		cout << "Press 1 to view an entire team's roster" << endl;
		cout << "Press 2 to view a roster by position" << endl;
		cout << "Press 3 to view a roster by year" << endl;
		cout << "Press 4 to view a roster by height" << endl;
		cout << "press 5 to view a roster by weight" << endl;
		cout << "Press 6 to compare two rosters by the above attributes" << endl;
		cout << "Pree 7 to exit" << endl;
		cout << "Please enter to your choice: " << endl;
		cin >> choice;

		// If statements to handle menu options
		if ( choice == 1) { 
			// View roster function
			ifstream inChoice1;
			string choice1;
			cout << "Enter the name of a roster: " << endl;
			cin >> choice1;
			fullRosterPrint(inChoice1, choice1);		
		} else if (choice == 2) {
			// Roster by position option
			ifstream inChoice2;
			string choice2;
			cout << "Enter the name of a roster: " << endl;
			cin >> choice2;
			positionRosterPrint(inChoice2, choice2);
		} else if (choice == 3) {
			// Roster by year option
		} else if (choice == 4) {
			// Roster by height option
		} else if (choice == 5) {
			// Roster by weight option
		} else if (choice == 6) {
			// Compare rosters option
		} else if (choice == 7) {
			cout << "Thank you for using the SEC Football Roster Analyst" << endl;
			return 0; 
		} else {
			cout << "That option was not recognized, please select a valid option" << endl;
		}
	}
}

// Open two rosters (for comparison function)
void openRoster(ifstream &inRoster1, string roster1, ifstream &inRoster2, string roster2) {
	inRoster1.open(roster1.c_str()); // Open first roster and convert contents to strings
	inRoster2.open(roster2.c_str()); // Open second roster and convert contents to strings
	
	if (!inRoster1) {
		cout << "Error opening " << roster1 << endl;
		return;
	}
	if (!inRoster2) {
		cout << "Error opening " << roster2 << endl;
		return;
	}
}

// Open one roster
void openOneRoster(ifstream &inRoster1, string roster1) {
	inRoster1.open(roster1.c_str());
	if (!inRoster1) {
		cout << "Error opening " << roster1 << endl;
		return;
	}
}

void fullRosterPrint(ifstream &inRoster1, string roster1) {
	string num, fName, lName, pos, ht, wt, yr, homehs;
	rosterData arr[4];
	openOneRoster(inRoster1, roster1);
	cout << "Number" << setw(20) << "First Name" << setw(10) << "Last Name" << setw(10) << "Position" << setw(10) << "Height" << setw(10) << "Weight" << setw(10) << "Year" << setw(40) << "Hometown/High School" << endl;
	for (int i = 0; i < 4; i++) {
	//string num, fName, lName, pos, ht, wt, yr, homehs;
	//rosterData arr[4];
	//openOneRoster(inRoster1, roster1);
	//cout << "Number" << setw(20) << "First Name" << setw(10) << "Last Name" << setw(10) << "Position" << setw(10) << "Height" << setw(10) << "Weight" << setw(10) << "Year" << setw(40) << "Hometown/High School" << endl;
	//for (int i = 0; i < 4; i++) {
		inRoster1 >> arr[i].num >> arr[i].fName >> arr[i].lName >> arr[i].pos >> arr[i].ht >> arr[i].wt >> arr[i].yr >> arr[i].homehs;
	}
	for (int i = 0; i < 4; i++) {
		cout << arr[i].num << setw(20) << arr[i].fName << setw(10) << arr[i].lName << setw(10) << arr[i].pos << setw(10) << arr[i].ht << setw(10) << arr[i].wt << setw(10) << arr[i].yr << setw(40) << arr[i].homehs << endl;
	}	
}


void positionRosterPrint(ifstream &inRoster1, string roster1) {
	rosterData arr[4];
	string posChoice;
	cout << "Enter a position group to search: " << endl;
	cout << "(Options are OL, QB, TE, WR, P, K, DL, DE, CB, S, LB)" << endl;
	cin >> posChoice;
	//int count;
	openOneRoster(inRoster1, roster1);
	cout << "Number" << setw(20) << "First Name" << setw(10) << "Last Name" << setw(10) << "Position" << setw(10) << "Height" << setw(10) << "Weight" << setw(10) << "Year" << setw(40) << "Hometown/High School" << endl;
	
	for (int i = 0; i < 4; i++) {		
	 inRoster1 >> arr[i].num >> arr[i].fName >> arr[i].lName >> arr[i].pos >> arr[i].ht >> arr[i].wt >> arr[i].yr >> arr[i].homehs;
			//cout << arr[i].num << setw(20) << arr[i].fName << setw(10) << arr[i].lName << setw(10) << arr[i].pos << setw(10) << arr[i].ht << setw(10) << arr[i].wt << setw(10) << arr[i].yr << setw(40) << arr[i].homehs << endl;		
		
		if (strarr[i].pos, posChoice) == 0) {
			cout << i << endl;
		} else {
			cout << "No";
		}
	}
	//cout << count;
}
