#include <iostream>

using namespace std;
// loacal vaiable must have limied size
// local variable placed in stack memory
// stack size is limited for each application

int main (void)
{	
	int size = 4096*4096;
	// local array huge size
	double arrL[size];
	// unable to execute due to size
	for(int i = 0; i <size; i++)
	{
		arrL[i] = (i+1)*10;
	}

	for(int i = 0; i <size; i++)
	{
		cout << arrL[i] << endl;
	}

	return 0;
}
