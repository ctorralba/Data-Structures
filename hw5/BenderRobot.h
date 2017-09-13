/* Christopher Torralba			File: BenderRobot.h
	 Date: 3/3/16							Section: B
 */

#ifndef BENDERROBOT_H
#define BENDERROBOT_H
#include "AbstractRobot.h"

#include<string>

class BenderRobot : public AbstractRobot {
    int m_regHour;
    int m_bends;
    int m_extraTime;
    string typeName;
public:
    //constructor
    BenderRobot(string n, int hours, int extraTime, int bends) : AbstractRobot(n) {
        m_regHour = hours;
        m_bends = bends;
        m_extraTime = extraTime;
        typeName = "Bender";
    }
    
    float getPay() const {
        return m_regHour*.45 + m_extraTime*.65 + m_bends*.02;
    }
    
    const string& getName() const {
        return m_name;
        }
        
    const string& getType() const {
        return typeName;
        }
        
    ~BenderRobot(){};
};

#endif
