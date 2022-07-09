#pragma once
#include <iostream>
#include <string>
using namespace std;

class Person
{
	char* lName;
	char* fName;
	char* fthrName;
	string info;
public:

	Person(const char* lastName, const char* firstName, const char* fathersName, string info)
	{
		setLName(fName);
		setFName(firstName);
		setFthrName(fathersName);
		setInfo(info);
	}
	Person()
	{
		lName = nullptr;
		fName = nullptr;
		fthrName = nullptr;
		info = "";
	}

	~Person()
	{
		if (lName != nullptr)
		{
			delete[] lName;
		}
		if (fName != nullptr)
		{
			delete[] fName;
		}
		if (fthrName != nullptr)
		{
			delete[] fthrName;
		}
	}

	void setData(const char* name, int choice);
	void setFName(const char* name);
	void setLName(const char* name);
	void setFthrName(const char* name);
	void setInfo();
	void setInfo(string data);
	void Print()
	{
		cout << lName << " " << fName << " " << fthrName << ": " << info << endl;
	}

	const char* LName()
	{
		return lName;
	}
	const char* FName()
	{
		return fName;
	}
	const char* FthrName()
	{
		return fthrName;
	}
	string Info()
	{
		return info;
	}

};

