/*Christopher Torralba		File: arraylist.hpp
Section: B			Date: 2/22/2016
*/

#include <iostream>
using namespace std;

template <class T>
ArrayList <T> :: ArrayList(int s, const T& x)
{
  m_size = s;
  m_max = m_size * 2;
  if (m_size > 0)
  {
    m_data = new T[m_size];
    for (int k = 0; k < m_size; k++)
    {
      m_data[k] = x;
    }
  }
}
template <class T>
ArrayList<T>::~ArrayList(){
  delete [] m_data;
  m_size = 0;
  m_max = 0;
  m_data = NULL;
}

template <class T>
ArrayList<T>& ArrayList<T> :: operator = (const ArrayList<T>& rhs){
  if (this != &rhs)
  {
    delete [] m_data;
    m_size = rhs.m_size;
    m_data = new T[m_size];
    for (int k = 0; k < m_size; k++)
    {
      m_data[k] = rhs.m_data[k];
    }
  }
  return *this;
}

template <class T>
ArrayList<T>::ArrayList(const ArrayList<T> &cpy)
{
  m_data = new T[1];
  m_max = cpy.m_max;
  m_size = cpy.m_size;
  *this = cpy;
}

template <class T>
int ArrayList<T>::size()const
{
  return m_size;
}

template <class T>
const T& ArrayList<T>::first() const
{
  if (m_size > 0)
  {
    return m_data[0];
  }
  else
  {
    cout<<"!-- ERROR : PANIC in ARRAYLIST!! List empty, no first."<<endl;
    return m_errobj;
  }
}

template <class T>
T& ArrayList<T>::operator[](int i)
{
  if (i<m_size && m_size>0)
  {
    return m_data[i];
  }
  else
  {
    if (i>m_size)
    {
      cout<<"!-- ERROR : PANIC in ARRAYLIST!!";
      cout<<" For writable [] i is not in range of the list "<<endl;
      return m_errobj;
    }
    if (m_size == 0)
    {
      cout<<"!-- ERROR : PANIC in ARRAYLIST!!";
      cout<<" For writable [] the list is empty"<<endl;
      return m_errobj;
    }
    return m_errobj;
  }
}

template <class T>
const T& ArrayList<T>::operator[](int i)const
{
  if (i<m_size && m_size>0)
  {
    return m_data[i];
  }
  else
  {
    if (i>m_size)
    {
      cout<<"!-- ERROR : PANIC in ARRAYLIST!!";
      cout<<" For readable [] i is not in range of the list "<<endl;
      return m_errobj;
    }
    if (m_size == 0)
    {
      cout<<"!-- ERROR : PANIC in ARRAYLIST!!";
      cout<<" For readable [] the list is empty"<<endl;
      return m_errobj;
    }
    return m_errobj;
  }
}

template <class T>
int ArrayList<T>::find(const T& x) const
{
  if (m_size > 0)
  {
    int pos = 0;
    while (pos < m_size && m_data[pos] != x)
    {
      pos++;
    }
    if (m_data[pos] == x)
    {
      return (pos);
    }
    else
    {
      return (-1);
    }
  }
  else
  {
    cout<<"!-- ERROR : PANIC in ARRAYLIST!!"<<endl;
    cout<<"Can't find using an empty list"<<endl;
    return (-1);
  }
}

template <class T>
void ArrayList<T>::clear()
{
  delete [] m_data;
  m_max = 0;
  m_size = 0;
  m_data = NULL;
  return;
}

template <class T>
void ArrayList<T>::insert_back(const T& x)
{
  T*tmp;
  if(m_max == 0 && m_max==m_size) 
  {
    m_max++;
    tmp = new T[m_max*2];
    m_max = m_max*2;
    for(int k = 0; k < m_size; k++)
    {
      tmp[k] = m_data[k];
    }
    delete [] m_data;  
    m_data = tmp;
    m_data[m_size] = x;
    m_size++;
  }
  else if(m_max==m_size&&m_max!=0)
  { 
    tmp = new T[m_max*2];
    m_max = m_max*2;
    for(int k = 0; k < m_size; k++)
    {
      tmp[k] = m_data[k];
    }
    delete [] m_data;  
    m_data = tmp;
    m_data[m_size] = x;
    m_size++;
  }
  else
  {  
    m_data[m_size]=x;
    m_size++;
  } 
  return;
}

