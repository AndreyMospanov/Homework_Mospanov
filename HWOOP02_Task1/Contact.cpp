#include "Contact.h"
#include <string>

void Contact :: Edit()
{
	char _name[80];
	char _pH[80];
	char _pW[80];
	char _pM[80];
	int choice;
	cout << "Choose data to edit\n";
	cout << "1. Name\n2. Phone Home\n3. PhoneWork\n4. PhoneMobile\n";
	cin >> choice;
	switch (choice)
	{
	case 1:
	{
		if (name)
		{
			delete[] name;
		}
		cout << "Enter name: ";
		cin >> _name;
		name = new char[strlen(_name) + 1];
		strcpy_s(name, strlen(_name) + 1, _name);
		break;
	}
	case 2:
	{
		if (phoneHome)
		{
			delete[] phoneHome;
		}
		cout << "Enter home phone: ";
		cin >> _pH;
		phoneHome = new char[strlen(_pH) + 1];
		strcpy_s(phoneHome, strlen(_pH) + 1, _pH);
		break;
	}
	case 3:
	{
		if (phoneWork)
		{
			delete[] phoneWork;
		}
		cout << "Enter phone at work: ";
		cin >> _pW;
		phoneWork = new char[strlen(_pW) + 1];
		strcpy_s(phoneWork, strlen(_pW) + 1, _pW);		
		break;
	}
	case 4:
	{
		if (phoneMobile)
		{
			delete[] phoneMobile;
		}
		cout << "Enter mobile phone: ";
		cin >> _pM;
		phoneMobile = new char[strlen(_pM) + 1];
		strcpy_s(phoneMobile, strlen(_pM) + 1, _pM);
		break;
	}
	default:
		break;
	}
	system("cls");
}

void Contact::AddContact()
{
	cout << "debug add contact\n";
	char _name[80];
	char _pH[80];
	char _pW[80];
	char _pM[80];

	cout << "Enter name: ";
	cin >> _name;
	if (name)
	{
		delete[] name;
	}
	name = new char[strlen(_name) + 1];
	strcpy_s(name, strlen(_name) + 1, _name);	

	if (phoneHome)
	{
		delete[] phoneHome;
	}
	cout << "Enter phone at home: ";
	cin >> _pH;
	phoneHome = new char[strlen(_pH) + 1];	
	strcpy_s(phoneHome, strlen(_pH) + 1, _pH);	

	if (phoneWork)
	{
		delete[] phoneWork;
	}
	cout << "Enter phone at work: ";
	cin >> _pW;
	phoneWork = new char[strlen(_pW) + 1];
	strcpy_s(phoneWork, strlen(_pW) + 1, _pW);
	
	if (phoneMobile)
	{
		delete[] phoneMobile;
	}
	cout << "Enter mobile phone: ";
	cin >> _pM;
	phoneMobile = new char[strlen(_pM) + 1];
	strcpy_s(phoneMobile, strlen(_pM) + 1, _pM);
	
	cin.ignore(1024, '\n');
	cout << "enter additional info\n";
	getline(cin, info);	

	system("cls");
}