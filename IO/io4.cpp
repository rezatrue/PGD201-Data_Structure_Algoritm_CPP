// Practice code 04 //
// Problem arises if file is broken

#include <iostream>
using namespace std;

int main(){     
         int x;
         cin >> x;
        while(!cin.eof()){
		cout << x << endl;
        	cin >> x;
    	}
    return 0;
}


