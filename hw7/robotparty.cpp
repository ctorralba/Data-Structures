//Christopher Torralba		Section: B

#include "queue.h"
#include <iostream>
using namespace std;

class Robot
{
  private:
    string m_name;
    int m_numOfServices;
    ArrayQueue<int> m_services;
  public:
    Robot(){m_name=""; m_numOfServices = 0;};
    Robot(const string name, const int numServices,
    const ArrayQueue<int> Services)
    {
      m_name = name;
      m_numOfServices = numServices;
      m_services = Services;
    };
    bool isFinished() const {return m_services.isEmpty();}
    string getName() const {return m_name;}
    int getNumServices() const {return m_numOfServices;}
    int getServiceNumber() const {return m_services.front();}
    void clear(){m_services.clear();}
    void dequeueService(){m_services.dequeue();}
};

class ServiceStation
{
  private:
    int m_time;
    bool m_open;
    Robot m_robot;
  public: 
    ServiceStation(){};
    ServiceStation(const int & time)
    {
      m_time = time;
    };
    int getTime() const {return m_time;}
    void setRobot(const Robot x){m_robot=x;}
    Robot getRobot() const {return m_robot;}
    bool getIsOpen() const {return m_open;}
    void setIsOpen(const int x) {m_open = x;}
    void setTime(const int x) {m_time = x;}
};

