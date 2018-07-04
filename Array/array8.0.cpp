#include <iostream>

/*
 Delete from Array [methods modified]

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

void deleteArray(void)
{
	delete [] arr;
}

void printArray()
{
	cout << "Printing" << endl;
	for(int i=0;i<=filledTo;i++)
	{
		cout << arr[i] << "\t";
	}
	cout << endl <<"Size " << size << " FilledTo " << filledTo << endl;
}

void shrinkArray(void)
{
	if(size ==10) return;
	int newSize = size/2;
	
	int *newArr = new int [newSize];
	
	for(int i=0; i<=filledTo; i++)
	{
		newArr[i]= arr[i];
	}
	
	delete [] arr;
	arr = newArr;
	size = newSize;
}

bool boundaryCheckForDelete(int index)
{
	if(index <0 || index>filledTo) return false;
	else return true;
}


bool deleteAtIndex(int index)
{
	if(!boundaryCheckForDelete(index))
	{
		cout << "Invalid index for delete" << endl;
		return false;
	}
	
	for(int i=index; i<filledTo; i++)
	{
		arr[i] = arr[i+1];
	}
	
	filledTo--;
	
	if(2*(filledTo+1) == size) shrinkArray();
	return true;
}



bool deleteFirst(void)
{
	int element = arr[0];
	
	if(deleteAtIndex(0))
	{
		cout << "Deleted element: " << element << endl;
		return true;
	}
	
	else return false;
}

bool deleteLast(void)
{
	int element = arr[filledTo];
	
	if(deleteAtIndex(filledTo))
	{
		cout << "Deleted element: " << element << endl;
		return true;
	}
	
	else return false;
}

int search(int item)
{
	for(int i=0; i<=filledTo; i++)
	{
		if(arr[i]==item) return i;
	}
	return -1;
}


bool isItEmpty(void)
{
	if(filledTo == -1) return true;
	else return false;
}

bool deleteElement(int element)
{
	if(isItEmpty())
	{
		cout << "Array Empty" << endl;
		return false;
	}
	
	int index = search(element);
	
	if(index ==-1) 
	{
		cout << "Element not found in the index" << endl;
		return false;
	}
	else return deleteAtIndex(index);
}


int main (void)
{

	traversalAndInitialize();

	int itemToBeInserted = 100;
	int indexPOsitionForInsert = 0;
	int beforeValue = 17;
	int afterValue = 32;
	
	int indexPOsitionForDelete = 6;
	int itemToBeDeleted = 20;
	
	printArray();
	
	/*
	if(deleteAtIndex(indexPOsitionForDelete))	
		cout << "Deleted" << endl;
	else  cout << "Failed" << endl;
	*/
	
	/*
	if(deleteFirst())	
		cout << "Deleted" << endl;
	else  cout << "Failed" << endl;
	*/
	/*
	if(deleteLast())	
		cout << "Deleted" << endl;
	else  cout << "Failed" << endl;
	*/
	
	/*
	if(deleteElement(itemToBeDeleted))	
		cout << "Deleted" << endl;
	else  cout << "Failed" << endl;
	*/
	
	printArray();
	
	deleteArray();
}