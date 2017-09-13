//Christopher Torralba	Section: B
//Date: 4/18/2016				Hw:9 (mybstree.h)

#include "abstractbstree.h"
#ifndef MYBSTREE_H
#define MYBSTREE_H

template <typename T>
struct TreeNode
{
   T m_data;
   TreeNode* m_left;
   TreeNode* m_right;
};

template <class T>
class MyBSTree: public AbstractBSTree<T>
{
  private:
   TreeNode<T>* m_root;
   int m_size;
   
  public:
  //Big-3
    MyBSTree(){
    m_root = NULL;
    m_size = 0;
    }
    const MyBSTree<T>& operator=(const MyBSTree<T>& rhs);
    MyBSTree(const MyBSTree<T>& rhs);
    ~MyBSTree();
  //Accessor
    int size() const;
    bool isEmpty() const;
    int height() const;
    const T& findMax() const throw (Oops);
    const T& findMin() const throw (Oops);
    int find (const T& x) const;
  //Mutator
    void clear();
    void insert(const T& x);
    void remove(const T& x);
  //Output
    void printPreOrder() const;
    void printPostOrder() const;
    void print() const;
};

#include "Mybstree.hpp"
#endif
