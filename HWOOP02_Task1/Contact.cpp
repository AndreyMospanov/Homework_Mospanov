#include "Contact.h"

void Contact :: Edit()
{
	char* temp;
	int choice;
	cout << "Choose data to edit\n";
	cout << "1. Name\n2. Phone Home\n3. PhoneWork\n4. PhoneMobile\n";
	cin >> choice;
	switch (choice)
	{
	case 1:
	{
		cout << "Enter name: ";
		cin >> temp;
		name = temp;
		break;
	}
	case 2:
	{
		cout << "Enter home phone: ";
		cin >> temp;
		phoneHome = temp;
		break;
	}
	case 3:
	{
		cout << "Enter phone at work: ";
		cin >> temp;
		phoneWork = temp;
		break;
	}
	case 4:
	{
		cout << "Enter mobile phone: ";
		cin >> temp;
		phoneMobile = temp;
		break;
	}
	default:
		break;
	}
	system("cls");
}