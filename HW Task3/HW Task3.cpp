#include <iostream>
#include <time.h>
#include <math.h>
using namespace std;
/*������� 3. �������� ���� ����� � �������. ���������
����������� ������������� ����� � �������� ������
������� ���. ����� ����� ������������� ����� ���������
��������, ������� ���� ����� ������� (����) � �������
���� ������� � ����� �� ������ ����� (������). �����
����������� ����� �� ����� ���������� ������� ���������� ��������� ������������� �������. � ���������
���������� ������������ ��������.*/
void DefineNum(int arr[4])
{ 
    srand(time(0));
    for (int i = 0; i < 4; i++)
    {
        arr[i] = rand() % 9;
        //cout << arr[i];
    }
}
int CowBullsLogic(int num, int arr[], int count = 0)
{
    int cows = 0;
    int bulls = 0;
    int userNum[4];
    for (int i = 3; i >= 0; i--)
    {
        userNum[i] = num % 10;
        num /= 10;
    }
    for (int i = 0; i < 4; i++)
    {        
        for (int j = 0; j < 4; j++)
        {
            if (arr[i] == userNum[j] && i == j)
            {                
                cows++;                
            }            
            else if (arr[i] == userNum[j])
            {
                bulls++;
            }
        }
    }
    cout << "���� = " << bulls << ", ������ = " << cows << endl;
    count++;
    if (cows != 4)
    {
        cout << "������� ������������� �����\n";
        cin >> num;
        CowBullsLogic(num, arr, count);
    }
    else
    {
        return count;
    }        
}
void ParseNum(int num, int userNum[])
{
    for (int i = 3; i >= 0; i--)
    {
        userNum[i] = num % 10;
        num /= 10;
    }
}
int NoCycleLogic( int num, int arr[], int count = 0)
{    
    

}
int main()
{
    setlocale(0, "");
    int arr[4];
    int userNum[4];
    int num, bulls, cows;    

    DefineNum(arr);
    cout << "\n�������� ������������� �����\n";
    /*cin >> num;
    cout << "\n� ��� ���� "<< CowBullsLogic(num, arr) <<" �������";*/
    cout << "\n� ��� ���� "<< NoCycleLogic(num, arr) <<" �������";
    while (cows != 4) 
    {
        bulls = 0;
        cows = 0;
        cout << "������� ������������� �����\n";
        cin >> num;
        ParseNum(num, userNum);
        CowBullsLogic(num, arr);
    }
}

