#include <iostream>

// need to talk with sir why dynamic array show segmentation error??

using namespace std;
/*
	Dynamic / resizeable variable placed in Heap
	It has big storage size / user has control over it size
	Less secured
	uses shared memory
	variable exist upto application life time
	
*/

void creatDynamicArray(int *arr, int size)
{
	arr = new int[size];
}

void destroyDynamicArray(int *arr)
{
	delete [] arr;
}

int main(void)
{
	
	int *a;
	
	creatDynamicArray(a, 10);
	cout << "p1" << endl;
	//for(int i = 0; i < 10 ; i++) a[i] = i*10;
	cout << "p2" << endl;
	for(int i = 0; i < 10; i++) cout << a[i] << endl;
	cout << "p3" << endl;
	destroyDynamicArray(a);

	return 0;
}
