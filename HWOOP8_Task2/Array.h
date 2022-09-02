#pragma once
#include <iostream>
using namespace std;

class Array
{
	int size;
	int* arr;
public:
	explicit Array(int _size) : size(_size), arr{ new int[_size] }
	{
		cout << "constructor\n";
	}

	Array(const Array& arr2) : size(arr2.size), arr{ new int[arr2.size] }
	{
		for (int i = 0; i < arr2.size; i++)
		{
			arr[i] = arr2[i];
		}
		cout << "copy constructor\n";
	}

	Array(Array&& arr2) noexcept : size{ arr2.size }, arr{ arr2.arr }
	{
		arr2.arr = nullptr;
		arr2.size = 0;
		cout << "move constructor\n";
	}

	//Array() : Array(0){}

	int getSize()
	{
		return size;
	}

	bool operator == (const Array& arr2)
	{		
		if (size == arr2.size)
		{
			for (int i = 0; i < size; i++)
			{
				if (arr[i] != arr2.arr[i])
					return false;
			}
			return true;
		}
		else
		{
			return false;
		}
	}

	~Array()
	{
		cout << "destructor\n";
		/*for (int i = 0; i < size; i++)
		{
			cout << arr[i] << " ";
		}*/				
		delete[] arr;	
	}
	Array& operator = (const Array& arr2)//копирующее присваивание
	{
		if (&arr2 == this)
		{
			return *this;
		}
		if (size != arr2.size)
		{
			delete arr;
			arr = new int[arr2.size];
			size = arr2.size;
		}

		for (int i = 0; i < size; i++)
		{
			arr[i] = arr2.arr[i];
		}

		return *this;
	}

	Array& operator=(Array&& arr2) noexcept//перемещающее присваивание
	{
		cout << "move =\n";
		if (this == &arr2)
		{
			return *this;
		}
		delete arr;
		arr = new int[arr2.size];
		size = arr2.size;
		arr2.arr = nullptr;
		arr2.size = 0;
		return *this;
	}

	int& operator [] (int index)
	{
		if (index < 0 || index >= size)
		{
			cout << " index is out of range\n";
			exit(1);
		}
		return arr[index];
	}

	int& operator [] (int index) const
	{
		if (index < 0 || index >= size)
		{
			cout << " index is out of range\n";
			exit(1);
		}
		return arr[index];
	}

	friend ostream& operator << (ostream& output, const Array& a )
	{
		for (int i = 0; i < a.size; i++)
		{
			output << a.arr[i] << " ";
		}

		return output;
	}

	friend istream& operator >> (istream& input, Array& a)
	{
		for (int i = 0; i < a.size; i++)
		{
			input >> a[i];
		}
		return input;
	}

	friend Array operator + (const Array& a, const Array& b)
	{
		Array c{ a.size };
		if (a.size == b.size)
		{
			for (int i = 0; i < a.size; i++)
			{
				c[i] = a[i] + b[i];				
			}
			return c;
		}
		else
		{
			cout << "sum impossible\n";
			exit(1);
		}
	}

	Array randomArray(int size)
	{
		Array temp{ size };
		for (int i = 0; i < size; i++)
		{
			temp[i] = rand() % 10;
		}
		return temp;
	}

};



