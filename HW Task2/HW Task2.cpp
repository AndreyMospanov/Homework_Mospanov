#include <iostream>
using namespace std;
//�������� ����������� ������� ���������� ����������� ������ �������� ���� int
static int MaxDivider(int a, int b)
{
    int temp, maxDivider;
    
    if (a > b)
    {
        temp = a;
        a = b;
        b = temp;
    }
    b %= a;

    if (a != 0 && b != 0)
    {
        MaxDivider(a, b);        
    }
    else
    {
        return a + b;
    }
}
int main()
{
    int a, b;
    setlocale(0, "");
    cout << "������� ����� 1\n";
    cin >> a;
    cout << "������� ����� 2\n";
    cin >> b;
    cout << "��� = " << MaxDivider(a, b);
}
