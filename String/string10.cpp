#include <iostream>

using namespace std;


int main(void){

    string s = "ALI REZA";

    // start replacing fifth (index 4) later
    // replace 3 letter with "ahmed reza"

	//s.replace(4, 3, "ahmed reza");

	// insert into fourth (index 3)
    // insert 3 letter from third position (index 2)

	//s.insert (4, "ahmed ", 2, 3);

	string s1 = " Iron Man";
	s.append(s1);

	cout << s << endl;

    return 0;

}
