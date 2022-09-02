#include <iostream>
#include"Overcoat.h"
/*Создать класс верхняя одежда.
Реализовать перегруженные операторы:
1. == равенство типов одежды
2. = Операцию присваивания
3. >,< Сравнение двух пальто одного типа*/


void ComparePrices(const Overcoat& o1, const Overcoat& o2)
{
    if (o1 > o2)
    {
        cout << o1 << " cost more than " << o2 << endl;
    }
    else
    {
        cout << o1 << "is cheaper, than " << o2;
    }
}

void CompareTypes(const Overcoat& o1, const Overcoat& o2)
{
    if (o1 == o2)
    {
        cout << "overcoats " <<o1 <<" & " << o2 << " are the same type\n";
    }
    else
    {
        cout << "overcoats " <<o1 <<" & " << o2 << " have different types\n";
    }
}
int main()
{
    Overcoat o1("kurtka", 5000);
    Overcoat o2("vatnik", 350);
    Overcoat o3("kurtka", 4500);
    Overcoat o4;
    cout << "enter new overcoat: type, price\n";
    cin >> o4;
    cout << "You've created " << o4 << endl;

    CompareTypes(o1, o2);
    CompareTypes(o2, o3);
    o2 = o1;
    cout << "o2 now is " << o2 << endl;
    CompareTypes(o2, o3);
    ComparePrices(o2, o3);
    if (o3 == o4)
    {
        ComparePrices(o3, o4);
    }
    else
    {
        cout << "overcoats uncomparable\n";
    }
}
