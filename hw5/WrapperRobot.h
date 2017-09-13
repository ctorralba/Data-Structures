/* Christopher Torralba			File: WrapperRobot.h
	 Date: 3/3/16							Section: B
 */

#ifndef WRAPPERROBOT_H
#define WRAPPERROBOT_H
#include "AbstractRobot.h"

#include <string>

class WrapperRobot : public AbstractRobot {
    int regHour;
    int numPackages;
    string typeName;
public:
    //constructor
    WrapperRobot(string n, int hours, int packages) : AbstractRobot(n) {
        regHour = hours;
        numPackages = packages;
        typeName = "Wrapper";
    }
    
    float getPay() const {
        return regHour*.25 + numPackages*.05;
    }
    
    const string& getName() const {
        return m_name;
        }
        
    const string& getType() const {
        return typeName;
        }
        
    ~WrapperRobot(){};
};

#endif
