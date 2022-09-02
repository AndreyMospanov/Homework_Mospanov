#include <iostream>
#include "Queue.h"
using namespace std;
/*создать имитационную модель "остановка маршрутного такси"
ввод инфо: среднее время между появлением пассажиров на остановке в разное время
ср. время между появлениями автобусов на остановке
тип: конечная/нет
Определить ср. время пребывания человека на остановке и достаточный интервал движения, чтобы на остановке находилось не более N людей*/
int totalPeople = 0;
int totalTransported = 0;
int totalBuses = 0;

void ReportStats(Queue& pass, int time)
{
    cout << "by " << 7 + time / 60 << " hours stats:\ntotal people = " << totalPeople << ". total buses = " << totalBuses << "\ntotal transported = " << totalTransported << ". people remain on the station = " << pass.Length() << endl << endl;
}

int main()
{
    int deltaPass[5];//среднее время между появлением пассажиров на остановке в разное время
    int deltaBus;//ср. время между появлениями автобусов на остановке
    bool endLine;//конечная
    int desiredRemain;//желаемый остаток людей, который нельзя превышать
    Queue pass(1000);//ожидающие пассажиры на остановке
    Queue bus(25);//автобус    
    int AverageWait = 0;

    cout << "Enter people arriving interval for 7-00 - 9-00, people per minute \n";//0-120min
    cin >> deltaPass[0];
    cout << "Enter people arriving interval for 9-00 - 16-00, people per minute \n";//120-540
    cin >> deltaPass[1];
    cout << "Enter people arriving interval for 16-00 - 19-00, people per minute \n";//540-720
    cin >> deltaPass[2];
    cout << "Enter people arriving interval for 19-00 - 23-00, people per minute \n";//720-960
    cin >> deltaPass[3];
    cout << "Enter bus interval\n";
    cin >> deltaBus;
    cout << "is it end of the line? 1 - yes, 0 - no\n";
    cin >> endLine;
    cout << "set desired remain of people to calculate new bus interval\n";
    cin >> desiredRemain;
    
    //создать очереди, имитирующие очереди людей и очереди = автобусы. Перекидывать людей туда
    //возьмём время работы транспорта с 7-00 до 23-00 - это 960 минут
    for (int i = 0; i < 961; i++)
    {
        //set interval
        if (i < 120)
        {
            deltaPass[4] = deltaPass[0];
        }        
        else if (i < 540)
        {
            deltaPass[4] = deltaPass[1];
        }        
        else if (i < 720)
        {
            deltaPass[4] = deltaPass[2];
        }
        else
        {
            deltaPass[4] = deltaPass[3];
        }

        //action
        
        for (int j = 0; j < deltaPass[4]; j++)
        {
            if (!pass.isFull())
            {
                pass.Add(i);
                totalPeople++;
            }
        }         
        
        if (i % deltaBus == 0)
        {
            bus.RandomClear(endLine);
            totalBuses++;
        }

        while (!bus.isFull() && !pass.isEmpty())
        {
            AverageWait += i - pass.NextToOut();           
            bus.Add(pass.Extract());
            totalTransported++;
        }   

        //report
        if (i == 120 || i == 540 || i == 720 || i == 960)
        {
            ReportStats(pass, i);
        }
        if (pass.Length() > desiredRemain && deltaBus > 1)
        {
            cout << "queue of people at the station = " << pass.Length() << endl;
            deltaBus--;
            cout << "new bus interval = " << deltaBus << "min. time = " << 7 + i / 60 << "h " << i % 60 <<"min" << endl;
        }
    }

    cout << "Calculated interval = " << deltaBus << endl;

    cout << "Average time of wait of passangers = " << AverageWait / totalTransported << endl;
}