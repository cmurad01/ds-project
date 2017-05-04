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
#include <algorithm>

using namespace std;

// Function Prototypes
void openRoster(ifstream &, string, ifstream &, string); // Open two rosters (for comparision)
void openOneRoster(ifstream &, string); // Open one roster
void fullRosterPrint(ifstream &, string); // Print one full roster
void positionRosterPrint(ifstream &, string); // Print one roster by specified position
void heightRosterPrint(ifstream &, string); // Print one roster by specified height
void weightRosterPrint(ifstream &, string); // Print one roster by specified weight
void yearRosterPrint(ifstream &, string); // Print one roster by specified year
void twoRosterPrint(ifstream &, string, ifstream &, string); // Compare rosters
int optionPrint(); // Display choice of rosters

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
		cout << "Welcome to the SEC Football Roster Analyst" << endl;
		
		while (choice != 7) {
		cout << "Please select an option:" << endl;
		cout << "Press 1 to view an entire team's roster" << endl;
		cout << "Press 2 to view a roster by position" << endl;
		cout << "Press 3 to view a roster by height" << endl;
		cout << "Press 4 to view a roster by weight" << endl;
		cout << "press 5 to view a roster by year" << endl;
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
			optionPrint();
			cout << "Enter the name of a roster: " << endl;
			cin >> choice2;
			positionRosterPrint(inChoice2, choice2);
		} else if (choice == 3) {
			// Roster by height option	
			ifstream inChoice3;
			string choice3;
			cout << "Enter the name of a roster: " << endl;
			cin >> choice3;
			heightRosterPrint(inChoice3, choice3);
		} else if (choice == 4) {
			// Roster by weight option
			ifstream inChoice4;
			string choice4;
			cout << "Enter the name of a roster: " << endl;
			cin >> choice4;
			weightRosterPrint(inChoice4, choice4);
		} else if (choice == 5) {
			// Roster by year option
			ifstream inChoice5;
			string choice5;
			cout << "Enter the name of a roster: " << endl;
			cin >> choice5;
			yearRosterPrint(inChoice5, choice5);
		} else if (choice == 6) {
			// Compare rosters option
			ifstream inRoster1, inRoster2;
			string roster1, roster2;
			optionPrint();
			cout << "Enter the name of the first roster: " << endl;
			cin >> roster1;
			cout << "Enter the name of the second roster: " << endl;
			cin >> roster2;
			twoRosterPrint(inRoster1, roster1, inRoster2, roster2);
		} else if (choice == 7) {
			cout << "Thank you for using the SEC Football Roster Analyst" << endl;
			return 0; 		
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
	rosterData arr[4]; // Roster data array
	string posChoice; // Choice input by user
	cout << "Enter a position group to search: " << endl;
	cout << "(Options are OL, QB, TE, WR, P, K, DL, DE, CB, S, LB)" << endl;
	cin >> posChoice; // Store user input 
	openOneRoster(inRoster1, roster1); // Open roster
		
	cout << "Number" << setw(20) << "First Name" << setw(10) << "Last Name" << setw(10) << "Position" << setw(10) << "Height" << setw(10) << "Weight" << setw(10) << "Year" << setw(40) << "Hometown/High School" << endl;
	
	for (int i = 0; i < 4; i++) { // Iterate through roster		
		inRoster1 >> arr[i].num >> arr[i].fName >> arr[i].lName >> arr[i].pos >> arr[i].ht >> arr[i].wt >> arr[i].yr >> arr[i].homehs;
		if (arr[i].pos == posChoice) { // Output positions based on user input
			cout << arr[i].num << setw(20) << arr[i].fName << setw(10) << arr[i].lName << setw(10) << arr[i].pos << setw(!0) << setw(10) << arr[i].ht << setw(10) << arr[i].wt << setw(10) << arr[i].yr << setw(40) << arr[i].homehs << endl;
			cout << endl;
			cout << endl;	
		}
	}
}

void heightRosterPrint(ifstream &inRoster1, string roster1) {
	rosterData arr[4]; // Roster data array
	string posChoice; // Choice input by user
	cout << "Enter a height to search: " << endl;
	cout << "Please separate values with '-'" << endl;
	cout << "Ex. 6-0" << endl;
	cin >> posChoice; // Store user input 
	openOneRoster(inRoster1, roster1); // Open roster
		
	cout << "Number" << setw(20) << "First Name" << setw(10) << "Last Name" << setw(10) << "Position" << setw(10) << "Height" << setw(10) << "Weight" << setw(10) << "Year" << setw(40) << "Hometown/High School" << endl;
	
	for (int i = 0; i < 4; i++) { // Iterate through roster		
		inRoster1 >> arr[i].num >> arr[i].fName >> arr[i].lName >> arr[i].pos >> arr[i].ht >> arr[i].wt >> arr[i].yr >> arr[i].homehs;
		if (arr[i].ht == posChoice) { // Output positions based on user input
			cout << arr[i].num << setw(20) << arr[i].fName << setw(10) << arr[i].lName << setw(10) << arr[i].pos << setw(!0) << setw(10) << arr[i].ht << setw(10) << arr[i].wt << setw(10) << arr[i].yr << setw(40) << arr[i].homehs << endl;
			cout << endl;
			cout << endl;	
		}
	}
}
void weightRosterPrint(ifstream &inRoster1, string roster1) {
	rosterData arr[4]; // Roster data array
	string posChoice; // Choice input by user
	cout << "Enter a weight to search: " << endl;
	cout << "Enter any number" << endl;
	cin >> posChoice; // Store user input 
	openOneRoster(inRoster1, roster1); // Open roster
		
	cout << "Number" << setw(20) << "First Name" << setw(10) << "Last Name" << setw(10) << "Position" << setw(10) << "Height" << setw(10) << "Weight" << setw(10) << "Year" << setw(40) << "Hometown/High School" << endl;
	
	for (int i = 0; i < 4; i++) { // Iterate through roster		
		inRoster1 >> arr[i].num >> arr[i].fName >> arr[i].lName >> arr[i].pos >> arr[i].ht >> arr[i].wt >> arr[i].yr >> arr[i].homehs;
		if (arr[i].wt == posChoice) { // Output positions based on user input
			cout << arr[i].num << setw(20) << arr[i].fName << setw(10) << arr[i].lName << setw(10) << arr[i].pos << setw(!0) << setw(10) << arr[i].ht << setw(10) << arr[i].wt << setw(10) << arr[i].yr << setw(40) << arr[i].homehs << endl;
			cout << endl;
			cout << endl;	
		}
	}
}

