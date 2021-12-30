#include <iostream>
using namespace std;

//this class is only accessible with genericLinkedListStack class
//========================================================================

template<typename T>
class LinkedList;

template<typename T>
class Node 
{ 
private: 
	T data; 
	Node* link; 	
	friend class LinkedList<T>; 
};

template<typename T>
class LinkedList 
{ 
public: 
	Node<T>* head; 
	Node<T>* tail;

	LinkedList()
	{
		head=NULL; tail=NULL;
	}

	LinkedList(const LinkedList& other)
	{
		this->head=new Node<T>;
		this->head->data=other.head->data;
		this->head->link=NULL;
    	this->tail=this->head;
    	Node<T>* temp=other.head->link;
    	while (temp!=NULL)
    	{
        	this->addBack(temp->data);
        	temp=temp->link;
        }
	}

	bool empty() const
	{
		return (head==NULL);
	}

	const T& front() const
	{
		return head->data;
	}

	~LinkedList()
	{
		while (!empty()) 
			removeFront();
	}

	void addFront(const T& e)
	{
		Node<T>* v = new Node<T>;          // create new node
		v->data = e;                         // store data
    	v->link = head;                      // head now follows v
    	head = v;                            // v is now the head
		if (head->link==NULL)
			tail = head;
	}
	
	void addBack(const T& e)
	{
		Node<T>* v = new Node<T>;          // create new node
        v->data = e;
		v->link = NULL;                         // store data
        tail->link = v;                      // head now follows v
		tail = v;
	}

	void removeFront()
	{
		Node<T>* old = head;                // save current head
    	head = old->link;                    // skip over old head
    	delete old;
	}

	void print()
	{
		Node<T>* v = head;
    	while (v != NULL)
    	{
    		cout << v->data << " ";
    		v = v->link;
   		}
   		cout << endl;
	}

	int count()
	{
		Node<T>* v = head;
		int counter = 0;
        while (v != NULL)
        {
			counter++;
        	v = v->link;
        }
		return counter;
	} 
	
};