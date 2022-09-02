#include <iostream>
#include"Flat.h"
using namespace std;
/*Создать класс квартира
Реализовать перегруженные операторы
1. == Проверка на равенство площадей
2. = операция присваивания 
3. Сравнение двух квартир по цене*/
void ComparePrices(const Flat& o1, const Flat& o2)
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

void CompareSquare(const Flat& o1, const Flat& o2)
{
    if (o1 == o2)
    {
        cout << o1 << " & " << o2 <<" squares are the same" << endl;
    }
    else
    {
        cout << o1 << " & " << o2 << " squares are different" << endl;
    }
}

int main()
{
    Flat o1(150, 7000000);
    Flat o2(65, 3500000);

    ComparePrices(o1, o2);
    CompareSquare(o1, o2);
    o2 = o1;
    CompareSquare(o1, o2);
}