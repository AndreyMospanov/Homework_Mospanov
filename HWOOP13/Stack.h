#pragma once
#include <iostream>
#include <string>

/* Ћабораторна€ работа, «адание 2
ѕерепишите класс stack одного из предыдущих домашних заданий таким образом, чтобы генерировать исключени€ дл€ такого количества условий, какое вы считаете приемлемым.
Ќапример, невозможность выделить нужное количество пам€ти, переполнение стека и т.д*/
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
        std::string stackOverflow = "stack overflow";
        try
        {
            if (!isFull())
            {
                st[++top] = c;
            }
            else
            {
                throw stackOverflow;                
            }
        }
        catch (std::string message)
        {
            std::cerr << message;
        }
		
	}

	char Pop()
	{
        try
        {
            if (!isEmpty())
            {
                return st[top--];
            }
            else
            {
                throw st[top];
            }
        }
        catch (char)
        {
            std::cerr << "Can't pop element! Stack is empty\n";
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

