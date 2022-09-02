#pragma once
#include <iostream>
#include <string>
using namespace std;

class Stack
{
	enum {Empty = -1, Full = 20};
	char st[Full + 1];
	int top;

public:
	Stack()
	{		
		top = Empty;
	}

	bool isEmpty()
	{
		return top == Empty;
	}

	bool isFull()
	{
		return top == Full;
	}

	void Push(char c)
	{
		if (!isFull())
		{
			st[++top] = c;
		}
		else
		{
			cout << "stack overflow\n";
			exit(1);
		}
	}

	char Pop()
	{
		if (!isEmpty())
		{
			return st[top--];
		}
		else
		{
			return 0;
		}
	}

	char Peek()
	{
		return st[top];
	}

	int Count()
	{
		return top + 1;
	}
};

