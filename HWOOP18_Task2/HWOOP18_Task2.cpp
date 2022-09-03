#include <iostream>
#include <cmath>
using namespace std;

/*Описать базовый класс «Строка».
Методы:
1) конструктор без параметров;
2) конструктор, принимающий в качестве параметра
C - строку(заканчивается нулевым байтом);
3) конструктор копирования;
4) оператор присваивания;
5) получение длины строки;
6) очистка строки(сделать строку пустой);
7) деструктор;
8) конкатенация строк(перегрузить операторы + и += );
9) проверка на равенство(= = ) и на неравенство(!= ).*/

class myString
{
protected:

    char* data;
    int size;

public:    

    myString(const char* input, int size) : data{ input ? new char[strlen(input) + 1] : nullptr }, size{ size }
    {
        if (data != nullptr)
        {
            strcpy_s(data, strlen(input) + 1, input);            
        }
        /*else if (size > 0)
        {
            cout << "debug int initialization\n";
            for (int i = 0; i < size; i++)
            {
                data[i] = '0';
            }
        }*/
    }

    myString(int size) :myString(new char[size + 1], size) {}

    myString(const char* input) :myString(input, strlen(input)) {}

    myString() :myString(new char[80], 80) {}

    myString(const myString& orig) :myString(orig.data, orig.size) {}


    myString(myString&& orig) noexcept 
    {
        cout << "debug move operator" << *this;
        if (data != nullptr)
        {
            delete[] data;
        }
        data = orig.data;
        size = orig.size;
        orig.data = nullptr;
        orig.size = 0;
    }

    ~myString()
    {
        if (data)
        {
            delete[] data;
        }
    }

    friend ostream& operator << (ostream& output, const myString& outMS)
    {

        for (int i = 0; i < outMS.size; i++)
        {
            output << outMS.data[i];
        }
        return output;
    }

    friend istream& operator >> (istream& input, myString& inMS)
    {
        string temp;
        input >> temp;
        inMS.size = temp.size();
        inMS.data = new char[inMS.size + 1];
        for (int i = 0; i < inMS.size; i++)
        {
            inMS.data[i] = temp[i];
        }
        return input;
    }

    myString& operator = (myString& ms)
    {
        if (&ms == this)
        {
            return *this;
        }
        if (data)
            delete[] data;

        data = new char[ms.size + 1];
        strcpy_s(data, ms.size + 1, ms.data);        
        size = ms.size;
        return *this;
    }

    myString& operator = (const char* input)
    {
        if (input == data)
            return *this;
        if (data)
            delete[] data;
        size = strlen(input);
        data = new char[size + 1];
        for (int i = 0; i < size; i++)
        {
            data[i] = input[i];
        }
        return *this;
    }

    bool operator ==(myString& ms2)
    {
        if (size == ms2.size)
        {
            for (int i = 0; i < size; i++)
            {
                if (data[i] != ms2.data[i])
                    return false;
            }
            return true;
        }
        else
        {
            return false;
        }
    }

    bool operator !=(myString& ms2)
    {
        if (*this == ms2)
        {
            return false;
        }
        else
            return true;
    }
};

/*Описать класс «Битовая строка» производный от 
класса «Строка» 
(Строки данного класса могут содержать только символы ‘0’ и ‘1’). Если в основе инициализирующей строки
встретятся любые символы, отличные от допустимых, то
«Битовая строка» конвертируется. 

Методы:
1) конструктор без параметров;
2) конструктор, принимающий в качестве параметра
C-строку;
3) конструктор копирования;
4) оператор присваивания;
5) деструктор;
6) изменение знака числа (перевод числа в дополнительный код).
7) сложение битовых строк (перегрузить операторы +
и +=);
8) проверка на равенство (==) и на неравенство (!=)
*/

class myBitStr :public myString
{
    int* ConvertToBit(const char* &cstr)
    {
        int size = strlen(cstr);
        int* asciiStr = new int[size];
        int* bitStr = new int[size * 8 + 1];
        int index = 0;
        int power;

        for (int i = 0; i < size; i++)
        {
            asciiStr[i] = (int)cstr[i];            
        }

        for (int i = 0; i < size; i++)
        {
            power = 7;
            while (power >= 0)
            {
                if (asciiStr[i] >= pow(2, power))
                {
                    asciiStr[i] -= pow(2, power);
                    bitStr[index] = 1;
                    
                }
                else
                {
                    bitStr[index] = 0;
                }

                index++;
                power--;
            }
        }

        return bitStr;
    }
public:

    myBitStr(const char* input)
    {
        delete[] data;        
        size = strlen(input) * 8;
        int* numData = new int[size];
        numData = ConvertToBit(input);
        data = new char[size + 1];
        for (int i = 0; i < size; i++)
        {
            if (numData[i] == 1)
            {
                data[i] = '1';
            }
            else
            {
                data[i] = '0';
            }
        }
    }

    myBitStr(int size) : myString(size){}

    myBitStr() :myBitStr(" "){}

    myBitStr(const myBitStr& orig) :myBitStr(orig.data) {}

    myBitStr(myBitStr&& orig) noexcept
    {        
        if (data != nullptr)
        {
            delete[] data;
        }
        data = orig.data;
        size = orig.size;
        orig.data = nullptr;
        orig.size = 0;
    }

    myBitStr operator + (const myBitStr& ms2)
    {
        myBitStr result(size + ms2.size); 
        int index = 0;
        for (int i = 0; i < result.size; i++)
        {
            if (i < size)
            {
                result.data[i] = data[i];
            }
            else
            {
                result.data[i] = ms2.data[index];
                index++;
            }
        }        
        cout << result << endl;        
        return result;
    }

    myBitStr operator += (myBitStr& ms2)
    {
        return *this + ms2;
    }

    myBitStr& operator = (const myBitStr& ms)
    {        
        if (&ms == this)
        {
            return *this;
        }
        if (data != nullptr)
        {            
            delete[] data;            
        }           
        
        data = new char[ms.size + 1];        
        for (int i = 0; i < ms.size; i++)
        {
            data[i] = ms.data[i];
        }
        
        size = ms.size;        
        return *this;
    }
};

int main()
{
    //проверяем работу класса myString    
    myString ms1("myString");
    myString ms2("myString");
    cout << (ms1 == ms2) << endl;
    ms1 = "newMyString";
    cout << ms1 << endl;
    cout << (ms1 != ms2) << endl;
    ms1 = ms2;
    cout << ms1 << endl << "-----------------------" << endl;
    //myBitString
    
    myBitStr mbs1("myBitStr");
    cout << "my Bit String created " << mbs1 << endl;
    myBitStr mbs2("0");
    cout << "my Bit String #2 created " << mbs2 << endl;
    myBitStr mbs3;
    mbs3 = mbs1 + mbs2;    
    cout << "summand of bit strings is " << mbs3 << endl;
    cout << (mbs1 == mbs2) << endl;
}
