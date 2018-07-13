#include <iostream>

using namespace std;

int* tain(int* arrL)
{
	cout << arrL[5] << endl;
	int arrT[3] = {1,2,3};
	return arrT;
}


int main(void)
{
	int number = 10;
	/* local array
	-Created in stack memory
	-Has limited life time, exist with in scope/ function
	-Must be small/ limited in size, as stack is limited for each application
	-High level of security
	-Exclusive
	-if overflowed application crashed [segmentation error]
	*/
	int arrL[number];

	for (int i = 0; i < number ; i++)
	{
		arrL[i] = (i+1)*10;
	}

	for(int i = 0; i < number ; i++)
	{
		cout << arrL[i] << endl;
	}


	// value of the location array arrT don't exist
	// segmentation fault (core dumped)
	int* arr = tain(arrL);
	// unable to print output
	cout << arr[1] << endl;

	return 0;

}
