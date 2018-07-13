#include <iostream>

using namespace std;

// problem with Local variable
/*
segmentation fault (core dumped) due to size
*/



int main (void)
{

	int n;

	cout << "point 1" << endl;
	n = 4096*4096;
	cout << "point 2" << endl;
	int arrL[n];
	for (int i = 0; i < n ; i++) arrL[i] = i;
	cout << "point 3" << endl;

	return 0;
}
