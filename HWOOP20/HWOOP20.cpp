/*Создайте иерархию классов по работе с файлами. Базовый 
класс умеет открывать файл и отображать его содержимое в консоль, первый класс потомка открывает файл 
и отображает содержимое в виде ASCII-кодов символов, 
расположенных в файле, второй класс потомка открывает 
файл и показывает его содержимое в двоичном виде и т.д.
Для отображения содержимого файла в базовом классе 
определена виртуальная функция 
•	 void Display(const char * path);
•	 path — путь к файлу.
Потомки создают свою реализацию виртуальной функции*/

#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
using namespace std;

class FileReader
{
protected:
    string path;
    ofstream out;
    ifstream in;
public:

    FileReader(string pathP) :path{ pathP } {}    

    void CreateFile()
    {
        out.open(path);//создаём файл и открываем его для записи
        out.close();
    }

    void Record(string input)
    {
        out.open(path, ios::app);
        if (out.is_open())
        {
            out << input << endl;
        }
        out.close();
        cout << "\nData recorded\n";
    }

    virtual void Display()
    {
        string fileData;
        in.open(path);
        if (in.is_open())
        {
            cout << "\nRead file data:\n";
            while (getline(in, fileData))
            {
                cout << fileData << endl; 
            }
        }
        in.close();
        cout << "End of programm\n";
    }
};

class AsciiConverter :public FileReader
{
    int* asciiData;

    void ConvertToAscii(string &fileData)
    {
        int size = fileData.length();
        
        for (int i = 0; i < size; i++)
        {
            char temp = fileData[i];
            asciiData[i] = (int)temp;            
        }        
    }
    
public:
    AsciiConverter(string pathP) :FileReader(pathP) {}
    
    virtual void Display()
    {
        string fileData;        
        in.open(path);
        if (in.is_open())
        {
            getline(in, fileData);
        }
        in.close();
        asciiData = new int[fileData.size()];
        ConvertToAscii(fileData);
        cout << "\nReading converted Ascii Data: \n";
        for (int i = 0; i < fileData.size(); i++)
        {
            cout << asciiData[i] << " ";
        }
        cout << "\nEnd of converted programm\n";
    }

    int* AsciiData()
    {
        return asciiData;
    }

     
};

class BinaryReader :public FileReader
{
    int* ascii;    

    void ConvertToByte(string& fileData)
    {
        int size = fileData.length();

        for (int i = 0; i < size; i++)
        {
            char temp = fileData[i];
            ascii[i] = (int)temp;
        }
    }
public:
    BinaryReader(string pathP) :FileReader(pathP) {}

    virtual void Display()
    {
        string fileData;
        in.open(path);
        if (in.is_open())
        {
            getline(in, fileData);
        }
        in.close();
        ascii = new int[fileData.size()];        
        ConvertToByte(fileData);

        cout << "\nReading file in binary mode:\n";
        for (int i = 0; i < fileData.size(); i++)
        {            
            if (ascii[i] < 0)
            {
                cout << "1";
                ascii[i] *= -1;
            }
            else
            {
                cout << "0";
            }

            int power = 7;
            while (power >= 0)
            {
                if (ascii[i] >= pow(2, power))
                {
                    ascii[i] -= pow(2, power);
                    cout << "1";

                }
                else
                {
                    cout << "0";
                }
                power--;
            }
            cout << " ";
        }
        cout << "\nEnd of binary programm\n";
    }
};

int main()
{
    setlocale(0, "");
    string path = "C:\\Homework\\Homework20.txt";
    string dataForText = "ios::in: файл открывается для ввода (чтения). Может быть установлен только для объекта ifstream или fstream";
    string dataForText2 = "ios::out: файл открывается для вывода (записи). При этом старые данные удаляются. Может быть установлен только для объекта ofstream или fstream";
    FileReader fr(path);

    cout << "Base class:\n";
    fr.CreateFile();
    fr.Record(dataForText);
    fr.Display();
    fr.Record(dataForText2);
    fr.Display();

    cout << "ASCII Converted Data:\n";
    AsciiConverter ac(path);
    ac.Display();

    BinaryReader br(path);
    br.Display();
}