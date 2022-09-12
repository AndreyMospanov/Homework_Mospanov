/*Задание 2.
Создайте иерархию пользовательских классов-исключений. В ней должны быть классы для разных ситуаций. В качестве предметной области используйте ваши 
практические и домашние задания. Например, должны присутствовать классы для обработки всевозможных 
математических ошибок, нехватки памяти, проблемам по работе с файлами и т.д*/
#include <iostream>
using namespace std;

class Exxxception
{
public:
    Exxxception() {}
};

class MathExceptions: public Exxxception
{
public:
    MathExceptions() {}
    bool CheckCorrectInput(string input) {}
    double CheckDivisionByZero(double a, double b) {}
    void CheckOutOfRangeArray(int index, int size) {}
};

class FileExceptions : public Exxxception
{
public:
    FileExceptions() {}
    void FileAlreadyExists(string path) {}
    void FileIsNotExist(string path) {}
    void AccessError(string path) {}
};

int main()
{
    
}
