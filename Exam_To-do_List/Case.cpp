#include "Case.h"
#include <iostream>
#include <string>
#include <Windows.h>

using namespace std;

	void Case::Edit()
	{
		//set name
		cin.ignore(1024, '\n');
		cout << "Enter name of case to do\n";
		getline(cin, name);

		//set priority
		cout << "set priority of this case\n1: high\n2: normal\n3: low\n";
		int levelChoose = 0;
		do
		{
			cin >> levelChoose;
			if (levelChoose > 3 || levelChoose < 1)
			{
				cout << "enter correct number from 1 to 3\n";
			}
		} while (levelChoose > 3 || levelChoose < 1);

		priority = static_cast<level>(levelChoose - 1);

		//set description
		cin.ignore(1024, '\n');
		cout << "Enter description of case to do\n";
		getline(cin, description);

		//set deadline
		int year, month, day, hour;
		cout << "Enter deadline of case to do\n";
		do
		{
			cout << "Set year: ";
			cin >> year;
			if (year < deadline.wYear)
			{
				cout << "year is not correct\n";
			}
		} while (year < deadline.wYear);
		deadline.wYear = year;

		do
		{
			cout << "Set month: ";
			cin >> month;
			if (month > 12 || month < 1)
			{
				cout << "month is not correct\n";
			}
		} while (month > 12 || month < 1);
		deadline.wMonth = month;

		bool correctDay;
		do
		{
			correctDay = true;
			cout << "Set day: ";
			cin >> day;

			if (month == 4 || month == 6 || month == 9 || month == 11)
			{
				if (day > 30 || day < 1)
				{
					cout << "day is not correct\n";
					correctDay = false;
				}
			}
			else if (month == 2 && year % 4 == 0)
			{
				if (day > 29 || day < 1)
				{
					cout << "day is not correct\n";
					correctDay = false;
				}
			}
			else if (month == 2)
			{
				if (day > 28 || day < 1)
				{
					cout << "day is not correct\n";
					correctDay = false;
				}
			}
			else
			{
				if (day > 31 || day < 1)
				{
					cout << "day is not correct\n";
					correctDay = false;
				}
			}

		} while (!correctDay);
		deadline.wDay = day;

		do
		{
			cout << "Set hour: ";
			cin >> hour;
			if (hour > 23 || hour < 0)
			{
				cout << "hour is not correct\n";
			}
		} while (hour < 0 || hour > 23);
		deadline.wHour = hour;
	}

	void Case::Print()
	{
		cout << name << endl;
		cout << "priority: ";
		switch (priority)
		{
		case 0:
		{
			cout << "high\n";
			break;
		}
		case 1:
		{
			cout << "normal\n";
			break;
		}
		case 2:
		{
			cout << "low\n";
			break;
		}
		}
		cout << description << endl;
		cout << "To be done by " << deadline.wYear << "/" << deadline.wMonth << "/" << deadline.wDay << " at " << deadline.wHour << ":00\n\n";
	}