void yearRosterPrint(ifstream &inRoster1, string roster1) {
	rosterData arr[4]; // Roster data array
	string posChoice; // Choice input by user
	cout << "Enter a year  to search: " << endl;
	cout << "Options are FR, SO, JR, SR, GS" << endl;
	cin >> posChoice; // Store user input 
	openOneRoster(inRoster1, roster1); // Open roster
		
	cout << "Number" << setw(20) << "First Name" << setw(10) << "Last Name" << setw(10) << "Position" << setw(10) << "Height" << setw(10) << "Weight" << setw(10) << "Year" << setw(40) << "Hometown/High School" << endl;
	
	for (int i = 0; i < 4; i++) { // Iterate through roster		
		inRoster1 >> arr[i].num >> arr[i].fName >> arr[i].lName >> arr[i].pos >> arr[i].ht >> arr[i].wt >> arr[i].yr >> arr[i].homehs;
		if (arr[i].yr == posChoice) { // Output positions based on user input
			cout << arr[i].num << setw(20) << arr[i].fName << setw(10) << arr[i].lName << setw(10) << arr[i].pos << setw(!0) << setw(10) << arr[i].ht << setw(10) << arr[i].wt << setw(10) << arr[i].yr << setw(40) << arr[i].homehs << endl;
			cout << endl;
			cout << endl;	
		}
	}
}

void twoRosterPrint(ifstream &inRoster1, string roster1, ifstream &inRoster2, string roster2) {
	rosterData arr[4], arr2[4];// Roster data array
	//string userChoice;
	string compare;
	//cout << "Select an attribute to compare: " << endl;
	//cout << "Options are num, fName, lName, pos, ht, wt, yr" << endl;
	//cin >> userChoice;
	cout << "Select a comparison parameter: " << endl;
	cout << "This parameter can be a position, height, weight, or year" << endl;
	cout << "Reminder: Valid positions are QB, RB, WR, TE, OL, DL, DE, LB, CB, S, K, P" << endl;
	cin >> compare;
	optionPrint();
	openRoster(inRoster1, roster1, inRoster2, roster2); // Open roster
		
	cout << "Number" << setw(20) << "First Name" << setw(10) << "Last Name" << setw(10) << "Position" << setw(10) << "Height" << setw(10) << "Weight" << setw(10) << "Year" << setw(40) << "Hometown/High School" << endl;
	
	for (int i = 0; i < 4; i++) { // Iterate through roster		
		inRoster1 >> arr[i].num >> arr[i].fName >> arr[i].lName >> arr[i].pos >> arr[i].ht >> arr[i].wt >> arr[i].yr >> arr[i].homehs;
		for (int j = 0; j < 4; j++) {
			inRoster2 >> arr2[j].num >> arr2[j].fName >> arr2[j].lName >> arr2[j].pos >> arr2[j].ht >> arr2[j].wt >> arr2[j].yr >> arr2[j].homehs;
			if ((arr[i].pos == compare && arr2[j].pos == compare) || (arr[i].ht == compare && arr2[j].ht == compare) || (arr[i].wt == compare && arr2[j].wt == compare) || (arr[i].yr == compare && arr2[j].yr == compare)) { // Output positions based on user input				
				
				cout << arr[i].num << setw(20) << arr[i].fName << setw(10) << arr[i].lName << setw(10) << arr[i].pos << setw(10) << arr[i].ht << setw(10) << arr[i].wt << setw(10) << arr[i].yr << setw(40) << arr[i].homehs << endl;
				cout << endl;
				cout << endl;
				cout << arr2[j].num << setw(20) << arr2[j].fName << setw(10) << arr2[j].lName << setw(10) << arr2[j].pos << setw(10) << arr2[j].ht << setw(10) << arr2[j].wt << setw(10) << arr2[j].yr << setw(40) << arr2[j].homehs << endl;	
				cout << endl;
				cout << endl;
			}
		}
	}
}

int optionPrint() {
	cout << "alabama.txt" << endl;
	cout << "texasam.txt" << endl;
	return 0;
}		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		

