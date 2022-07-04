#pragma once
#include <iostream>
#include <string.h>
using namespace std;
/*
Задание.
Разработать класс String, который в дальнейшем будет
использоваться для работы со строками. Класс должен
содержать:
•	 Конструктор по умолчанию, позволяющий создать
строку длиной 80 символов;
•	 Конструктор, позволяющий создавать строку произвольного размера;
•	 Конструктор, который создаёт строку и инициализирует её строкой, полученной от пользователя.
Необходимо создать деструктор, а также использовать
механизмы делегирования конструкторов, если это возможно.
Класс должен содержать методы для ввода строк с клавиатуры и вывода строк на экран. Также нужно реализовать
статическую функцию-член, которая будет возвращать количество созданных объектов строк
*/

class myString
{
	char* data;
	int size;
	
public:

	static int msCount;

	myString(const char* input, int size) : data{ input ? new char[strlen(input) + 1] : nullptr }, size{ size }
	{
		strcpy_s(data, strlen(input) + 1, input);
		msCount++;
	}

	myString(const char* input) :myString(input, strlen(input)) {}
	
	myString():myString(new char[80], 80){}

	myString(const myString& orig)
	{
		if (data)
		{
			delete[] data;
		}
		data = new char[orig.size + 1];
		strcpy_s(orig.data, orig.size + 1, data);
		size = orig.size;
	}

	myString(myString&& orig) : data{ orig.data }, size{ orig.size }
	{
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

	myString& operator = (myString& ms)
	{
		if (&ms == this)
		{
			return *this;
		}
		if (data)
			delete[] data;

		data = new char[ms.size + 1];
		data = ms.data;
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
	

};



