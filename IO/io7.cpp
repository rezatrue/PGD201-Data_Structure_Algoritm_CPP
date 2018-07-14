// Practice code 07 //
// unsbale to print all lines

#include <iostream>
using namespace std;

int main(){     
	int n;
	cin >> n;
	for(int i = 0; i < n ; i++)
       {
    		string s;
            getline(cin, s);
            cout << s << endl;
	}
return 0;
}





