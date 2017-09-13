/* Christopher Torralba		File: robots.cpp
  Date: 3/3/16						Section: B
 */
 
 #include <iostream>
 #include <iomanip>
 #include "WelderRobot.h"
 #include "BenderRobot.h"
 #include "WrapperRobot.h"
 #include "AbstractRobot.h"
 
 using namespace std;
 
 int main()
 {
  float totalPay = 0;
  int numRobots;
  int typeRobot;
  
  string name;
  int firstArg, secondArg, thirdArg;
  
  cout.setf(ios_base::fixed,ios_base::floatfield);
  cout.precision(2);
  cin >> numRobots;
  
  for (int k = 0; k < numRobots; k++) 
  {
	  cin >> typeRobot;
	  switch (typeRobot)
	  {
	   case 0:
	   	{
		   	cin >> name;
		   	cin >> firstArg;
		   	cin >> secondArg;
		   	WrapperRobot x(name,firstArg,secondArg);
		   	cout << "#" << k << ": " << x.getName() << ", " << x. getType() << " $" << x.getPay() << endl;
		    totalPay = x.getPay() + totalPay;
		   	break;
		  }
	   case 1:
	   	{
		   	cin >> name;
		   	cin >> firstArg;
		   	cin >> secondArg;
		   	cin >> thirdArg;
		   	BenderRobot y(name,firstArg,secondArg, thirdArg);
		   	cout << "#" << k << ": " << y.getName() << ", " << y. getType() << " $" << y.getPay() << endl;
		    totalPay = y.getPay() + totalPay;
		   	break;
		   }
	   case 2:
	   	{
		   	cin >> name;
		   	cin >> firstArg;
		   	cin >> secondArg;
		   	cin >> thirdArg;
		   	WelderRobot z(name,firstArg,secondArg, thirdArg);
		   	cout << "#" << k << ": " << z.getName() << ", " << z. getType() << " $" << z.getPay() << endl;
		    totalPay = z.getPay() + totalPay;
	   	  break;
	     }
	   default: 
		   cout << "No Robot of that type" << endl;
	  }
  }
   cout << "TOTAL PAY = $" << totalPay << endl;
   cout << "AVERAGE PAY = $" << (totalPay/4) << endl;
   
   return 0;
 }
