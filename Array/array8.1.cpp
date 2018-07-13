#include <iostream>

/*

	Insert items into an Array [methods modified]

*/

using namespace std;

int size, filledTo;
int *arr;

void traversalAndInitialize(void)
{
	size = 10;
	arr = new int [size];

	for(int i=0; i<size; i++)
	{
		arr[i]=i;
	}

	for(int i=0; i<size; i+=2)
	{
		arr[i]=20;
	}

	filledTo = size-1;

}

void makeSpaceAt(int index)
{
	for(int i = filledTo+1; i>index; i--)
	{
		arr[i]= arr[i-1];
	}
		filledTo++;
}

bool boundaryCheck(int index)
{
	if(index <0 || index > filledTo+1) return false;
	else return true;
}

bool isItFull()
{
	if(filledTo == size-1) return true;
	else return false;
}

void enlargeArray(void)
{
	int newSize = size*2;
	int *newArr = new int [newSize];

	for(int i=0; i<=filledTo; i++)
	{
		newArr[i]= arr[i];
	}

	delete [] arr;
	arr = newArr;

	size = newSize;
}



bool insertAtTheBeginning(int itemToBeInserted)
{
	if(isItFull()) enlargeArray();
	makeSpaceAt(0);
	arr[0] = itemToBeInserted;
	return true;
}

bool insertAtTheEnd(int itemToBeInserted)
{
	if(isItFull()) enlargeArray();
	filledTo++;
	arr[filledTo] = itemToBeInserted;
	return true;
}

bool insertAtIndexPOsition(int itemToBeInserted, int index)
{
	if(!boundaryCheck(index))
	{
		cout << "Moja los?" << endl;
		return false;
	}

	if(isItFull()) enlargeArray();

	if(index <= filledTo)
	{
		makeSpaceAt(index);
	}
	else
	{
		filledTo++;
	}
	arr[index] = itemToBeInserted;
	return true;
}


int search(int item)
{
	for(int i=0; i<=filledTo; i++)
	{
		if(arr[i]==item) return i;
	}
	return -1;
}

bool insertBeforeValue (int itemToBeInserted, int beforeValue)
{
	int index = search(beforeValue);
	return insertAtIndexPOsition(itemToBeInserted, index);

}

bool insertAfterValue (int itemToBeInserted, int afterValue)
{
	int index = search(afterValue);
	//-2 use korte paren
	if(index != -1)
	{
		return insertAtIndexPOsition(itemToBeInserted, index+1);
	}
	else
	{
		cout << "Moja loss?" << endl;
		return false;
	}
}



void printArray()
{
	cout << "Printing" << endl;
	for(int i=0; i<=filledTo; i++)
	{
		cout << arr[i] << "\t";
	}
	cout << endl <<"Size " << size << " FilledTo " << filledTo << endl;
}


int main (void)
{
	traversalAndInitialize();

	printArray();

	int itemToBeInserted = 100;
	int indexPOsitionForInsert = 2;
	int beforeValue = 17;
	int afterValue = 32;

	/*
	if(insertAtTheBeginning(itemToBeInserted))
		cout << "Inserted" << endl;
	else  cout << "Failed" << endl;
    */

	/*
	if(insertAtTheEnd(itemToBeInserted))
		cout << "Inserted" << endl;
	else  cout << "Failed" << endl;
    */

    /*
	if(insertAtIndexPOsition(itemToBeInserted, indexPOsitionForInsert))
		cout << "Inserted" << endl;
	else  cout << "Failed" << endl;
    */
    /*
	if(insertBeforeValue(itemToBeInserted, beforeValue))
		cout << "Inserted" << endl;
	else  cout << "Failed" << endl;
    */


	if(insertAfterValue(itemToBeInserted, afterValue))
		cout << "Inserted" << endl;
	else  cout << "Failed" << endl;


	printArray();
}
