//****************************************************************************
/*
Author: Christopher Leipfert
Date: 4/19/2015
Project: Doubly Linked Recursive List
Filename: TestClient.cpp
Purpose: 
		To test the functionallity various methods for 
		the OrdList doubly linked list to ensure that the methods
		function as the should

Input: 
	N/A

Processing: 
		Test various methods for the OrdList doubly linked list

Output: 
		Outputs what is in the list and weither or certain keys were added
		and deleted

Assumptions:  
		N/A

Exception Handling: 
			Catches exceptions such as: 
								DuplicateKeyException
								OutOfMemoryException
								KeyNotThereException
								bad_alloc
*/
//****************************************************************************

// Included libraries
#include "OrdList.h"	// For the OrdListClass object.
#include "ItemType.h"	// For the ItemType struct and KeyType definition.
#include <iostream>		// For outputting the results of operations to the screen.

using namespace std;

//****************************************************************************

void main()
{
	OrdListClass my, your, their;	//Instantiates class objects my, your, and their


	ItemType testItem;		//Used for inserting of items into the list

	try
	{
		if (my.IsEmpty())
		{
			//Test the IsEmpty helper method.
			cout << "The List is empty!!!" << endl;
		}
		
		if (!my.IsFull())
		{
			//Test the IsFull helper method.
			cout << "The List is not full!" << endl;
		}

		for (int i = 1; i <= 10; i++)
		{
			//Runs through 0-9 and inserts i+10 into my
			testItem.key = i + 10;
			my.Insert(testItem);
			cout << "Item " << testItem.key << " Inserted" << endl;
		}

		your = my;
		//test the operator= method.

		system("pause");
		system("cls");
		//Pauses screen and waits for confirmation to continue

		//Prints my in order then in reverse order
		cout << "my contains: " << endl;
		my.Print();

		cout << "my contains in reverse: " << endl;
		my.PrintReverse();

		system("pause");
		system("cls");
		//Pauses screen and waits for confirmation to continue

		//Prints your in order then in reverse order
		cout << "your contains: " << endl;
		your.Print();

		cout << "your contains in reverse: " << endl;
		your.PrintReverse();

		system("pause");
		system("cls");
		//Pauses screen and waits for confirmation to continue

		testItem = my.Retrieve(15);

		cout << testItem.key << " retrieved" << endl;
		//Test the retrieve method and outputs what is retrieved

		my.Delete(testItem.key);
		cout << "Item " << testItem.key << " deleted" << endl;
		//Test the delete method and outputs that it was deleted

		system("pause");
		system("cls");
		//Pauses screen and waits for confirmation to continue

		their = my;

		cout << "their contains: " << endl;

		their.Print();

		their.Clear();
		cout << "After using clear their contains: " << endl;
		their.Print();
		//Test clear amd ouputs what is now not in the list

		//Following block test inputing random numbers given 
		//in a random order
		//then prints the list
		testItem.key = 22;
		their.Insert(testItem);

		testItem.key = 25;
		their.Insert(testItem);

		testItem.key = 10;
		their.Insert(testItem);

		testItem.key = 34;
		their.Insert(testItem);

		testItem.key = 100;
		their.Insert(testItem);

		cout << "their now contains: " << endl;
		their.Print();
	}
	catch (OutOfMemoryException)
	{
		//Accounts for out of mem exception
		cout << "Out of Memory!" << endl;
	}
	catch (DuplicateKeyException)
	{
		//Accounts for dup key exception
		cout << "Duplicate Key!" << endl;
	}
	catch (KeyNotThereException)
	{
		//Accounts for key not there exception

		cout << "Key Not There!" << endl;
	}
	catch (bad_alloc)
	{
		//Accounts for bad alloc exception

		cout << "Out of Memory!" << endl;
	}
} 
/*		OUPUT APPENDED
The List is empty!!!
The List is not full!
Item 10 Inserted
Item 11 Inserted
Item 12 Inserted
Item 13 Inserted
Item 14 Inserted
Item 15 Inserted
Item 16 Inserted
Item 17 Inserted
Item 18 Inserted
Item 19 Inserted
Press any key to continue . . .

my contains:
10
11
12
13
14
15
16
17
18
19
my contains in reverse:
19
18
17
16
15
14
13
12
11
10
Press any key to continue . . .

your contains:
10
11
12
13
14
15
16
17
18
19
your contains in reverse:
19
18
17
16
15
14
13
12
11
10
Press any key to continue . . .

15 retrieved
Item 15 deleted
Press any key to continue . . .

their contains:
10
11
12
13
14
16
17
18
19
After using clear their contains:
their now contains:
10
22
25
34
100
Press any key to continue . . .
*/