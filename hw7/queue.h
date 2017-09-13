//Christopher Torralba	Section: B

#include "abstractqueue.h"
#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>
using namespace std;

template <class T>
class ArrayQueue:public AbstractQueue<T>
{
  private:
    int m_first;
    int m_last;
    int m_max;
    T*m_data;
  public:
    ArrayQueue():m_first(0),m_last(0),m_max(0),m_data(NULL){};
    bool isEmpty() const;
    const T& front() const throw (Oops);
    const T& back() const throw (Oops);
    void enqueue(const T& x);
    void dequeue();
    void clear();
    ArrayQueue<T>& operator = (const ArrayQueue<T>& rhs);
};

#include "queue.hpp"
#endif
