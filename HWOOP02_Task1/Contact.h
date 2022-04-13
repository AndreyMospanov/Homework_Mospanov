#pragma once
#include <iostream>
#include <string.h>
using namespace std;

class Contact
{
	char* name;
	char* phoneHome;
	char* phoneWork;
	char* phoneMobile;
	string info;

	void assign(const char* source, char* destination)
	{
		if (destination)
		{
			strcpy_s(destination, strlen(source) + 1, source);
		}
	}
	void deleteData(char* data)
	{
		if (data)
			delete[] data;
	}

public:

	Contact(const char* _name, const char* pH, const char* pW, const char* pM, string _info) : name{ _name ? new char[strlen(_name) + 1] : nullptr}, phoneHome{pH ? new char[strlen(pH) + 1] : nullptr}, phoneWork{pW ? new char[strlen(pW) + 1] : nullptr}, phoneMobile{pM ? new char[strlen(pM) + 1] : nullptr}, info{_info}
	{		
		assign(_name, name);
		assign(pH, phoneHome);
		assign(pW, phoneWork);
		assign(pM, phoneMobile);
	}

	Contact(char* _name, char* pH) : Contact(_name, pH, nullptr, nullptr, "")
	{
		assign(" ", phoneMobile);
		assign(" ", phoneWork);
	}

	Contact() :Contact("noname", nullptr, nullptr, nullptr, "") {}

	~Contact()
	{
		cout << "Contact " << name << "deleted.\n";
		deleteData(name);
		deleteData(phoneHome);
		deleteData(phoneWork);
		deleteData(phoneMobile);
	}

	void Print()
	{
		cout << "Name: " << name << endl;
		cout << "Home: " << phoneHome << endl;
		cout << "Work: " << phoneWork << endl;
		cout << "Mobile: " << phoneMobile << endl;
		cout << "additional information: " << info << endl;
		system("pause");
		system("cls");
	}

	void Edit();
};

