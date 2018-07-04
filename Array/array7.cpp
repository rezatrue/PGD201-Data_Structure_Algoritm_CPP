#include <iostream>

using namespace std;
/*
	deleteing item from Array
	updating / repalcing from Array

*/

int traverseAndInitialize(int *arr, int size)
{
	//traversal
	for(int i=0; i<size; i++)
	{
		arr[i] = -1;
	}

	for(int i=0; i<20; i++)
	{
		arr[i] = i*20;
	}

	for(int i=4; i<8; i++)
	{
		arr[i] = 150;
	}

	int filledTo = 19;
	return filledTo;
}



void printArray(int *arr, int size, int filledTo)
{
	cout << "Printing" << endl;
	for(int i=0;i<=filledTo;i++)
	{
		cout << arr[i] << "\t";
	}
	cout << endl <<"Size " << size << " FilledTo " << filledTo << endl;
}


bool validateIndexForDelete(int index, int filledTo)
{
	if(index >filledTo || index <0)
	{
		cout << "Invalid Index" << endl;
		return false;
	}
	return true;
}


bool deleteAtIndex(int *arr, int size, int &filledTo, int index)
{
	if(!validateIndexForDelete(index, filledTo)) return false;

	for(int i=index; i<filledTo; i++)
	{
		arr[i] = arr[i+1];
	}

	arr[filledTo] = -1;
	filledTo--;

	return true;
}

bool deleteFirst(int *arr, int size, int &filledTo)
{
	int element = arr[0];

	if(deleteAtIndex(arr, size, filledTo, 0))
	{
		cout << "Deleted element: " << element << endl;
		return true;
	}

	else return false;
}


bool deleteLast(int *arr, int size, int &filledTo)
{
	int element =-2;

	if(!(filledTo<0)) int element = arr[filledTo];

	if(deleteAtIndex(arr, size, filledTo, filledTo))
	{
		cout << "Deleted element: " << element << endl;

		return true;
	}

	else return false;
}

int search(int *arr, int filledTo, int item)
{
	for(int i=0; i<=filledTo; i++)
	{
		if(arr[i]==item) return i;
	}
	return -1;
}

bool isItEmpty(int filledTo)
{
	if(filledTo==-1)
	{
		cout << "Array is Empty" << endl;
		return true;
	}
	return false;
}

bool deleteElement(int *arr, int size, int &filledTo, int element)
{
	if(isItEmpty(filledTo)) return false;
	
	int index = search(arr, filledTo, element);
	
	if(index == -1)
	{
		cout << "Maalta array te nai" << endl;
		return false;
	}
	
	if(deleteAtIndex(arr, size, filledTo, index))
	{
		cout << "Deleted element: " << element << endl;
	}
	
	return true;
}

bool deleteAllAppearenceOfElement(int *arr, int size, int &filledTo, int element)
{
	if(isItEmpty(filledTo)) return false;
	
	bool wasDeleted = false;
	
	while(1)
	{
		int index = search(arr, filledTo, element);
		
		if(index == -1) break;
		
		if(deleteAtIndex(arr, size, filledTo, index))
		{
			wasDeleted = true;
		}
	}
	
	if(wasDeleted) cout << "Deleted element: " << element << endl;
	
	return wasDeleted;
}

bool replace (int *arr, int size, int &filledTo, int elementOut, int elementIn)
{
	bool wasReplaced = false;
	
	for(int i=0; i<=filledTo; i++)
	{
		if(arr[i] == elementOut)
		{
			arr[i] = elementIn;
			wasReplaced = true;
		}
	}
	
	if(wasReplaced) cout << "Replaced" << endl;
	
	return wasReplaced;
}

int binarySearch(int *arr, int filledTo, int item)
{
	int index =-1;
	
	int low=0, high = filledTo;
	
	while(low<=high)
	{
		int mid = (low+high)/2;
		
		if(item == arr[mid])
		{
			index = mid;
			break;
		}
		else if(item > arr[mid])
		{
			low = mid+1;
		}
		else
		{
			high = mid-1;
		}
	}
	
	if(index !=-1)
	{
		while(index>0 && arr[index] == arr[index-1])
		{
			index--;
		}
	}
	
	return index;
}


int main (void)
{
	int size =100;
	int arr [100];
	int filledTo=0;//(index)

	filledTo = traverseAndInitialize(arr, size);

	int itemToBeInserted =500, beforeValue =66, afterValue =-1,
		index =0, element =150, elementOut=150, elementIn=420, item=150;

	/*
	// delete from an specific index

	if(deleteAtIndex(arr, size, filledTo, index))
		cout << "Deleted" << endl;
	else  cout << "Failed" << endl;
	*/

	/*
	// delete from first four

	for (int i=0;i<4;i++)
	{
	if(deleteFirst(arr, size, filledTo))
		cout << "Deleted" << endl;
	else  cout << "Failed" << endl;
	}
	*/

	/* 
	
	// delete from last 25 items
	
	for (int i=0;i<25;i++)
	{
	if(deleteLast(arr, size, filledTo))
		cout << "Deleted" << endl;
	else  cout << "Failed" << endl;
	}
	*/
	
	/*
	// delete element 
	
	if(deleteElement(arr, size, filledTo, element))	
		cout << "Deleted" << endl;
	else  cout << "Failed" << endl;
	*/
	
	/*
	// delete all simiar elements
	if(deleteAllAppearenceOfElement(arr, size, filledTo, element))	
		cout << "Deleted" << endl;
	else  cout << "Failed" << endl;
	*/
	
	/*
	// Replace 
	if(replace(arr, size, filledTo, elementOut, elementIn))	
		cout << "Asholei Replaced" << endl;
	else  cout << "Not Replaced" << endl;
	*/
	
	
	// Binary Search
	cout << "Binary Search "<< binarySearch(arr, filledTo, item) << endl;
	

	printArray(arr, size, filledTo);


	return 0;



}

