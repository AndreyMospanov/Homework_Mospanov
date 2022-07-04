#include <iostream>
#include "myString.h"

using namespace std;
int myString::msCount{ 0 };
int main()
{
    myString ms1 = "myString ms1";
    cout << ms1 << endl;
    myString ms2;
    cout << "type new ms2:\n";
    cin >> ms2;
    cout << ms2;
    myString ms3("ms3: input");
    cout << ms3 << endl;
    cout << "total myStrings in this program: " << ms1.msCount;
}