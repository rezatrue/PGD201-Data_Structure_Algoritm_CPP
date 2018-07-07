#include <iostream>

using namespace std;


int main(void){


	string s = "Ali Reza";

    char str[80];

    // start reading from 4th position
    // & read 3 characters
    // count start from Zero [first position is 0 like array]

	s.copy(str,3, 4);
	str[3]='\0';

	cout << str << endl;

    return 0;

}
