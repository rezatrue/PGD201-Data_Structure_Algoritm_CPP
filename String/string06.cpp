#include <iostream>

using namespace std;


int main(void){


	string s = "Ali Reza";

    string s1 = "ali Reza";

	if(s1.compare(s) == 0)
        cout << "milse" << endl; //s == s1
	else
        cout << "mile nai" << endl;
        // it don't match because it is case sensitive
    return 0;

}
