//Christopher Torralba			File: Realbox.cpp
//Section B				Date: 2/12/2016
//HW 2

#include "realbox.h"
#include <iostream>
using namespace std;

//Default Constructor
RealBox::RealBox(int s, float a){
  if (s > 0) {
     m_reals = new float[s];
     for (int k = 0; k < s; k++){
       m_reals[k] = a;
     }
     m_boxsize = s;
  }
}

//Destructor
RealBox::~RealBox( ){
  delete [] m_reals;
}

//Operator =
const RealBox& RealBox::operator=(const RealBox& rhs){
  if (this != &rhs){
    if (m_boxsize != rhs.m_boxsize && m_boxsize != 0){
    delete [] m_reals;
    }
    m_boxsize = rhs.m_boxsize;
    m_reals = new float[m_boxsize];
    for (int k = 0; k < m_boxsize; k++)
    m_reals[k] = rhs.m_reals[k];
  }
  return (*this);
}

//Copy Constructor
RealBox::RealBox(const RealBox &rhs){
  m_boxsize = 0;
  *this = rhs;
}

//Accessor
void RealBox::set( int i, float x ){
  for (int k = 0; k < i; k++){
    m_reals[i] = x;
  }
}

//Printer
ostream& operator << (ostream& out, const RealBox& box){
  out << "[ ";
  for (int i = 0; i < box.m_boxsize; i++){
    out << box.m_reals[i] << ", ";
  }
  out << " ]";
  return (out);
}
