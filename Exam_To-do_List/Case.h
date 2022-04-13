#pragma once
#include <iostream>
#include <string>
#include <Windows.h>

using namespace std;

/*Х название; Х приоритет; Х описание; Х дата, врем€ исполнени€. */
class Case
{
	string name;
	enum level
	{
		high,
		normal,
		low	
	};
	level priority;
	string description;
	SYSTEMTIME deadline;
public:
	Case()
	{
		name = "new case";
		priority = normal;
		description = "new case description";
		GetLocalTime(&deadline);
	}
	Case(string name, int priority, string description, int year, int month, int day, int hour)
	{
		this->name = name;
		this->priority = static_cast<level>(priority - 1);
		this->description = description;
		this->deadline.wYear = year;
		this->deadline.wMonth = month;
		this->deadline.wDay = day;
		this->deadline.wHour = hour;
	}
	string getName()
	{
		return name;
	}
	level getPriority()
	{
		return priority;
	}
	level setPriority(int num)
	{
		priority = static_cast<level>(num - 1);
	}
	string getDescription()
	{
		return description;
	}
	SYSTEMTIME getDeadline()
	{
		return deadline;
	}

	void Edit();
	
	void Print();
	
};

