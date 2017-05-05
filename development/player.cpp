/* Cat Murad, lab 6
 * This is the implementation of the player class
 */


#include "player.h"
#include <iostream>

using namespace std;

//constructor for player class
Player::Player(string n, string ht, string wt) {
  name = n;
  height = ht;
  weight = wt;
}

//set player name 
void Player::setName(const string val) {
  name = val;
}

//set height
void Player::setHeight(const string val) {
  height = val;
}

//set weight
void Player::setWeight(const string val) {
  weight = val;
}

//get name
string Player::getName() {
 return (name);
}

//get weight
string Player::getWeight() {
  return (weight);
}

//get height
string Player::getHeight() {
  return (height);
}
