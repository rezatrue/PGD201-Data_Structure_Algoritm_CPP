#include <iostream>

using namespace std;

// problem with global variable
/*
as value of n is not assigned,
array created with the garbage value of n
so size become unknown
*/

int n;
int arrG[n];


int main (void)
{
	cout << "point 1" << endl;
	n = 4096*4096;
	cout << "point 2" << endl;
	for (int i = 0; i < n ; i++) arrG[i] = i;
	cout << "point 3" << endl;

	return 0;
}
