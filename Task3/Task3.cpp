#include <iostream>
using namespace std;
/*�������� �������, ������� ������� ����� ���� ����� � ��������� �� � �� �*/
int SumOfRange(int a, int b)
{    
    if (a == b)
    {
        return b;
    }
    return b + SumOfRange(a, b - 1);
}

int main()
{
    int a, b;
    cout << "Enter a ";
    cin >> a;
    cout << "\nEnter b ";
    cin >> b;
    cout << "\nResult = " << SumOfRange(a, b);
}
