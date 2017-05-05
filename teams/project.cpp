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
void rosterBreakdown(ifstream &, string); // Viziualization of given roster
//void graphDisplay(ifstream &, string, ifstream &, string); // Vizualization of roster matches
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
		
		while (choice != 8) {
		cout << "Please select an option:" << endl;
		cout << "Press 1 to view an entire team's roster" << endl;
		cout << "Press 2 to view a roster by position" << endl;
		cout << "Press 3 to view a roster by height" << endl;
		cout << "Press 4 to view a roster by weight" << endl;
		cout << "press 5 to view a roster by year" << endl;
		cout << "Press 6 to compare two rosters by the above attributes" << endl;
		cout << "Press 7 to view a roster breakdown" << endl;
		cout << "Press 8 to exit" << endl;
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
			ifstream inChoice7;
			string choice7;
			cout << "Enter the name of a roster: " << endl;
			cin >> choice7;
			rosterBreakdown(inChoice7, choice7);
			} else if (choice == 8) {
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
	//sort(rosterData, rosterData+4);
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
	int count = 0;	
	cout << "Number" << setw(20) << "First Name" << setw(10) << "Last Name" << setw(10) << "Position" << setw(10) << "Height" << setw(10) << "Weight" << setw(10) << "Year" << setw(40) << "Hometown/High School" << endl;
	
	for (int i = 0; i < 4; i++) { // Iterate through roster		
		inRoster1 >> arr[i].num >> arr[i].fName >> arr[i].lName >> arr[i].pos >> arr[i].ht >> arr[i].wt >> arr[i].yr >> arr[i].homehs;
		if (arr[i].yr == posChoice) { // Output positions based on user input
			count++;
			cout << arr[i].num << setw(20) << arr[i].fName << setw(10) << arr[i].lName << setw(10) << arr[i].pos << setw(!0) << setw(10) << arr[i].ht << setw(10) << arr[i].wt << setw(10) << arr[i].yr << setw(40) << arr[i].homehs << endl;
			cout << endl;
			cout << endl;	
		}
	}
		cout << "There were " << count << " matches for your search" << endl;
}

void twoRosterPrint(ifstream &inRoster1, string roster1, ifstream &inRoster2, string roster2) {
	rosterData arr[4], arr2[4];// Roster data array
	//string userChoice;
	string compare;
	int count = 0;
	//cout << "Select an attribute to compare: " << endl;
	//cout << "Options are num, fName, lName, pos, ht, wt, yr" << endl;
	//cin >> userChoice;
	cout << "Select a comparison parameter: " << endl;
	cout << "This parameter can be a position, height, weight, or year" << endl;
	cout << "Reminder: Valid positions are QB, RB, WR, TE, OL, DL, DE, LB, CB, S, K, P" << endl;
	cin >> compare;
	optionPrint();
	openRoster(inRoster1, roster1, inRoster2, roster2); // Open roster
	string star = "";
	cout << "Number" << setw(20) << "First Name" << setw(10) << "Last Name" << setw(10) << "Position" << setw(10) << "Height" << setw(10) << "Weight" << setw(10) << "Year" << setw(40) << "Hometown/High School" << endl;
	
	for (int i = 0; i < 4; i++) { // Iterate through roster		
		inRoster1 >> arr[i].num >> arr[i].fName >> arr[i].lName >> arr[i].pos >> arr[i].ht >> arr[i].wt >> arr[i].yr >> arr[i].homehs;
		for (int j = 0; j < 4; j++) {
			inRoster2 >> arr2[j].num >> arr2[j].fName >> arr2[j].lName >> arr2[j].pos >> arr2[j].ht >> arr2[j].wt >> arr2[j].yr >> arr2[j].homehs;
			if ((arr[i].pos == compare && arr2[j].pos == compare) || (arr[i].ht == compare && arr2[j].ht == compare) || (arr[i].wt == compare && arr2[j].wt == compare) || (arr[i].yr == compare && arr2[j].yr == compare)) { // Output positions based on user input				
				count++;
				cout << arr[i].num << setw(20) << arr[i].fName << setw(10) << arr[i].lName << setw(10) << arr[i].pos << setw(10) << arr[i].ht << setw(10) << arr[i].wt << setw(10) << arr[i].yr << setw(40) << arr[i].homehs << endl;
				cout << endl;
				cout << endl;
				cout << arr2[j].num << setw(20) << arr2[j].fName << setw(10) << arr2[j].lName << setw(10) << arr2[j].pos << setw(10) << arr2[j].ht << setw(10) << arr2[j].wt << setw(10) << arr2[j].yr << setw(40) << arr2[j].homehs << endl;	
				cout << endl;
				cout << endl;
				//string star;
				star+="*";
			}
		}
	}
	cout << compare << ": " <<  star << endl;
	cout << "There were " << count << " matches between rosters" << endl;
}

