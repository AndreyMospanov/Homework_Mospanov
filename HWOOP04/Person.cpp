#include "Person.h"

void Person::setData(const char* name, int choice)
{	
	switch (choice)
	{
	case 1://change last name
	{
		if (lName != nullptr)
			delete[] lName;

		if (name == nullptr)
		{
			lName = nullptr;			
		}
		else
		{
			lName = new char[strlen(name) + 1];
			strcpy_s(lName, strlen(name) + 1, name);
		}
		break;
	}
	case 2://change first name
	{
		if (fName != nullptr)
			delete[] fName;

		if (name == nullptr)
		{
			fName = nullptr;			
		}
		else
		{
			fName = new char[strlen(name) + 1];
			strcpy_s(fName, strlen(name) + 1, name);
		}
		break;
	}
	case 3://change fathers name
	{
		if (fthrName != nullptr)
			delete[] fthrName;

		if (name == nullptr)
		{
			fthrName = nullptr;			
		}
		else
		{
			fthrName = new char[strlen(name) + 1];
			strcpy_s(fthrName, strlen(name) + 1, name);
		}
		break;
	}
	default:
		break;
	}		
}

void Person::setFName(const char* name)
{
	Person::setData(name, 2);
}

void Person::setLName(const char* name)
{
	Person::setData(name, 1);
}

void Person::setFthrName(const char* name)
{
	Person::setData(name, 3);
}

void Person:: setInfo()
{
	cout << "set info:\n";
	cin >> info;
}

void Person::setInfo(string data)
{
	info = data;
}
