#include <iostream>

using namespace std;


int main(void){


	string s = "Ali Reza";

    getline(cin, s);

    cout << s.length() << endl;

	for(int i=0; i < s.length(); i++)
	{
		cout << s.at(i) << endl; //s[i]
	}

    return 0;

}
