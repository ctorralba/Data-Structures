/* Christopher Torralba			File: WelderRobot.h
	 Date: 3/3/16							Section: B
 */

#ifndef WELDERROBOT_H
#define WELDERROBOT_H
#include "AbstractRobot.h"
#include <string>

class WelderRobot : public AbstractRobot {
    int m_regHour;
    int m_radioActive;
    int m_extraTime;
    string typeName;
public:
    //constructor
    WelderRobot(string n, int hours, int extraTime, int radioActive) : AbstractRobot(n) {
        m_regHour = hours;
        m_radioActive = radioActive;
        m_extraTime = extraTime;
        typeName = "Welder";
    }
    
    float getPay() const {
        return m_regHour*.55 + m_extraTime*.75 + m_radioActive + 9.99;
    }
    
    const string& getName() const {
        return m_name;
        }
        
    const string& getType() const {
        return typeName;
        }
        
    ~WelderRobot(){};
};

#endif