template <class T>
void ArrayList<T>::insert(const T& x, int i)
{
  if (0 < m_size && i <= m_size)
  {
    if (m_size == m_max)
    {
      T*tmp = new T[m_max * 2];
      m_max *= 2;
      for (int k = 0; k<m_size; k++)
      {
	tmp[k] = m_data[k];
      }
      delete [] m_data;
      m_data = tmp;
    }
    for (int k = m_size; k>i; k--)
    {
      m_data[k] = m_data[k-1];
    }
    m_data[i] = x;
    m_size++;
  }
  else
  {
    if(m_size == 0)
    {
     cout<<"!-- ERROR : PANIC in ARRAYLIST!!";
     cout<<" Can't insert when list is empty" <<endl;
    }
    else
    {
      cout<<"!-- ERROR : PANIC in ARRAYLIST!!";
      cout<< " " << i << " is not in range of the list "<<endl;
    }
  }
  return;
}

template <class T>
void ArrayList<T>::remove(int i)
{
  T*tmp;
  if(m_size>0&&i<=m_size)
  {
    if(m_size<(m_max/4))
    {
      tmp=new T[m_max/2];
      m_max=m_max/2;
      for(int k=0; k<m_size; k++)
      {
        tmp[k] = m_data[k];
      }
      	  
      delete[] m_data;
      m_data=tmp;
      for(int k=i; k<m_size-1; k++)
      {
        m_data[k] = m_data[k+1];
      }		
    }
    else
    {
      for(int k=i; k<m_size-1; k++)
      {
        m_data[k]=m_data[k+1];	
      }	
    }
    m_size--;
  }
  else
  {
    if(m_size == 0)
    {
      cout<<"!-- ERROR : PANIC in ARRAYLIST!!";
      cout<<" Can't remove when list is empty" <<endl;
    }
    else
    {
      cout<<"!-- ERROR : PANIC in ARRAYLIST!!";
      cout<<" Can't remove: " << i << " is not in the range of list" << endl;
    }
  }
  return;
}

template <class T>
void ArrayList<T>::swap(int i, int k)
{
  if(0 < m_size && k <= m_size && i <= m_size)
  {
    T tmp;
    tmp = m_data[k];
    m_data[k] = m_data [i];
    m_data[i] = tmp;
    return;
  }
  else
  {
    if(m_size == 0)
    {
      cout<<"!-- ERROR : PANIC in ARRAYLIST!!";
      cout<<"Can't swap when list is empty" <<endl;
    }
    else if (!(k < m_size && k >= 0))
    {
      cout<<"!-- ERROR : PANIC in ARRAYLIST!!";
      cout<<" Position " << k << " is out of range, cant swap "<<endl;
    }
    else if (!(i < m_size && i >= 0))
    {
      cout<<"!-- ERROR : PANIC in ARRAYLIST!!";
      cout<<" Position " << i << " is out of range, can't swap "<<endl;
    }
  }
}

template <class T>
void ArrayList<T>::resize(int s, const T& x)
{
  if (s < m_size)
  {
    T*tmp = new T[s];
    m_max = s;
    m_size = s;
    for (int k = 0; k<m_size; k++)
    {
      tmp[k] = m_data[k];
    }
    delete [] m_data;
    m_data = tmp;
  }
  if (s > m_size)
  {
    T*tmp = new T[s];
    m_max = s;
    for (int k = 0; k<m_size; k++)
    {
      tmp[k] = m_data[k];
    }
    delete [] m_data;
    m_data = tmp;
  }
  for (int k = m_size; k < m_max; k++)
  {
    m_data [k] = x;
  }
  m_size = s;
  return;
}

template <class T>
void ArrayList<T>::append(const ArrayList<T> &alist)
{
  T*tmp;
  int firstData=0;
  int secondData=0;
  if(m_size>0)
  {
    if(m_size<m_max+alist.m_max)
    {
      tmp = new T[m_max+alist.m_max];
      while(firstData<m_size)
      {
        tmp[firstData] = m_data[firstData];
        firstData++;
      }
      while(secondData < alist.m_size)
      {
        tmp[firstData+secondData] = alist.m_data[secondData];
        secondData++;
      }
      delete[]m_data;
      m_data=tmp;
    }
    m_size = m_size + alist.m_size;
  }
  else if(m_size==0)
  {
	  cout<<"!-- ERROR : PANIC in ARRAYLIST!!.append()";
	  cout<<" Can't append: empty list"<<endl;
  }
  return;
}
