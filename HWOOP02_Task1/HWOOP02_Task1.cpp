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
	for (int i = 0; i < phoneBook.size(); i++)
	{
		cout << i << " ";
		phoneBook[i].Print();
	}
}
int main()
{
	int choice;
	vector <Contact> phoneBook;
	Contact temp;
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
			cout << "Add contact\n";
			phoneBook.push_back(temp);
			phoneBook[phoneBook.size() - 1].Edit();
			phoneBook[phoneBook.size() - 1].Print();
			break;
		}			
		case 2:
		{
			int toDelete;
			cout << "Enter number of Contact to delete\n";
			cin >> toDelete;
			phoneBook.erase(phoneBook.begin() + toDelete - 1);
			break;
		}
		case 3:
		{
			break;
		}
		case 4:
		{
			break;
		}
		default:
			break;
		}

	} while (choice != 0);
}