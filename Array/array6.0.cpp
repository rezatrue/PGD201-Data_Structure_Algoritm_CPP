#include <iostream>

/*
 insert into the first position of an Array
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
	for(int i = filledTo+1; i > index ; i--)
	{
		arr[i] = arr[i-1]; 
	}

	filledTo++;
	arr[index] = -1;
}

bool insertAtTheBeginning(int* arr, int size, int &filledTo, int itemToBeInserted)
{
	if(isItFull(size, filledTo)) return false;
	makeSpaceAt(arr, 0, filledTo);
	arr[0] = itemToBeInserted;
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

	int itemToBeInserted =500, beforeValue =66, afterValue =-1;

	cout << "Before inserting array ";
	printArray(arr, size, filledTo);

	if(insertAtTheBeginning(arr, size, filledTo, itemToBeInserted))
		cout << "Inserted" << endl;
	else
		cout << "failed" << endl;

    cout << "After inserting array ";

	printArray(arr, size, filledTo);

	return 0;
}
