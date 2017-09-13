/* Christopher Torralba		File: AbstractRobot.h
  Date: 3/3/16						Section: B
 */

#ifndef ABSTRACTROBOT_H
#define ABSTRACTROBOT_H

#include <string>

using namespace std; 


//----------------------------------------
/* _______________________
  /                       \
  | AbstractRobot Class   |
  \_______________________/

    ABSTRACT CLASS

    PURPOSE: Base class for all Robot Employee classes.
 
*/
class AbstractRobot {
protected:
  string m_name;    // the name of the robot
   
public:  
// Purpose: Constructor
// Postconditions: name set to parameter
// -- INLINE
   AbstractRobot(string n) :
	     m_name(n)	 
	 {}
   
// Purpose: Returns the pay of the robot
// -- VIRTUAL
virtual float getPay() const = 0;

// Purpose: Returns the Robot's name.
// -- VIRTUAL
virtual const string& getName() const = 0;

// Purpose: Returns the Robot's type.
// -- VIRTUAL
virtual const string& getType() const = 0;


// Purpose: Destructor
// -- INLINE
virtual ~AbstractRobot() {}


}; //Abstract Robot


#endif
