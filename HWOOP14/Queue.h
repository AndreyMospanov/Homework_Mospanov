#pragma once
#include<iostream>
#include <time.h>
using namespace std;
                            
class Queue
{
    int* wait;
    int maxLength;
    int length;

public:
    Queue(int m)
    {
        maxLength = m;
        wait = new int[maxLength];
        length = 0;
    }

    /*Queue(int m, int n)//для создания случайно заполненного автобуса
    {
        maxLength = n;
        length = m + rand() % n ;
        wait = new int[maxLength];
    }*/

    ~Queue()
    {
        delete[] wait;
    }

    void Clear()
    {
        length = 0;
    }

    void RandomClear(bool endOfTheLine)
    {
        if (!endOfTheLine)
        {
            srand(time(0));
            length = rand() % maxLength;
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
        return length == maxLength;
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
        if (!isEmpty())
        {
            int temp = wait[0];
            for (int i = 1; i < length; i++)
            {
                wait[i - 1] = wait[i];
            }
            length--;
            return temp;
        }
        else
            return -1;
    }

    int NextToOut()
    {
        return wait[0];
    }
};

