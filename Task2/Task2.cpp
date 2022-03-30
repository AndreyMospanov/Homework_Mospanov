#include <iostream>
using namespace std;
/*Задание 2. Написать рекурсивную функцию, которая
выводит N звезд в ряд, число N задает пользователь. Проиллюстрируйте работу функции примером.*/
void PrintStars(int num)
{
	cout << "*";
	if(num > 1)
	PrintStars(num - 1);
}
int main()
{
	int num;
	cout << "Enter number ";
	cin >> num;
	PrintStars(num);
}
