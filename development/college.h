/* cat murad, lab 6
 * this is the interface for a derived class. this will include position, team, hometown, and highschool
 */

#ifndef COLLEGE_H
#define COLLEGE_H

#include "player.h"
#include <string>

//derived class, inherits from player
class College : public Player {
  
  public:
    College();		//constructor
    virtual void print();

  private:
    string Position;
    string Team;
    string Hometown;
    string Highschool;
};

#endif
