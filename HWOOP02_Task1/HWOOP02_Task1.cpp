#include <iostream>
#include <vector>
#include <string>
#include "Contact.h"

/*Тема: Конструкторы, деструкторы
Задание.
Создайте приложение "Телефонная книга". Необходимо хранить данные об абоненте (ФИО, домашний телефон, 
рабочий телефон, мобильный телефон, дополнительная информация о контакте) внутри соответствующего класса. Наполните класс переменными-членами, функциями-членами, конструкторами, inline-функциями-членами, используйте инициализаторы, реализуйте деструктор. 
Обязательно необходимо выделять динамически память под ФИО. Предоставьте пользователю возможность добавлять новых абонентов, удалять абонентов, искать абонентов по ФИО, показывать всех абонентов, сохранять информацию в файл и загружать из файла*/

void ShowContacts(vector <Contact> &phoneBook)
{
	cout << "void show contacts\n";
	for (int i = 0; i < phoneBook.size(); i++)
	{
		cout << i + 1 << "). ";
		phoneBook[i].Print();
	}
	system("pause");
}

void FindContact(string &toFind, vector <Contact>& phoneBook)
{
	bool finded = false;
	for (int i = 0; i < phoneBook.size(); i++)
	{
		if (phoneBook[i].Name().find(toFind) != string::npos)
		{
			phoneBook[i].Print();
			finded = true;
		}					
	}
	if (!finded)
	{
		cout << "Nothing found\n";
	}
}
int main()
{
	int choice;
	vector <Contact> phoneBook;
	
	do
	{
		cout << "Welcome to Phonebook!\nOptions:\n1. Add contact\n2. Delete contact\n3. Find contact\n4. Show contacts\n5. Edit contact\n6. Add Demo contacts\n";
		do
		{
			cin >> choice;
			if (choice < 1 || choice > 6)
				cout << "number is not correct.Try again\n";
		} while (choice < 1 || choice > 6);
		
		switch (choice)
		{
		case 1:
		{
			Contact temp;
			cout << "Add contact\n";
			phoneBook.emplace_back(temp);			
			phoneBook[phoneBook.size() - 1].AddContact();
			phoneBook[phoneBook.size() - 1].Print();
			break;
		}			
		case 2:
		{
			int toDelete;
			do
			{
				cout << "Choose number of contact to delete\n press 0 to exit\n";
				ShowContacts(phoneBook);
				cin >> toDelete;
				if (toDelete == 0)
				{
					break;
				}
				if (toDelete > phoneBook.size() + 1)
					cout << "number is incorrect\n";
				else
					phoneBook.erase(phoneBook.begin() + toDelete - 1);
			} while (toDelete != 0);
			
			break;
		}
		case 3:
		{
			string toFind;
			int findChoice;
			do
			{
				cout << "type name of contact, you want to find\n";
				cin >> toFind;
				FindContact(toFind, phoneBook);
				cout << "continue? 0 - no, any number - yes\n";
				cin >> findChoice;
			} while (findChoice != 0);

			break;
		}
		case 4:
		{
			cout << "case to show contacts\n";
			ShowContacts(phoneBook);
			break;
		}
		case 5:
		{
			int toEdit;
			do
			{
				cout << "Choose number of contact to edit\n press 0 to exit\n";
				for (int i = 0; i < phoneBook.size(); i++)
				{
					cout <<i+1 <<". " << phoneBook[i].Name();
				}
				cin >> toEdit;
				if (toEdit > phoneBook.size())
					cout << "number is incorrect\n";
				else
					phoneBook[toEdit - 1].Edit();
			} while (toEdit != 0);
			break;
		}
		case 6:
		{
			cout << "Demo Contacts added\n";
			phoneBook.push_back(Contact("Vasya", "789-789", "250-525", "+79990123456", "just Vasya"));
			phoneBook[0].Print();
			phoneBook.push_back(Contact("Vova", "789-987", "543-354", "+79998881234", "Vova from work"));
			phoneBook.push_back(Contact("Anya", "789-879", "876-687", "+79997651111", "girlfriend"));
			phoneBook.push_back(Contact("Vanya", "789-798", "321-213", "+79991112233", "friend"));
			break;
		}
		default:
			break;
		}
		system("cls");
	} while (choice != 0);
}