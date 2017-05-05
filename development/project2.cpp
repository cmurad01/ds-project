#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <iomanip>
#include <cstring>
#include <cstdlib>

using namespace std;

// Function Prototypes
void openRoster(ifstream &, string, ifstream &, string);


// Struct
struct rosterData {
	string number;
	string firstName;
	string lastName;
	string position;
	string height;
	string weight;
	string year;
	string hometown;
	string highSchool;
};

int main(int argc, char* argv[]) {
	vector<rosterData> ros1, ros2;
	ifstream inRoster1, inRoster2;
	string roster1, roster2;
	cout << "Please enter the name of the first roster: " << endl;
	getline(cin, roster1);
	cout << "Please enter the name of the second roster: " << endl;
	getline(cin, roster2);
	openRoster(inRoster1, roster1, inRoster2, roster2);
	rosterData r1, r2;
	//size_t size = r1.size();
	
		for (int i = 0; i < ros1.size(); i++) {
	 		inRoster1 >> ros1[i].number >> ros1[i].firstName >> ros1[i].lastName >> ros1[i].position >> ros1[i].height >> ros1[i].weight >> ros1[i].year >> ros1[i].hometown >> ros1[i].highSchool;
			ros1[i].push_back(r1);
		}
		for (int i = 0; i < ros2.size(); i++) {
			inRoster2 >> ros2[i].number >> ros2[i].firstName >> ros2[i].lastName >> ros2[i].position >> ros2[i].height >> ros2[i].weight >> ros2[i].year >> ros2[i].hometown >> ros2[i].highSchool;
			ros2[i].push_back(r2);
		}
	//ros2.push_back(r2);
	//vector<rosterData>::iterator it;
	
	cout << "Player contains: ";
	for (int i = 0; i < ros1.size(); i++) {
		cout << " " << ros1[i].number << endl;
		cout << " " << ros1[i].firstName << endl;
		cout << " " << ros1[i].lastName << endl;
		cout << " " << ros1[i].position << endl;
		cout << " " << ros1[i].height << endl;
		cout << " " << ros1[i].weight << endl;
		cout << " " << ros1[i].year << endl;
		cout << " " << ros1[i].hometown << endl;
		cout << " " << ros1[i].highSchool << endl;
	}
	//for (it = ros2.begin(); it < ros2.end(); it++) {
	for (int i = 0; i < ros2.size(); i++) {
		cout << " " << ros2[i].number << endl;
		cout << " " << ros2[i].firstName << endl;
		cout << " " << ros2[i].lastName << endl;
		cout << " " << ros2[i].position << endl;
		cout << " " << ros2[i].height << endl;
		cout << " " << ros2[i].weight << endl;
		cout << " " << ros2[i].year << endl;
		cout << " " << ros2[i].hometown << endl;
		cout << " " << ros2[i].highSchool << endl;
	}
	return 0;
}

void openRoster(ifstream &inRoster1, string roster1, ifstream &inRoster2, string roster2) {
	inRoster1.open(roster1.c_str());
	inRoster2.open(roster2.c_str());

	if (!inRoster1) {
		cout << "Could not open " << roster1 << endl;
		return;
	}
	if (!inRoster2) {
		cout << "Could not open " << roster2 << endl;
		return;
	}
}

