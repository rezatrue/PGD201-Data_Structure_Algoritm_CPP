#include <iostream>

using namespace std;


int main(void){

    string s = "ALI REZa";

    // return index number of letter Z

    if(s.find("Z") != string::npos)
        cout << s.find("Z") << endl;
	else
        cout << "eikhane nai" << endl;


    return 0;

}
