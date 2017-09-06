

#include "ListLinked.h"
#include <stdexcept>
#include <iostream>

using namespace std;

template <typename DataType>

List<DataType>::List(int ignored)
{
	head = NULL;
	cursor = NULL;
}

template <typename DataType>	
List<DataType>::List(const List& other)    
{
	if(other.head == NULL)
	{
		head = NULL;
		cursor = NULL;
		return;
	}

	head = new ListNode(other.head->dataItem, NULL);
	cursor = head;
	ListNode* temp = head;
	ListNode* tempOther = other.head->next;
	
	for(; tempOther != NULL; tempOther = tempOther->next)
	{
		temp->next = new ListNode(tempOther->dataItem,NULL);
		temp = temp->next;
	}
	tempOther = other.head;
	while(tempOther != other.cursor)
	{
		tempOther = tempOther->next;
		cursor = cursor->next;
	}
	return;
			
}

template <typename DataType>
List<DataType>& List<DataType>:: operator=(const List& other)
{
	if(this == &other) 
	{
		return *this;
	}
	
	this->clear();
	if(other.head == NULL)
	{
		return *this;
	}

	head = new ListNode(other->head->dataItem, NULL);
	cursor = head;
	ListNode* temp = head;
	ListNode* tempOther = other->head->next;
	
	for(; tempOther != NULL; tempOther = tempOther->next)
	{
		temp->next = new ListNode(tempOther->dataItem,NULL);
		temp = temp->next;
	}
	tempOther = other->head;
	for(int i = 0; tempOther != other->cursor; i++)
	{
		tempOther = tempOther->next;
		cursor = cursor->next;
	}
	return *this;
	
}

template <typename DataType>
List<DataType>::~List()
{
	cursor = head;
	ListNode* temp = cursor;
	while(cursor != NULL)
	{
		temp = temp->next;
		delete cursor;
		cursor = temp;
	}
	head = NULL;
}

template <typename DataType>
void List<DataType>::insert(const DataType& newDataItem) throw (logic_error)
{
	if(head == NULL)
	{
		head = new ListNode(newDataItem, NULL);
		cursor = head;
		return;
	}
	
	cursor->next = new ListNode(newDataItem, cursor->next);
	cursor = cursor->next;
	
	
}

template <typename DataType>
void List<DataType>::remove() throw (logic_error)
{
	//one node
	if(head->next == NULL)
	{
		delete head;
		head = NULL;
		cursor = NULL;
		return;
	}
	ListNode* temp = cursor->next;
	//deleting head
	if(cursor == head)
	{
		head = head->next;
	}
	//linking nodes
	else
	{
		ListNode* temp2 = head;
		while(temp2->next != cursor)
		{
			temp2 = temp2->next;
		}
		temp2->next = cursor->next;
	}
	
	delete cursor; 
	//end of list    
	if(temp == NULL)
	{
		cursor = head;
	}
	//middle of list
	else
	{
		cursor = temp;
	}
	
}

template <typename DataType>
void List<DataType>::replace(const DataType& newDataItem) throw (logic_error)
{
	cursor->dataItem = newDataItem;
}

template <typename DataType>
void List<DataType>::clear()
{
	cursor = head;
	ListNode* temp = head;
	while(temp != NULL)
	{
		cursor = cursor->next;
		delete temp;
		temp = cursor;
	}
	head = NULL;
			
}

template <typename DataType>
bool List<DataType>::isEmpty() const
{
	if(head == NULL)
	{ 
		return true;
	}
	else
	{
		return false;
	}
}

template <typename DataType>
bool List<DataType>::isFull() const
{
	return false;
}

template <typename DataType>
void List<DataType>::gotoBeginning() throw (logic_error)
{
	cursor = head;
}

template <typename DataType>
void List<DataType>::gotoEnd() throw (logic_error)
{
	while(cursor->next != NULL)
	{
		cursor = cursor->next;
	}
}

template <typename DataType>
bool List<DataType>::gotoNext() throw (logic_error)
{
	if(cursor->next == NULL)
	{
		return false;
	}
	else
	{
		cursor = cursor->next;
		return true;
	}
}

template <typename DataType>
bool List<DataType>::gotoPrior() throw (logic_error)
{
	if(cursor == head)
	{
		return false;
	}
	ListNode* temp = head;
	while(temp->next != cursor)
	{
		temp = temp->next;
	}
	cursor = temp;
	return true;
	
}

template <typename DataType>
DataType List<DataType>::getCursor() const throw (logic_error)
{
	return cursor->dataItem;
}

template <typename DataType>
void List<DataType>::moveToBeginning () throw (logic_error)
{
	if(head == NULL)
	{
		return;
	}
	if(head == cursor)
	{
		return;
	}
	head = new ListNode(cursor->dataItem, head);
	remove();
	cursor = head;
}

template <typename DataType>
void List<DataType>::insertBefore(const DataType& newDataItem) throw (logic_error)
{
}

//Source code: show5.cpp 
//Publisher: Jones and Bartlet learning; 3 edition (March 7, 2008) 
template <typename DataType>
void List<DataType>::showStructure() const

// Outputs the items in a list. If the list is empty, outputs
// "Empty list". This operation is intended for testing and
// debugging purposes only.

{
    if ( isEmpty() )
    {
       cout << "Empty list" << endl;
    } 
    else
    {
	for (ListNode* temp = head; temp != 0; temp = temp->next) {
	    if (temp == cursor) {
		cout << "[";
	    }

	    // Assumes that dataItem can be printed via << because
	    // is is either primitive or operator<< is overloaded.
	    cout << temp->dataItem;	

	    if (temp == cursor) {
		cout << "]";
	    }
	    cout << " ";
	}
	cout << endl;
    }
}

template <typename DataType>
List<DataType>::ListNode::ListNode(const DataType& nodeData, ListNode* nextPtr)
{
	dataItem = nodeData;
	next = nextPtr;
}




