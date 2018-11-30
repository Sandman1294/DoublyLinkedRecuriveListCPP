//*************************************************************************************************
//										IMPLEMENTATION FILE
/*
Author: Luke Musto
Date: 04/10/2015
Modifications:
Mod Date:
Project: Doubly Linked Recursive List
Filename: OrdList.cpp
Purpose: This file contains the implementation of OrdList.
*/
//*************************************************************************************************

// Included Libraries
#include "OrdList.h"

//definition of forward declaration
struct node
{
	node* prev;			// Pointer to the previous node 
	ItemType data;		// Data stored
	node* next;			// Pointer to the next node 
}; // End node struct

// ------------------------------------------------------------------------------------------------
// |																							  |
// |								Constructors & Destructors									  |
// |																							  |
// ------------------------------------------------------------------------------------------------

		OrdListClass::OrdListClass()
		{
			head = nullptr;
			tail = nullptr;
		} // End Default Constructor

//*************************************************************************************************

		OrdListClass::~OrdListClass()
		{
			Clear();
		} // End Destructor

//*************************************************************************************************

		OrdListClass::OrdListClass(/*in*/ const OrdListClass& orig) // List to be copied.
		{
			head = nullptr;
			tail = nullptr;

			operator=(orig);
		} // End Copy Constructor

// ------------------------------------------------------------------------------------------------
// |																							  |
// |							Observer Predicators											  |
// |																							  |
// ------------------------------------------------------------------------------------------------

		bool OrdListClass::IsFull() const
		{
			return false;
		} // End IsFull()

//*************************************************************************************************

		bool OrdListClass::IsEmpty() const
		{
			return (head == nullptr);
		} // End IsEmpty()

// ------------------------------------------------------------------------------------------------
// |																							  |
// |										Mutators											  |
// |																							  |
// ------------------------------------------------------------------------------------------------

		void OrdListClass::Insert(/*in*/ ItemType newItem) // Item to be inserted.
		{
				rInsert(head, newItem);
		} // End Insert()

//*************************************************************************************************

		void OrdListClass::Delete(/*in*/ KeyType target) // Key of item to delete.
		{
			if(!IsEmpty())
				rDelete(head, target);
			else
				throw KeyNotThereException();
		} // End Delete()

//*************************************************************************************************

		void OrdListClass::Clear()
		{
			if(!IsEmpty())
				rClear(head);

			head = nullptr;
			tail = nullptr;
		} // End Clear()

// ------------------------------------------------------------------------------------------------
// |																							  |
// |									Observer Accessor										  |
// |																							  |
// ------------------------------------------------------------------------------------------------

		ItemType OrdListClass::Retrieve(/*in*/ KeyType target) const // Key of item to be returned.
		{
			// If the list isn't empty try to retrieve. Otherwise, throw an exception.
			if(!IsEmpty())
			{
				ItemType tbr;
				rRetrieve(head, tbr, target);
				return tbr;
			} // End not empty path.
			else
				throw KeyNotThereException();

			
		} // End Retrieve()

// ------------------------------------------------------------------------------------------------
// |																							  |
// |								Observer Summarizers/Printerators(lol)						 |
// |																							  |
// ------------------------------------------------------------------------------------------------

		void OrdListClass::Print() const
		{
			if(!IsEmpty())
				rPrint(head);
		} // End Print()

//*************************************************************************************************

		void OrdListClass::PrintReverse() const
		{
			if(!IsEmpty())
				rPrintRev(tail);
		} // End PrintReverse()

// ------------------------------------------------------------------------------------------------
// |																							  |
// |									Overloaded Operators									  |
// |																							  |
// ------------------------------------------------------------------------------------------------

		void OrdListClass::operator =(/*in*/ const OrdListClass& orig)	// List to be copied.
		{
			if (orig.IsEmpty())
			{
				//Orig is empty so you clear the list to set them equal.
				Clear();
			}
			else
			{
				//orig must not be empty
				for (node*temp = orig.head; temp != nullptr; temp = temp->next)
				{
					//goes through every element of the list and insets it into the
					//applying class
					Insert(temp->data);
				}
			}

		} // End operator=()
		

//*************************************************************************************************
		OrdListClass OrdListClass::operator +(/*in*/ const OrdListClass& rtOp) const // List to be added to applying object.
		{
			OrdListClass tbr;	//to be returned
			node* temp = head;	//temp for the applying list

			for (node* rtOpTemp = rtOp.head; rtOpTemp != nullptr; rtOpTemp = rtOpTemp->next)
			{
				if (rtOpTemp->data.key == temp->data.key)
				{
					//Inserts one if both the items are the same
					tbr.Insert(rtOpTemp->data);
				}
				else
				{
					//Inserts both if they arent the same
					tbr.Insert(rtOpTemp->data);
					tbr.Insert(temp->data);
				}
			}
			if (temp != nullptr)
			{
				while (temp!=nullptr)
				{//finishes going throught temp
					tbr.Insert(temp->data);
					temp = temp->next;
				}
			}

			return tbr;	//returns tbr
		}

	
//*************************************************************************************************
	
		OrdListClass OrdListClass::operator -(/*in*/ const OrdListClass& rtOp) const // List to be subtracted from applying object.
		{
			OrdListClass tbr;	//to be returned
			node* temp = head;	//temp for the applying list

			for (node* rtOpTemp = rtOp.head; rtOpTemp != nullptr; rtOpTemp = rtOpTemp->next)
			{
				if (rtOpTemp->data.key != temp->data.key)
				{
					//Inserts bot if both the items are not the same
					tbr.Insert(rtOpTemp->data);
					tbr.Insert(temp->data);
				}
			}
			if (temp != nullptr)
			{
				while (temp != nullptr)
				{//finishes going throught temp
					tbr.Insert(temp->data);
					temp = temp->next;
				}
			}

			return tbr;	//returns tbr

		}

