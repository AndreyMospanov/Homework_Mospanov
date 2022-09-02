#pragma once
#include<iostream>
#include<time.h>
using namespace std;
template<class T>
class Matrix
{
	T* arr;
	int width;
	int height;	

	bool correctIdx(int index, int size)
	{
		if (index >= 0 || index < size)
			return true;
		else
			return false;
	}

	void ProgCrash(string message)
	{
		cout << message << endl;
		system("pause");
		exit(1);
	}

	void init(int width, int height)
	{
		this->width = width;
		this->height = height;
		int length = width * height;
		arr = new T[length];
		for (int i = 0; i < length; i++)
		{
			arr[i] = T();
		}
	}

	void clear()
	{
		if (arr != nullptr)
			delete[] arr;
		arr = nullptr;
	}

public:
	Matrix(int widthP, int heightP) :width{ widthP }, height{ heightP }
	{		
		if (width <= 0 || height <= 0)
			ProgCrash("impossible matrix");
		init(width, height);
	}

	Matrix() = delete;

	~Matrix()
	{		
		clear();
	}
	Matrix(Matrix& orig)
	{
		cout << "copy constructor\n";
		init(orig.width, orig.height);
		for (int i = 0; i < width * height; i++)
		{
			arr[i] = orig.arr[i];
		}
	}

	Matrix(Matrix&& orig):width{orig.width}, height{orig.height} 
	{
		cout << "move constructor\n";
		if (arr != nullptr)
		{
			delete[] arr;
			this->arr = new T[height * width];
		}
		
		for (int i = 0; i < width * height; i++)
		{
			arr[i] = orig.arr[i];			
		}
		orig.arr = nullptr;
		orig.width = 0;
		orig.height = 0;
	}

	int size()
	{
		return width * height;
	}

	void SetRandom()
	{
		srand(time
		(NULL));		
		for (int i = 0; i < width * height; i++)
		{			
			arr[i] = (T)(rand() % 999)/10;			
		}
	}

	void ShowArr()
	{
		for (int i = 0; i < width * height; i++)
		{
			cout << arr[i] << " ";
			if ((i + 1) % width == 0)
				cout << endl;
		}
		cout << "------------\n";
	}

	template <class T>
	Matrix& operator [](int index)
	{
		if (index < 0 || index >= width * height)
		{
			cout << " index is out of range\n";
			exit(1);
		}
		return this->arr[index];
	}

	template <class T>
	Matrix& operator [](int index) const
	{
		return this->arr[index];
	}

	bool operator == (const Matrix& arr2)
	{
		if (width*height == arr2.width * arr2.height)
		{
			for (int i = 0; i < size(); i++)
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

	Matrix& operator = (const Matrix& orig)
	{
		cout << " = operator\n";
		if (*this == orig)
		{
			return *this;
		}		
		if (width*height != orig.width * orig.height)
		{
			delete[] this->arr;
			arr = nullptr;
			this->width = orig.width;
			this->height = orig.height;			
			arr = new T[orig.width * orig.height];
		}
		for (int i = 0; i < width * height; i++)
		{
			arr[i] = orig.arr[i];
		}		
		return *this;
	} 
	
	friend istream& operator >> (istream& input, Matrix& mx)
	{
		for (int i = 0; i < mx.height*mx.width; i++)
		{
			input >> mx.arr[i];
		}		
		return input;
	}
	
	friend ostream& operator << (ostream& output, Matrix& mx)
	{
		for (int i = 0; i < mx.width * mx.height; i++)
		{
			output << mx.arr[i] << " ";
			if ((i + 1) % mx.width == 0) 
				output << endl;
		}
		return output;
	}

	template<class T>
	friend Matrix operator + (const Matrix<T>& m1, const Matrix<T>& m2)
	{		
		if (m1.width == m2.width && m1.height == m2.height)
		{			
			Matrix <T> result(m1.width, m1.height);
			int length = m1.width * m2.width;
			for (int i = 0; i < length; i++)
			{
				result.arr[i] = m1.arr[i] + m2.arr[i];
			}
			return result;
		}
		else
		{
			cout << "matrixes sizes are different\n";
			exit(1);
		}
	}

	template<class T>
	friend Matrix& operator - (Matrix<T> m1, Matrix<T> m2)
	{
		if (m1.width == m2.width && m1.height == m2.heigth)
		{
			Matrix <T> result(m1.width, m1.height);
			int length = m1.width * m2.width;
			for (int i = 0; i < length; i++)
			{
				result[i] = m1[i] - m2[i];
			}
			return result;
		}
		else
			cout << "matrixes sizes are different\n";
		return m1;
	}

	T& operator()(int iWidth, int iHeight)
	{
		if (correctIdx(iWidth, width) && correctIdx(iHeight, height))
		{
			return arr[iHeight * width + iWidth];
		}
		else
		{
			ProgCrash("index is out of range");
		}
	}

	T& operator()(int iWidth, int iHeight) const
	{
		if (correctIdx(iWidth, width) && correctIdx(iHeight, height))
		{
			return arr[iHeight * width + iWidth];
		}
		else
		{
			ProgCrash("index is out of range");
		}
	}

	T getMax()
	{
		T max = arr[0];
		for (int i = 0; i < width * height; i++)
		{
			max = arr[i] > max ? arr[i] : max;
		}
		return max;
	}
	
	T getMin()
	{
		T min = arr[0];
		for (int i = 0; i < width * height; i++)
		{
			min = arr[i] < min ? arr[i] : min;
		}
		return min;
	}
};

