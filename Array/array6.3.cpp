#include <iostream>

/*
 searing data & insert data after search item
 insert data in the middle of an Array
*/

using namespace std;


int traverseAndInitialize(int* arr, int size)
{
		// transverse
		for(int i = 0; i < size ; i++)
		{
			arr[i] = -1;
		}

		for(int i = 0; i < 10 ; i++ )
		{
			arr[i] = i * 5 ;
		}

		int filledTo = 9;
		return filledTo;
}

bool isItFull(int size, int filledTo)
{
	if(filledTo == size -1) return true;
	else return false;
}

void makeSpaceAt(int *arr, int index, int &filledTo)
{
	for(int i = filledTo; i > index ; i--)
	{
		arr[i+1] = arr[i];
	}

	filledTo++;
	arr[index] = -1;
}

int search(int* arr, int filledTo, int beforeValue)
{
	for(int i = 0; i <= filledTo;  i++)
	{
		if(arr[i] == beforeValue) return i;
	}

	return -1;
}


bool insertAfterValue(int* arr, int size, int &filledTo, int itemToBeInserted, int beforeValue)
{
	if(isItFull(size, filledTo)) return false;
	int index = search(arr, filledTo, beforeValue);
	if(index == -1)
	{
		cout << beforeValue <<" is not exist in the Array" << endl;
		return false;
	}
	makeSpaceAt(arr, index+1, filledTo);
	arr[index+1] = itemToBeInserted;
	return true;

}

void printArray(int* arr, int size, int filledTo)
{
	cout << "Printing" << endl;
	for(int i = 0 ; i <= filledTo ; i++)
	{
		cout << arr[i] << "\t";
	}

	cout << endl << "Size " << size << ", Fill to : " << filledTo << endl;
}


int main (void)
{
	int size = 100;
	int arr[100];
	int filledTo = 0; // index

	filledTo = traverseAndInitialize(arr, size);

	int itemToBeInserted =500, beforeValue =35, afterValue =-1;

	cout << "Before inserting array ";
	printArray(arr, size, filledTo);

	if(insertAfterValue (arr, size, filledTo, itemToBeInserted, beforeValue))
		cout << "Inserted" << endl;
	else  cout << "Failed" << endl;


    cout << "After inserting array ";

	printArray(arr, size, filledTo);

	return 0;
}
