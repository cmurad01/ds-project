/* Cat Murad, lab 6 
 * this is the player class. It will go much more in depth later in our project but I am starting out by making a class with height weight and name. 
 */

#ifndef PLAYER_H
#define PLAYER_H

#include <string>
using namespace std;

class Player {		//base class for player
  
  public:
    Player(string = "empty", string = "empty", string = "empty");     //constructor
    void setName(const string);
    void setHeight(const string);
    void setWeight(const string);
    string getName();
    string getHeight();
    string getWeight();

  protected:
    string name;
    string weight;
    string height;
};

#endif