//*************************************************************************************************

		
// ------------------------------------------------------------------------------------------------
// |																							  |
// |									Protected Methods										  |
// |																							  |
// ------------------------------------------------------------------------------------------------
		
		node* OrdListClass::Allocate()
		{
			// Try to allocate memory
			
			try
			{
				node* temp = new node;
		
				temp->next = nullptr;
				temp->prev = nullptr;
				return temp;
			}
			catch (std::bad_alloc)
			{
				throw OutOfMemoryException();
			}


		} // End Allocate()
		
// ------------------------------------------------------------------------------------------------
// |																							  |
// |									Recursive (Wrapped) Methods								  |
// |																							  |
// ------------------------------------------------------------------------------------------------

		void OrdListClass::rPrint(/*in*/ const node* trav) const // Pointer to traversal node 
		{
			if (trav!=nullptr)
			{
				//runs through the list and prints the item in acending order
				std::cout << trav->data.key << endl;
				rPrint(trav->next);
			}
		} // End rPrint()

//*************************************************************************************************

		void OrdListClass::rPrintRev(/*in*/ const node* trav) const // Pointer to traversal node 
		{
			if (trav != nullptr)
			{
				//runs through the list and prints the item in decending order
				std::cout << trav->data.key << endl;
				rPrintRev(trav->prev);
			}
		} // End rPrintRev()

//*************************************************************************************************

		void OrdListClass::rClear(/*in*/ node* trav) // Pointer to traversal node 
		{
			if (trav->next != nullptr)
			{
				//Delets everyitem in the list until
				//the very last element
				node* temp = trav;
				trav = trav->next;
				delete temp;
				rClear(trav);
			}
			else
			{
				//delets the last element
				node* temp = trav;
				delete temp;
			}
		} // End rClear()

//*************************************************************************************************

		void OrdListClass::rDelete(/*in*/ node* trav,			// Pointer to traversal node 
				 				   /*in*/ KeyType target)		// Target key to be deleted.
		{
			if (trav != nullptr)
			{
				if (trav->data.key == target)
				{
					//Checks to see if the target was found
					if (trav == head)
					{
						//accounts for if head is the target 
						//and adjust everything accordingly
						node*temp = trav;
						head = trav->next;
						head->prev = nullptr;
						delete temp;
					}
					else if (trav == tail)
					{
						//accounts for if tail is the target 
						//and adjust everything accordingly
						node*temp = trav;
						tail = trav->prev;
						tail->next = nullptr;
						delete temp;
					}
					else
					{
						//Target was found and it is not head nor tail
						//so its in the middle of the list.
						node * temp = trav;
						trav->next->prev = trav->prev;
						trav->prev->next = trav->next;
						delete temp;
					}
				}
				else
				{
					//Not found. Next position
					rDelete(trav->next, target);
				}
			}
			else
			{
				//if the key is not in the list
				//throws an exception
				throw KeyNotThereException();
			}
		} // End rDelete()

//****************************************************************************

		void OrdListClass::rInsert(/*in*/ node* trav,		//Pointer to traversal node 
								   /*in*/ ItemType newItem)	//Item to be inserted.
		{
			if (trav == nullptr)
			{
				//If the list is empty
				//inserts the element and
				//sets head and tail to 
				//point at it
				node*temp = Allocate();
				temp->data = newItem;
				head = temp;
				tail = temp;
			}
			else if (head == tail)
			{
				//test for if there is only one element in the list
				if (newItem.key < head->data.key)
				{
					//Inserts the item before head
					node*temp = Allocate();
					temp->data = newItem;
					head = temp;
					head->next = tail;
					tail->prev = head;
				}
				else
				{
					//Inserts the item after head
					node*temp = Allocate();
					temp->data = newItem;
					tail = temp;
					tail->prev = head;
					head->next = tail;
				}
			}
			else if (trav == tail)
			{
				//Test if the pointer if pointing at
				//tail and inserts it after tail
				node*temp = Allocate();
				tail = temp;
				tail->prev = trav;
				trav->next = tail;
				tail->data = newItem;
			}
			else if (trav->data.key == newItem.key)
			{
				//Keys are the same
				//throws exception
				throw DuplicateKeyException();
			}
			else if (newItem.key > trav->data.key)
			{
				//If the new key is greater than 
				//that in trav recalls rInsert
				rInsert(trav->next, newItem);
			}
			else if (newItem.key < trav->data.key)
			{
				//the new key is less that that in trav
				if (trav == head)
				{
					//Test if the item has to become the new
					//head
					node*temp = Allocate();
					head = temp;
					head->next = trav;
					head->data = newItem;
				}
				else
				{
					//insets the item right before trav
					node*temp = Allocate();
					trav->prev->next = temp;
					temp->prev = trav->prev;
					trav->prev = temp;
					temp->next = trav;
					temp->data = newItem;
				}
			}
		} // End rInsert()

//*************************************************************************************************

		void OrdListClass::rRetrieve(/*in*/ node* trav,					// Pointer to traversal node 
									 /*in/out*/ ItemType& tbr,			// Item to be returned.
									 /*in*/ KeyType target) const		// Requested key to be retrieved.
		{
			if (trav != nullptr)
			{
				if (trav->data.key == target)
				{
					//Item found, returns the item
					tbr = trav->data;
				}
				else
				{
					//not found, recalls rRetrieve
					rRetrieve(trav->next, tbr, target);
				}
			}
			else
			{
				//key not found.
				throw KeyNotThereException();
			}
		} // End rRetrieve()


