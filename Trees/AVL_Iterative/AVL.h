#ifndef AVL_H
#define AVL_H

#include "RStack.h"

//#include <fstream>
#include <iostream>
//#include <algorithm>
//#include <string>
using namespace std;

template <typename T>
class AVL
{
  public:
    AVL() { root = NULL; cout << "Constructor" << endl;}
    ~AVL() { cout << "Deconstructor" << endl;}
    void insert(T*);
    // bool remove(T& target, T* result);
  private:
    // AVL Helper Functions
    void insert(Node*,T*);
    Node* rightRotate(Node*);
    Node* leftRotate(Node*); 
  
    struct Node
    {
      T* data = NULL;
      int height = 0;
      Node* left = NULL;
      Node* right = NULL;
      Node(T* value) { data = value; }
    }; Node* root;

    // Helper Functions
    int getBalance(Node*) const;
    int getHeight(Node*) const;
    Node* updateHeight(Node*) const;
};

// Interface insert
void AVL<T>::insert(T* value)
{
  cout << "Inserting: " << *value << endl;
  if (root)
  {
    insert(root,value);
    return;
  }
  root = new Node(value);
}

// Helper function for insert
AVL<T>::Node* AVL<T>::insert(AVL<T>::Node* curr, T* value)
{
  RStack<T> backLine;
  
  // Iterative Traverse LRN
  while(curr)
  {
    backLine.push(curr);
    if(*curr->data < *value)
      curr = curr->left;
    else
      curr = curr->right;
  }
  // Insertion
  curr = backLine.pop();
  if (*curr->data < *value)
    curr->left = new Node(value);
  else
    curr->right = new Node(value);
    
  // Balancing
  /*
  do{
    updateHeight(curr);
    int balance = getBalance(curr);
    
    if (balance > 1)
    {
      if (*value > *curr->right->data)
        curr = rightRotate(curr);
      else
      {
        curr->left = leftRotate(curr->left);
        curr = rightRotate(curr);
      }
    }
    else if (balance < -1)
    {
      if (*value > *curr->right->data)
        curr = leftRotate(curr);
      else
      {
        curr->right = rightRotate(curr->right);
        curr = leftRotate(curr);
      }
    }
  curr = backLine.pop();
  } while(backLine__CONDITION); 
  */
}

AVL<T>::Node* AVL<T>::rightRotate(AVL<T>::Node* victim)
{
  if (!victim)
    return NULL;

  Node* beta = victim->right;  //Node* betaL = beta->left;
  
  //temp->right = NULL;
  victim->right = beta->left;
  beta->left = victim;
  return beta;
}

AVL<T>::Node* AVL<T>::leftRotate(AVL<T>::Node* victim)
{
  if (!victim)
    return NULL;

  Node* beta = victim->left;  //Node* betaR = beta->right;
  
  //temp->left = NULL;
  victim->left = beta->right;
  beta->right = victim;
  return beta;
}

//------------Helper Functions-------------------------//
int AVL<T>::getBalance(AVL<T>::Node* node) const
{
  if (!node)
    return 0;
  return getHeight(node->left) - getHeight(node->right);
}

int AVL<T>::getHeight(AVL<T>::Node* node) const
{
  if (!node)
    return 0;
  return node->height;
}

void AVL<T>::updateHeight(AVL<T>::Node* node) const
{
  if (!node)
    return;

	if (getHeight(node->left) > getHeight(node->right))
		node->height = getHeight(node->left) + 1;
	else
		node->height = getHeight(node->right) + 1;
}
#endif