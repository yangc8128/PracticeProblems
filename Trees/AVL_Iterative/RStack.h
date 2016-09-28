#ifndef RSTACK_H
#define RSTACK_H

#include <iostream>
using namespace std;

template <typename T>
class RStack
{
  public:
    // Constructor
    RStack<T>() {
      head = NULL;
      cout << "Constructor" << endl;
    }
    // Desconstructor
    ~RStack<T>() {
      cout << "Destructor" << endl;
      while(head)
        cout << *pop() << endl;
    } 
//---------FUNCTIONS---------------------//
    // Peek at head
    T* peek() const {
      if (!head)
        return NULL;
      return head->data;
    }
    // Insert into head
    void push(T* obj) {
      RNode *temp = new RNode(obj);
      temp->next = head;
      head = temp;
    }
    // Remove from head
    T* pop(){
      if (head){
        RNode *temp = head;
        T* retVal = temp->data;
        // Iterate        
        head = head->next;
        // Clean ptr
        delete temp; temp = NULL;
        return retVal;
      }
      return NULL;
    }
  private:
    struct RNode
    {
      T* data = NULL;
      RNode* next = NULL;
      RNode(T* value) {data = value;}
    }; RNode* head;
};
#endif