int main()
{
  const int MEMWIPE_TIME = 9;
  const int PAINT_TIME = 18;
  const int METALWORK_TIME = 12;
  const int OILBATH_TIME = 4;
  ServiceStation m;
  Robot r;
  string name;
  ArrayQueue<int> services;
  ArrayQueue<Robot> robots;
  string robotRequest;
  int requestNum;
  int serviceNum;
  ServiceStation paint(PAINT_TIME), metalwork(METALWORK_TIME),
   oilbath(OILBATH_TIME), memwipe(MEMWIPE_TIME);
   int globalTime = 0;
  int paintDoneTime=1000;
  int metalworkDoneTime=1000;
  int memwipeDoneTime=1000;
  int oilbathDoneTime=1000;
  bool newloop;
  paint.setIsOpen(true);
  metalwork.setIsOpen(true);
  oilbath.setIsOpen(true);
  memwipe.setIsOpen(true);
  
  
  do
  {
    cin>>name;
    if(name != "$")
    {
      cin>>serviceNum;
      for (int k = 0; k < serviceNum; k++)
      {
        cin >> robotRequest;
        if(robotRequest == "paint")
        {
          requestNum = 1;
        }
        if(robotRequest == "metalwork")
        {
          requestNum = 2;
        }
        if(robotRequest == "oilbath")
        {
         requestNum = 3;
        }
        if(robotRequest == "memwipe")
        {
          requestNum = 4;
        }
        services.enqueue(requestNum);
      }
      Robot myRobot(name, serviceNum, services);
      robots.enqueue(myRobot);
      services.clear();
    }
  }while (name != "$");

  while(!robots.isEmpty() || !paint.getIsOpen() || !oilbath.getIsOpen() ||
        !memwipe.getIsOpen() || !metalwork.getIsOpen())
  {
  	newloop = false;
  	if (!robots.isEmpty())
  	{
  		r = robots.front();
  		if (r.getServiceNumber()==1)
  		{
  			m = paint;
  		}
  			if (r.getServiceNumber()==2)
  		{
  			m = metalwork;
  		}
  			if (r.getServiceNumber()==3)
  		{
  			m = oilbath;
  		}
  			if (r.getServiceNumber()==4)
  		{
  			m = memwipe;
  		}
  	}
  	
  	if (!robots.isEmpty()&&m.getIsOpen())
  	{
  		if (r.getServiceNumber()==1)
  		{
  			paint.setIsOpen(false);
  			r.dequeueService();
  			paint.setRobot(r);
  			robots.dequeue();
  			cout << "At time " << globalTime << " : " << r.getName();
  			cout << " gets: paint" << endl;
  			paintDoneTime = globalTime+paint.getTime();
  		}
  		else if (r.getServiceNumber()==2)
  		{
  			metalwork.setIsOpen(false);
  			r.dequeueService();
  			metalwork.setRobot(r);
  			robots.dequeue();
  			cout << "At time " << globalTime << " : " << r.getName();
  			cout << " gets: metalwork" << endl;
  			metalworkDoneTime = globalTime+metalwork.getTime();
  		}
  		else if (r.getServiceNumber()==3)
  		{
  			oilbath.setIsOpen(false);
  			r.dequeueService();
  			oilbath.setRobot(r);
  			robots.dequeue();
  			cout << "At time " << globalTime << " : " << r.getName();
  			cout << " gets: oilbath" << endl;
  			oilbathDoneTime = globalTime+oilbath.getTime();
  		}
  		else if (r.getServiceNumber()==4)
  		{
  			memwipe.setIsOpen(false);
  			r.dequeueService();
  			r.clear();
  			memwipe.setRobot(r);
  			robots.dequeue();
  			cout << "At time " << globalTime << " : " << r.getName();
  			cout << " gets: memwipe" << endl;
  			memwipeDoneTime = globalTime+memwipe.getTime();
  		}
  	}
  	else
  	{
  		if (paintDoneTime<=metalworkDoneTime && paintDoneTime<=oilbathDoneTime
  				&& paintDoneTime<=memwipeDoneTime && !paint.getIsOpen() && !newloop)
  		{
  			newloop = true;
  			globalTime = paintDoneTime;
  			paint.setIsOpen(true);
  			if(paint.getRobot().isFinished()>0&&paint.getIsOpen())
  			{
  				cout << "At time " << globalTime << " : " << paint.getRobot().getName()
  						 << " is done! " << endl;
  		  }
  		  if (paint.getRobot().isFinished()==0&&paint.getIsOpen())
  		  {
  		  	robots.enqueue(paint.getRobot());
  				cout << "At time " << globalTime << " : " << paint.getRobot().getName()
  						 << " gets back in line for: " ;
  				if (paint.getRobot().getServiceNumber()==1)
  				{
  					cout << "paint." << endl;
  				}
  				if (paint.getRobot().getServiceNumber()==2)
  				{
  					cout << "metalwork." << endl;
  				}
  				if (paint.getRobot().getServiceNumber()==3)
  				{
  					cout << "oilbath." << endl;
  			  }
  				if (paint.getRobot().getServiceNumber()==4)
  				{
  					cout << "memwipe." << endl;
  				}
  			}
  			paintDoneTime=10000;
  		}
  		else if (metalworkDoneTime<=paintDoneTime && metalworkDoneTime<=oilbathDoneTime
  				&& metalworkDoneTime<=memwipeDoneTime && !metalwork.getIsOpen()
					&& !newloop)
  		{
  			newloop = true;
  			globalTime = metalworkDoneTime;
  			metalwork.setIsOpen(true);
  			if(metalwork.getRobot().isFinished()>0&&metalwork.getIsOpen())
  			{
  				cout << "At time " << globalTime << " : " << metalwork.getRobot().getName()
  						 << " is done! " << endl;
  		  }
  		  if (metalwork.getRobot().isFinished()==0&&metalwork.getIsOpen())
  		  {
  		  	robots.enqueue(metalwork.getRobot());
  				cout << "At time " << globalTime << " : " <<
								 metalwork.getRobot().getName()
  						 << " gets back in line for: " ;
  				if (metalwork.getRobot().getServiceNumber()==1)
  				{
  					cout << "paint." << endl;
  				}
  				if (metalwork.getRobot().getServiceNumber()==2)
  				{
  					cout << "metalwork." << endl;
  				}
  				if (metalwork.getRobot().getServiceNumber()==3)
  				{
  					cout << "oilbath." << endl;
  			  }
  				if (metalwork.getRobot().getServiceNumber()==4)
  				{
  					cout << "memwipe." << endl;
  				}
  			}
  			metalworkDoneTime=10000;
  		}
  		else if (oilbathDoneTime<=paintDoneTime && oilbathDoneTime<=metalworkDoneTime
  				&& oilbathDoneTime<=memwipeDoneTime && !oilbath.getIsOpen() && !newloop)
  		{
  			newloop = true;
  			globalTime = oilbathDoneTime;
  			oilbath.setIsOpen(true);
  			if(oilbath.getRobot().isFinished()>0&&oilbath.getIsOpen())
  			{
  				cout << "At time " << globalTime << " : " << oilbath.getRobot().getName()
  						 << " is done! " << endl;
  		  }
  		  if (oilbath.getRobot().isFinished()==0&&oilbath.getIsOpen())
  		  {
  		  	robots.enqueue(oilbath.getRobot());
  				cout << "At time " << globalTime << " : " << oilbath.getRobot().getName()
  						 << " gets back in line for: " ;
  				if (oilbath.getRobot().getServiceNumber()==1)
  				{
  					cout << "paint." << endl;
  				}
  				if (oilbath.getRobot().getServiceNumber()==2)
  				{
  					cout << "metalwork." << endl;
  				}
  				if (oilbath.getRobot().getServiceNumber()==3)
  				{
  					cout << "oilbath." << endl;
  			  }
  				if (oilbath.getRobot().getServiceNumber()==4)
  				{
  					cout << "memwipe." << endl;
  				}
  			}
  			oilbathDoneTime=10000;
  		}
  		else if (memwipeDoneTime<=paintDoneTime && memwipeDoneTime<=metalworkDoneTime
  				&& memwipeDoneTime<=oilbathDoneTime && !memwipe.getIsOpen() && !newloop)
  		{
  			newloop = true;
  			globalTime = memwipeDoneTime;
  			memwipe.setIsOpen(true);
  			if(memwipe.getRobot().isFinished()>0&&memwipe.getIsOpen())
  			{
  				cout << "At time " << globalTime << " : " << memwipe.getRobot().getName()
  						 << " is done! " << endl;
  		  }
  		  if (memwipe.getRobot().isFinished()==0&&memwipe.getIsOpen())
  		  {
  		  	robots.enqueue(memwipe.getRobot());
  				cout << "At time " << globalTime << " : " << memwipe.getRobot().getName()
  						 << " gets back in line for: " ;
  				if (memwipe.getRobot().getServiceNumber()==1)
  				{
  					cout << "paint." << endl;
  				}
  				if (memwipe.getRobot().getServiceNumber()==2)
  				{
  					cout << "metalwork." << endl;
  				}
  				if (memwipe.getRobot().getServiceNumber()==3)
  				{
  					cout << "oilbath." << endl;
  			  }
  				if (memwipe.getRobot().getServiceNumber()==4)
  				{
  					cout << "memwipe." << endl;
  				}
  			}
  			memwipeDoneTime=10000;
  		}
  	}
  }
  robots.clear();
  return 0;
}
