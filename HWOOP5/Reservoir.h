#pragma once
#include <iostream>
#include <string>
using namespace std;
class Reservoir
{
	char* name;
	char* type;
	int length, width, depth;

	void remove()
	{
		if (name != nullptr)
		{
			delete[] name;
		}
		if (type != nullptr)
		{
			delete[] type;
		}
	}

	void SetCharArr(char*& dest, const char* source)
	{
		if (dest != nullptr)
		{
			delete[] dest;
		}
		dest = new char[strlen(source) + 1];
		strcpy_s(dest, strlen(source) + 1, source);
	}

public:
	Reservoir(const char* Name, const char* Type, int Length, int Width, int depth):name{Name ? new char[strlen(Name) + 1]:nullptr}, type{ Type ? new char[strlen(Type) + 1] : nullptr }, length{Length}, width{Width}, depth{depth}
	{
		if (Name != nullptr)
		{
			strcpy_s(name, strlen(Name) + 1, Name);
			//cout << "constructor " << name << endl;
		}
		if (Type != nullptr)
		{
			strcpy_s(type, strlen(Type) + 1, Type);
		}
	}

	explicit Reservoir(const char* name) :Reservoir(name, nullptr, 0, 0, 0){}
	Reservoir()
	{
		name = nullptr;
		type = nullptr;
		length = 0;
		width = 0;
		depth = 0;
		//cout << " empty constructor \n";
	}
	Reservoir(const Reservoir& orig):name{ orig.name ? new char[strlen(orig.name) + 1] : nullptr }, type{ orig.type ? new char[strlen(orig.type) + 1] : nullptr }, length{ orig.length }, width{ orig.width }, depth{ orig.depth }
	{
		//cout << "copy constructor\n";
		if (orig.name != nullptr)
		{
			strcpy_s(name, strlen(orig.name) + 1, orig.name);
		}
		if (orig.type != nullptr)
		{
			strcpy_s(type, strlen(orig.type) + 1, orig.type);
		}		
	}

	Reservoir operator = (Reservoir& res)
	{
		//cout << "reloaded operator = " << res.name << endl;
		if (*this == res)
		{
			return *this;
		}		
		SetCharArr(name, res.name);
		SetCharArr(type, res.type);
		length = res.length;
		width = res.width;
		depth = res.depth;
		return *this;
	}

	bool operator == (const Reservoir& res2)
	{
		if (name == res2.name && type == res2.type)
		{
			if (length = res2.length && width == res2.width && depth == res2.depth)
				return true;
		}
		return false;
	}

	~Reservoir()
	{
		//if(name)
			//cout << "destructor " << name << endl;
		remove();
		//cout << "destruct successfull\n";		
	}

	const char* GetType() const
	{
		return type;
	}

	int Square()
	{
		return length * width;
	}

	int Volume()
	{
		return Square() * depth;
	}

	void Edit()
	{
		char Name[20];
		char Type[20];
		cout << "enter name\n";		
		cin >> Name;
		SetCharArr(name, Name);
		
		cout << "enter type\n";
		cin >> Type;
		SetCharArr(type, Type);
		
		cout << "enter length\n";
		cin >> length;
		cout << "enter width\n";
		cin >> width;
		cout << "enter depth\n";
		cin >> depth;
		cout << "You've created new object\n";
		Print();
	}

	void Print() const
	{
		cout << "reservoir " << name << ", type: " << type << ", length = " << length << ", width = " << width << ", depth = " << depth << endl;
	}

};