void rosterBreakdown(ifstream &inRoster1, string roster1) {
	string num, fName, lName, pos, ht, wt, yr, homehs;
	rosterData arr[4];
	int choice;
	while (choice != 3) {
		cout << "Choose an attribute to view: " << endl;
		cout << "Press 1 to view by position" << endl;
		cout << "Press 2 to view by year" << endl;
		cout << "Press 3 to exit" << endl;
		cin >> choice;
	
		openOneRoster(inRoster1, roster1);
 		string posCount1 = ""; // QB
		string posCount2 = ""; // WR
		string posCount3 = ""; // TE
		string posCount4 = ""; // OL
		string posCount5 = ""; // DL
		string posCount6 = ""; // LB
		string posCount7 = ""; // DB
		string posCount8 = ""; // K
		string posCount9 = ""; // P
		string posCount10 = ""; // Other (in the case that something is missed
		string yrCount1 = ""; // Freshman
		string yrCount2 = ""; // Sophomore
		string yrCount3 = ""; // Junior
		string yrCount4 = ""; // Seniot
		string yrCount5 = ""; // Graduate Student		
		if (choice == 1) {
			for (int i = 0; i < 4; i++) {
				inRoster1 >> arr[i].num >> arr[i].fName >> arr[i].lName >> arr[i].pos >> arr[i].ht >> arr[i].wt >> arr[i].yr >> arr[i].homehs;
				if (arr[i].pos == "QB") {
					posCount1 += "*";
				}			 
				if (arr[i].pos == "WR") {
					posCount2 += "*";
				}
				if (arr[i].pos == "TE") {
					posCount3 += "*";
				}			
				if (arr[i].pos == "OL") {
					posCount4 += "*";
				}
				if (arr[i].pos == "DL") {
					posCount5 += "*";
				}
				if (arr[i].pos == "LB" ) {
					posCount6 += "*";
				}
				if (arr[i].pos == "DB") {
					posCount7 += "*";
				}
				if (arr[i].pos == "K") {
					posCount8 += "*";
				}
				if (arr[i].pos == "P") {
					posCount9 += "*";
				}
				if (arr[i].pos != "QB" && arr[i].pos != "WR" && arr[i].pos != "TE" && arr[i].pos != "OL" && arr[i].pos != "DL" && arr[i].pos != "LB" && arr[i].pos != "DB" && arr[i].pos != "K" && arr[i].pos != "P") {
					posCount10 += "*";
				}	
			}		
			cout << "Quarterbacks: " << posCount1 << endl;	
			cout << "Wide Receivers: " << posCount2 << endl;
			cout << "Tight Ends: " << posCount3 << endl;
			cout << "Offensive Lineman: " << posCount4 << endl;
			cout << "Defensive Lineman: " << posCount5 << endl;
			cout << "Linebackers: " << posCount6 << endl;
			cout << "Defensive Backs: " << posCount7 << endl;
			cout << "Kickers: " << posCount8 << endl;
			cout << "Punters: " << posCount9 << endl;
			cout << "Other: " << posCount10 << endl;
			} else if (choice == 2) {
			for (int i = 0; i < 4; i++) {
				inRoster1 >> arr[i].num >> arr[i].fName >> arr[i].lName >> arr[i].pos >> arr[i].ht >> arr[i].wt >> arr[i].yr >> arr[i].homehs;
				if (arr[i].yr == "FR") {
					yrCount1 += "*";
				}		
				if (arr[i].yr == "SO") {
					yrCount2 += "*";
				}
				if (arr[i].yr == "JR") {
					yrCount3 += "*";
				}
				if (arr[i].yr == "SR") {
					yrCount4 += "*";
				}
				if (arr[i].yr == "GS") {
					yrCount5 += "*";
				}
			}
			cout << "Freshman: " << yrCount1 << endl;
			cout << "Sophomores: " << yrCount2 << endl;
			cout << "Juniors: " << yrCount3 << endl;
			cout << "Seniors: " << yrCount4 << endl;
			cout << "Graduate Students: " << yrCount5 << endl;
		}	else if (choice == 3) {
			break;
		}	
	}
}


int optionPrint() {
	cout << "alabama.txt" << endl;
	cout << "texasam.txt" << endl;
	return 0;
}		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		

