#include <iostream>

using namespace std;

/* global variable
	placed in Global program space
	Less secure
	variable exist up to application life time
	Huge size variable can be stored
	Shared memory

*/

double arrG[4096*4096];

int main (void)
{


	for(int i = 0; i <4096*4096; i++)
	{
		arrG[i] = (i+1)*10;
	}

	for(int i = 0; i <4096*4096; i++)
	{
		cout << arrG[i] << endl;
	}

	return 0;
}
