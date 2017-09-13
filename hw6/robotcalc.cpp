/* Christopher Torralba		Section: B
   File: braincalc.cpp 		HW: 6
   3/10/2015														*/
	
  #include "abstractstack.h"
  #include <iostream>
  #include <cstdlib>
  #include <cstring>
  #include <string>
  #include <stdlib.h>
  #include <cctype>
  using namespace std;
	
  template <typename T>
  class ArrayStack;
	
  template <typename T>
  ostream& operator<< (ostream& out, const ArrayStack<T>& aStack);
  
  template <class T>
  class ArrayStack: public AbstractStack<T>
  {
    T* m_data;
    int m_top;
    int m_max;
			
    public:
      ArrayStack():AbstractStack<T>()
      {
	m_top = 0;
	m_max = 0;
      }
      ~ArrayStack()
      {
	delete [] m_data;
 	m_top = 0;
        m_max = 0;
	m_data = NULL;
      }
      virtual bool isEmpty() const
      {
 	if (m_top > 0)
 	{
          return false;
	}
	else
	{
	  return true;
	}
      }	
	
      const T& top() const throw ( Oops )
      {
	if (!(isEmpty()))
	{
          return m_data[m_top-1];
	}
	else
	{
	  throw Oops("Error = empty stack for top()");
	}
      }
   
      void push(const T& x)
      {
        T*tmp;
        if(m_max == m_top) 
        {
          if (m_max == 0)
  	  {
            m_max++;
          }
          tmp = new T[m_max*2];
          m_max = m_max*2;
          for(int k = 0; k < m_top; k++)
          {
            tmp[k] = m_data[k];
          }
          delete [] m_data;  
          m_data = tmp;
          m_data[m_top] = x;
          m_top++;
        }
        else
        {  
          m_data[m_top]=x;
          m_top++;
        } 
        return;
      }
  	
      void pop()
      {
 	if (!(isEmpty()))
          m_top--;
      }
      void clear()
      {
    	delete [] m_data;
   	m_max = 0;
   	m_top = 0;
   	m_data = NULL;
   	return;
      }
      int size() const
      {
        return m_top;
      }
      void mult ()
      {
   	if (m_top > 1)
   	{
          int result;
   	  result = m_data[m_top-1]*m_data[m_top-2];
   	  pop();
   	  pop();
   	  push(result);
   	}
   	else
   	{
   	  throw Oops("Error = Not enough numbers for mult");
   	}
   	return;
      }
      void operator ~ ()
      {
   	if (!(isEmpty()))
   	{
          int result;
   	  result = m_data[m_top-1]*-1;
   	  pop();
          push(result);
        }
   	else
   	{
   	  throw Oops("Error = empty stack for ~");
   	}
   	return;
      }
      void divide ()
      {
   	if (m_top > 1)
   	{
          int result;
   	  result = m_data[m_top-2]/m_data[m_top-1];
   	  pop();
   	  pop();
   	  push(result);
   	}
   	else
   	{
   	  throw Oops("Error = Not enough numbers for divide");
   	}
   	return;
      } 
      void add ()
      {
   	if (m_top > 1)
   	{
          int result;
   	  result = m_data[m_top-2]+m_data[m_top-1];
   	  pop();
   	  pop();
   	  push(result);
   	}
   	else
   	{
   	  throw Oops("Error = Not enough numbers for add");
   	}
   	return;
      } 
      void subtract ()
      {
   	if (m_top > 1)
   	{
          int result;
   	  result = m_data[m_top-2]-m_data[m_top-1];
   	  pop();
   	  pop();
   	  push(result);
   	}
   	else
   	{
   	  throw Oops("Error = Not enough numbers for subtract");
   	}
   	return;
      } 

      void mod ()
      {
   	if (m_top > 1)
   	{
          int result;
   	  result = m_data[m_top-2] % m_data[m_top-1];
   	  pop();
   	  pop();
   	  push(result);
   	}
   	else
   	{
   	  throw Oops("Error = Not enough numbers for mod");
   	}
   	return;
      } 
      void addAll()
      {
   	if (m_top > 1)
   	{
	  do
	  {
	    add();
	  }while (m_top > 1);
	}
        else
	  throw Oops("Error (add all) = empty stack");
      }
      void multAll()
      {
   	if (m_top > 1)
   	{
          do
	  {
	    mult();
	  }while (m_top > 1);
	}
	else
	   throw Oops("Error (mult all) = empty stack");
   }
   friend ostream& operator<< <> (ostream& out, 
                                      const ArrayStack<T>& aStack);
 };
 template <class T>
 ostream& operator<< (ostream& out, const ArrayStack<T>& aStack)
 {
   out << "[ ";
   for (int i=aStack.m_top-1; i >=0; i--)
   {
     out << aStack.m_data[i] << " ";
   } 
   out << "]";
   out << endl;
   return out;
 }

  int main ()
  {
    string input = "1";
    int a;
    ArrayStack<int> num;
    while (input != ".")
    {
      cin >> input;
      if (input != ".")
      {
        if (input == "!")
        {
          cout << num;
        }
        else if (input == "$")
        {
          num.clear();
        }
        else if (input == "~")
        {
          ~num;
        }
        else if (input == "/")
        {
          num.divide();
        }
        else if (input == "*")
        {
          num.mult();
	}
	else if (input == "-")
	{
	  num.subtract();
	}
	else if (input =="+")
	{
	  num.add();
	}
	else if (input == "%")
	{
	  num.mod();
	}
	else if (input == "S")
	{
	  num.addAll();
	}
	else if (input =="P")
	{
	  num.multAll();
	}
	else 
	{
	  a = atoi(input.c_str());
	  num.push(a);
	}
      }	
    }		
    return 0;
  }
