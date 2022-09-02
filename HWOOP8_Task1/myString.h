#pragma once
#include <iostream>
#include <string.h>
using namespace std;
/*
�������.
����������� ����� String, ������� � ���������� �����
�������������� ��� ������ �� ��������. ����� ������
���������:
�	 ����������� �� ���������, ����������� �������
������ ������ 80 ��������;
�	 �����������, ����������� ��������� ������ ������������� �������;
�	 �����������, ������� ������ ������ � �������������� � �������, ���������� �� ������������.
���������� ������� ����������, � ����� ������������
��������� ������������� �������������, ���� ��� ��������.
����� ������ ��������� ������ ��� ����� ����� � ���������� � ������ ����� �� �����. ����� ����� �����������
����������� �������-����, ������� ����� ���������� ���������� ��������� �������� �����
*/

class myString
{
	char* data;
	int size;
	
public:

	//static int msCount;

	myString(const char* input, int size) : data{ input ? new char[strlen(input) + 1] : nullptr }, size{ size }
	{
		if (input)
		{
			strcpy_s(data, strlen(input) + 1, input);
			//msCount++;
		}
		cout << "constructor " << this->data << endl;
	}

	myString(const char* input) :myString(input, strlen(input)) {}
	
	myString():myString(new char[80], 80){}

	myString(const myString& orig): data{new char[orig.size + 1] }, size{orig.size}
	{
		if (data)
		{
			strcpy_s(data, orig.size + 1, orig.data);
			cout << "copy constructor " << data << endl;
		}
	}

	myString(myString&& orig) noexcept : data{ orig.data }, size{ orig.size }
	{
		orig.data = nullptr;
		orig.size = 0;
		cout << "move constructor " << data << endl;
	}

	~myString()
	{
		cout << "destructor of ";
		if (data)
		{	
			cout << this->data << endl;
			delete[] data;
		}
		else
		{
			cout << "empty data\n";
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
		strcpy_s(data, ms.size + 1, ms.data);
		size = ms.size;
		cout << "= operator " << data << endl;
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
	
	myString MoveCtorShow()
	{
		myString ms("toShowMoveConstructor");
		return ms;
	}
};



