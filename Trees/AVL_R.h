#ifndef AVL_H
#define AVL_H

#include <fstream>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

template <class T>
class AVL
{
  // enum Status {OK, LEFT, RIGHT};
  friend istream& operator>>(istream &instream, AVL<T> &);
  friend ostream& operator<<(ostream &outstream, const AVL<T> &);
  
  public:
    // Constructor & Destructor
    AVL();
    //AVL(const AVL<T> &source);
    ~AVL();
    //bool BuildAVL(string Filename);
    void insert(T obj);
    // bool Remove(T target, T &result);
    // bool isEmpty();
  
  private:
    struct Node
    {
      T data = NULL;
      int height = 1;
      Node *left = NULL;
      Node *right = NULL;
      Node(T value) { data = value; }
    }; Node *root;
    
    int getBalance(Node*);
    int getHeight(Node*);
    void updateHeight(Node*);
    Node* insert(Node*, T);
    Node* rightRotate(Node*);
    Node* leftRotate(Node*);
};

// Interface for AVL Tree
void insert(T obj)
{
  root = insert(root,obj);
  return;
}

/*
  Recursive Helper function for Insert
*/
Node* insert(Node* node, T obj)
{
  // BST Insert (recursive)
  if (!node)
    return new Node(obj);
    
  if (obj < node->data)
    node->left = insert(node->left, obj);
  else if (obj >= node->data)
    node->right = insert(node->right, obj);
  else
    return node;
    
  // AVL Balancing
  updateHeight(node);
  
  int balance = getBalance(node);
  
  // Left-Left or Left-Right
  if (balance > 1)
  {
    if (obj > node->right->data)
      node = rightRotate(node);
    else
    {
      node->left = leftRotate(node->left);
      node = rightRotate(node);
    }
  }
  // Right-Right or Right-Left
  else if (balance < -1)
  {
    if (obj > node->right->data)
      node = leftRotate(node)
    else
    {
      node->right = rightRotate(node->right);
      node = leftRotate(node);
    }
  }
  return node;
}
int getBalance(Node* node)
{
	if (!node) return 0;

	return getHeight(node->left) - getHeight(node->right);
}
int getHeight(Node* node)
{
	if (!node)
		return 0;
	return node->height;
}
void updateHeight(Node* node)
{
	if (!node) return;
	if (getHeight(node->left) > getHeight(node->right))
		node->height = getHeight(node->left) + 1;
	else
		node->height = getHeight(node->right) + 1;

}
Node* rightRotate(Node* node)
{
  if (!node)
    return NULL;

  Node* beta = victim->right;  //Node* betaL = beta->left;
  
  //temp->right = NULL;
  victim->right = beta->left;
  beta->left = victim;
  return beta;
}
Node* leftRotate(Node* node)
{
  if (!node)
    return NULL;

  Node* beta = victim->left;  //Node* betaR = beta->right;
  
  //temp->left = NULL;
  victim->left = beta->right;
  beta->right = victim;
  return beta;
}
#endif