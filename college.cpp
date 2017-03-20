/* cat murad, lab 6 
 * implementation for derived class
 */

#include "player.h"
#include "college.h"
#include <string>
#include <iostream>

using namespace std;

College::College() : Position("Linebacker"), Player("Josh Barajas") {
  Position = "Linebacker";
}


//want to include all of these attributes for the end result, but I could not get it to compile corrrectly

//College::College : Team("ND"), Player("Josh", "Barajas") {
  //Team = "ND";
//}

//College::College : Hometown("Valparaiso"), Player("Josh", "Barajas") {
 // Hometown = "Valparaiso";
//}

//College::College : Highschool("Andrean"), Player("Josh", "Barajas") {
 // Highschool = "Andrean";
//}

//print function
void College::print() {
  cout << name << " " << Position << " " << endl;
}
