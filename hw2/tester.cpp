#include <iostream>
#include "realbox.h"

using namespace std;

int main () 
{
	cout << "RealBox Tester" << endl;
	
	cout << "#1" << endl;
	RealBox a(100,2.2);
	cout << a << endl;

	cout << "#2" << endl;
	RealBox b(4,3.14);
	cout << b << endl;
	
	cout << "#3" << endl;
	RealBox c(2 ,5.55);
	c.set( 5, 0.7 );
	cout << c << endl;
	
	cout << "#4" << endl;
	RealBox d(4,8.123);
	d.set( 3, 1.15 );
	cout << d << endl;

	cout << "#5 : Operator= Test" << endl;
	c = d;
	cout << d << endl;
	cout << c << endl;
	c.set( 5, 42.42 );
	cout << d << endl;
	cout << c << endl;
	
	cout << "#6 : Copy Constructor Test" << endl;
	RealBox e(a);
	cout << a << endl;
	cout << e << endl;
	e.set( 20, 88.123 );
	cout << a << endl;
	cout << e << endl;
	
  return 0;
}
