#include <iostream>

using namespace std;

int* arr;

void printArray1(int n )
{	
	arr[1] = 100; // we can insert data as array is global

	for(int i = 0; i < n ; i++)
		cout << arr[i] << endl;
}

void printArray2(int *arrL, int n )
{
	for(int i = 0; i < n ; i++)
		cout << arrL[i] << endl;
}


int main(void)
{
	int n = 10;
	arr = new int[10];

	for(int i = 0; i < n ; i++) arr[i] = i;

	printArray1(n);

	printArray2(arr, n);

	delete [] arr;

	return 0;
}
