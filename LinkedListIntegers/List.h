#ifndef LIST_H
#define LIST_H

#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <cstdlib>
#include <vector>
using namespace std;

#include "ListNode.h"

template < typename NODETYPE >
class List
{
public:
	List()
		:firstPtr(nullptr), lastPtr(nullptr)
	{
		// Empty body
	}

	~List()
	{
		if (!isEmpty())
		{
			std::cout << "Destroying nodes....\n";
			ListNode<NODETYPE>* currentPtr = firstPtr;
			ListNode<NODETYPE>* tempPtr = nullptr;

			while (currentPtr != nullptr)
			{
				tempPtr = currentPtr;
				std::cout << tempPtr->data << "\n";
				currentPtr = currentPtr->nextPtr;
				delete tempPtr;
			}
		}

		std::cout << "All nodes destroyed\n\n";
	}


	void insertAtBack(const NODETYPE& value)
	{
		ListNode<NODETYPE>* newPtr = getNewNode(value);

		if (isEmpty())
		{
			firstPtr = lastPtr = newPtr;
		}
		else
		{
			lastPtr->nextPtr = newPtr;
			lastPtr = newPtr;
		}
	}

	bool isEmpty() const
	{
		return firstPtr == nullptr;
	}

	void print()
	{
		if (isEmpty())
		{
			std::cout << "The list is empty\n\n";
			return;
		}

		ListNode<NODETYPE>* currentPtr = firstPtr;

		std::cout << "The list is: ";
		while (currentPtr != nullptr)
		{
			std::cout << currentPtr->data << "->";
			currentPtr = currentPtr->nextPtr;
		}
		cout << "NULL";
		std::cout << "\n\n";
	}

	void deleteEvenNode()
	{
		ListNode<NODETYPE>* currentPtr = firstPtr;
		ListNode<NODETYPE>* deleteNode = nullptr;
		ListNode<NODETYPE>* temp = firstPtr;

		while (currentPtr != nullptr && currentPtr->data % 2 == 0)
		{
			deleteNode = firstPtr;
			firstPtr = firstPtr->nextPtr;
			free(deleteNode);
		}

		if (temp != nullptr)
		{
			while (temp->nextPtr != nullptr)
			{
				if (temp->nextPtr->data % 2 == 0)
				{
					deleteNode = temp->nextPtr;
					temp->nextPtr = temp->nextPtr->nextPtr;
					free(deleteNode);
				}
				else
				{
					temp = temp->nextPtr;
				}
				
			}
		}
	}

	void set_first_ptr(ListNode<NODETYPE>* const first_ptr);
	ListNode<NODETYPE>* first_ptr() const;
	ListNode<NODETYPE>* last_ptr() const;
private:
	ListNode< NODETYPE >* firstPtr;
	ListNode< NODETYPE >* lastPtr;
	vector<NODETYPE> listToVector;

	// utility function to allocate new node
	ListNode< NODETYPE >* getNewNode(const NODETYPE& value)
	{
		return new ListNode<NODETYPE>(value);
	}

};

template <typename NODETYPE>
void List<NODETYPE>::set_first_ptr(ListNode<NODETYPE>* const first_ptr)
{
	firstPtr = first_ptr;
}

template <typename NODETYPE>
ListNode<NODETYPE>* List<NODETYPE>::first_ptr() const
{
	return firstPtr;
}

template <typename NODETYPE>
ListNode<NODETYPE>* List<NODETYPE>::last_ptr() const
{
	return lastPtr;
}

#endif

