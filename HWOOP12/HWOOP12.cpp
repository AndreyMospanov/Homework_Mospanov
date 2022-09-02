/*Создать шаблонный класс матрица. Необходимо Реализовать динамическое выделение и очистку памяти, заполнение матрицы с клавиатуры, заполнение случайными значениями, отображение матрицы, арифметические операции с помощью перегруженных операторов. Поиск максимального и минимального элементов*/
#include <iostream>
#include "Matrix.h"
using namespace std;

int main()
{
    Matrix<double> mx(4, 6);
    Matrix<char> mxch(4, 6);
    mx.SetRandom();
    mx.ShowArr();
    cout << "min = " << mx.getMin() << endl;
    cout << "max = " << mx.getMax() << endl;
    mxch.SetRandom();
    mxch.ShowArr();
    Matrix<int> mxi(2, 2);
    cout << "enter 4 values for new matrix\n";
    cin >> mxi;
    cout << "new matrix is:\n";
    cout << mxi; 
    cout << "let's sum it with other matrix\n";
    Matrix<int> mxi2(2, 2);
    mxi2.SetRandom();
    cout << mxi2;    
    mxi = mxi + mxi2;
    cout << "sum = \n" << mxi << endl;
}
