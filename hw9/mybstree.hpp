//Christopher Torralba	Section: B

//operator =
template<class T>
const MyBSTree<T>& MyBSTree<T> :: operator = (const MyBSTree<T>& rhs)
{
  if (this != &rhs)
  {
    clear();
    m_root = clone(rhs.m_root);
    m_size = rhs.m_size;
  }
  return *this;
}

//copy
template<class T>
MyBSTree<T>::MyBSTree(const MyBSTree<T>& rhs)
{
  m_root = clone(rhs.m_root);
  m_size = rhs.m_size;
}

//deconstructor
template <class T>
MyBSTree<T>::~MyBSTree(){
  clear();
}
//accessor
template <class T>
int MyBSTree<T>::size() const
{
  return m_size;
}

template <class T>
bool MyBSTree<T>::isEmpty() const
{
  if (m_root == NULL)
  {
    return true;
  }
  else
  {
    return false;
  }
}

template <class T>
int MyBSTree<T>::height() const
{
  return findHeight(m_root);
}

template <class T>
const T& MyBSTree<T>::findMax() const throw (Oops)
{
  if (!isEmpty())
  {
    return getMax(m_root);
  }
  else
  {
    throw Oops("OOPS! : Tree is Empty!!");
  }
}

template <class T>
const T& MyBSTree<T>::findMin() const throw (Oops)
{
  if(!isEmpty())
  {
    TreeNode<T>* find = m_root;
    while (find->m_left != NULL)
    {
      find = find->m_left;
    }
    return find->m_data;
  }
  else
  {
    throw Oops("OOPS! : Tree is Empty!!");
  }
}

template <class T>
int MyBSTree<T>::find(const T& x)const
{
  if (m_root == NULL)
  {
    return 0;
  }
  else
  {
    int max = height();
    int depth = 1;
    TreeNode<T>*tmp = m_root;
    for (int k = 0; k < max; k++)
    {
      if (x < tmp->m_data)
      {
        if (tmp->m_left != NULL)
  	{
  	  depth++;
  	  tmp = tmp->m_left;
  	}
      }	
      else if (x > tmp->m_data)
      {
        if (tmp->m_right != NULL)
  	{
  	  depth++;
  	  tmp = tmp->m_right;
  	}
      }
      else if (x == tmp->m_data)
      {
    	return depth;
      }
    }
    depth++;
    return (depth*-1);
  }
}

//mutators
template <class T>
void MyBSTree<T>::clear()
{
  m_size = 0;
  if(!isEmpty())
  {
    deepClear(m_root);
  }
  m_root = NULL;
  return;
}

template <class T>
void MyBSTree<T>::insert(const T& x)
{
  m_size++;
  insertNode(m_root, x);
}

template <class T>
void MyBSTree<T>::remove(const T& x)
{
  m_size--;
  removeNode(m_root,x);
}
//output

template <class T>
void MyBSTree<T>::printPreOrder() const
{
  preOrder(m_root);
  cout << endl;
  return;
}

template <class T>
void MyBSTree<T>::printPostOrder() const
{
  postOrder(m_root);
  cout << endl;
  return;
}

template <class T>
void MyBSTree<T>::print() const
{
  prettyPrint(m_root,0);
  return;
}
/***************End of In Class Functions************/
template <class T>
void prettyPrint (const TreeNode<T>* t, int pad)
{
 string s(pad, ' ');
 if (t == NULL)
     cout << endl;
 else{
   prettyPrint(t->m_right, pad+4);
   cout << s << t->m_data << endl;
   prettyPrint(t->m_left, pad+4);
 }  
}

template <class T>
void insertNode(TreeNode<T>* &t, const T& x)
{
  if(t==NULL)
  {
    t = new TreeNode<T>;
    t->m_data = x;
    t->m_left = NULL;
    t->m_right = NULL;
  }
  else
  {
    if (x<t->m_data)
    {
      insertNode(t->m_left, x);
    }
    else if (x>t->m_data)
    {
      insertNode(t->m_right, x);
    }
    else
    {
      return;
    }
  }
}

template <class T>
void removeNode(TreeNode<T>* &t, const T& x)
{
  if(t==NULL)
  {
    return;
  }
  else if (x < t->m_data)
  {
    removeNode(t->m_left,x);
  }
  else if (x > t->m_data)
  {
    removeNode(t->m_right,x);
  }
  else
  {
    if((t->m_left == NULL) && (t->m_right == NULL))
    {
      delete t;
      t = NULL;
    }
    else if((t->m_left == NULL) || (t->m_right == NULL))
    {
      TreeNode<T>*child = t->m_left;
      if (child == NULL)
      {
  	child = t->m_right;
      }
      delete t;
      t = child;
    }
    else
    {
    t->m_data = getMax(t->m_left);
    removeNode(t->m_left,t->m_data);
    }
  }
}

template <class T>
int findHeight(TreeNode<T>* t)
{
  if (t == NULL)
  {
    return 0;
  }
  else
  {
    int left = 1+findHeight(t->m_left);
    int right = 1+findHeight(t->m_right);
    return ((left>right)?left:right);
  }
}

template<class T>
const T& getMax(TreeNode<T>* t)
{
  TreeNode<T>*r = t;
  while (r->m_right != NULL)
  {
    r = r->m_right;
  }
  return r->m_data;
}

template <class T>
void preOrder(const TreeNode<T>* t)
{
  cout << t->m_data << " ";
  if (t->m_left != NULL)
  {
    preOrder(t->m_left);
  }
  if (t->m_right != NULL)
  {
    preOrder(t->m_right);
  }
}

template <class T>
void postOrder(const TreeNode<T>* t)
{
  if (t->m_left != NULL)
  {
    postOrder(t->m_left);
  }
  if (t->m_right != NULL)
  {
    postOrder(t->m_right);
  }
  cout << t->m_data << " ";
}

template <class T>
void deepClear(TreeNode<T>* t)
{
  if (t->m_left!=NULL)
  {
    deepClear(t->m_left);
  }
  if (t->m_right!=NULL)
  {
    deepClear(t->m_right);
  } 
  delete t;
}

template <class T>
TreeNode<T>* clone(const TreeNode<T>* t)
{
  TreeNode<T>* new_root;
  if (t == NULL)
  {
     return NULL;
  }
  else
  {
    new_root = new TreeNode<T>;
    new_root->m_data = t->m_data;
    new_root->m_left = clone(t->m_left);
    new_root->m_right = clone(t->m_right);
  }
  return new_root;
}
