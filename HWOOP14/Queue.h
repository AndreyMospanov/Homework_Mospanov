#pragma once
#include<iostream>
#include <time.h>

/*Задание 1.
Добавьте в класс двусвязного списка механизм обработки исключений. На ваш выбор генерируйте исключения 
в случае ошибок. Например, нехватка памяти, попытка 
удаления из пустого списка и т.д.*/
                     
class Queue
{
    int* wait;
    int capacity;
    int length;

public:
    Queue(int m)
    {
        capacity = m;
        wait = new int[capacity];
        length = 0;
    }
    
    ~Queue()
    {
        try
        {
            if (wait == nullptr)
                throw wait;
        }
        catch (int*)
        {
            std::cerr << "Delete error. Wait does not exist\n";
        }
        delete[] wait;
    }

    void Clear()
    {
        try
        {
            if (length == 0)
                throw length;
        }
        catch (int)
        {
            std::cerr << "Queue is clear already\n";
        }

        length = 0;
    }

    void RandomClear(bool endOfTheLine)
    {
        if (!endOfTheLine)
        {
            srand(time(0));
            length = rand() % capacity;
        }
        else
        {
            Clear();
        }
    }

    bool isEmpty()
    {
        return length == 0;
    }

    bool isFull()
    {
        return length == capacity;
    }

    int Length()
    {
        return length;
    }

    void Add(int c)
    {
        if (!isFull())
        {
            wait[length++] = c;
        }
    }

    int Extract()
    {
        try
        {
            if (length == 0)
                throw length;

            int temp = wait[0];
            for (int i = 1; i < length; i++)
            {
                wait[i - 1] = wait[i];
            }
            length--;
            return temp;
        }
        catch (int)
        {
            std::cerr << "queue is empty\n";
            return -1;
        }
    }

    int NextToOut()
    {
        return wait[0];
    }
};

