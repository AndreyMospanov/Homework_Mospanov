#include <iostream>
#include "myString.h"
using namespace std;
//добавить в класс myString конструктор переноса
int main()
{
    myString s1("string1");
    myString s2(s1);

    s1 = s2;
    s2.MoveCtorShow();  
}