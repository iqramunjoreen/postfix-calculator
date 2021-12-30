#include <iostream>
#include <string>
#include "StackExceptions.h"
#include "linkedList.h"
using namespace std;



//===========================================================================

template<typename T>                 //top is the head of the linked list
class genericLinkedListStack: public LinkedList<T>      //only top is accessible in this class
{
public:
  genericLinkedListStack()
  {
  	n=0;
  } 
                              
  int size() const
  {
  	return n;
  }
                             
  bool empty() const
  {
  	return (S.empty());
  }   

  const T& top() const throw(StackEmpty)
  {
  	if (empty()) 
     throw StackEmpty("Top of empty stack");
  	return S.front();
  } 

  void push(const T& e)
  {
  	++n;
  	S.addFront(e);
  }

  void pop() throw(StackEmpty)
  {
  	if (empty()) 
     throw StackEmpty("Top of empty stack");
 	--n;
  	S.removeFront();
  }

  void print()
  {
  	this->S.print();
  }
                 
private:                                       
  LinkedList<T> S;                        
  int n;  
};