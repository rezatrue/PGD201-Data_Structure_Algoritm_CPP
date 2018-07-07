#include <iostream>

using namespace std;


int main(void){


	string s ;

    // CIN
    // delimiters =>  space, tab, new line
    // first skip all delimiter &
    // read data until it gets any delimiter
    cin >> s;
    cout << s << " One"  << endl;

    cin >> s;
    cout << s <<  " Two" << endl;

    // GETLINE read full line
    // delimiter new line (\n)
    getline(cin, s);
    cout << s <<   " Three" <<endl;

    return 0;

}
