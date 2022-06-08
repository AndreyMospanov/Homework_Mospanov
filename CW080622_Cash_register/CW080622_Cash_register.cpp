#include <iostream>
#include <vector>
using namespace std;

//Андрей Моспанов

class Cashier
{
    vector <double> sales;
    
public:
    bool inMenu = true;
    void PrintMenu()
    {
        cout << "0: exit\n1: new sale\n2: sales list\n3: cancel last sale\n4: show all sales\n5: min & max sale\n";
    }
    void menu(int num)
    {
        double sale;
        switch (num)
        {
        case 0:
        {
            inMenu = false;
            break;
        }
        case 1:
        {
            cout << "New sale: ";
            cin >> sale;
            sales.push_back(sale);
            break;
        }
        case 2:
        {
            cout << "Sales list:\n";
            for (int i = 0; i < sales.size(); i++)
            {
                cout << i + 1 << ". " << sales[i] << "$\n";
            }
            break;
        }
        case 3:
        {
            cout << "cancel last sale ";
            sales.pop_back();
            break;
        }
        case 4:
        {
            double sum = 0;
            for (int i = 0; i < sales.size(); i++)
            {
                sum += sales[i];
            }
            cout << "You have done: " << sales.size() + 1 << " sales worth " << sum << "$\n";
            break;
        }
        case 5:
        {
            double min, max;
            min = sales[0];
            max = sales[0];
            for (int i = 0; i < sales.size(); i++)
            {
                min = sales[i] < min ? sales[i] : min;
                max = sales[i] > max ? sales[i] : max;
            }
            cout << "max sale = " << max << "$ , min sale = " << min << "$\n";
            break;
        }
            
        default:
            break;
        }
    }
};

int main()
{
    Cashier saleToday;
    int chooseMenu;
    saleToday.PrintMenu();
    
    while (saleToday.inMenu)
    {
        cout << " enter number of menu\n";
        cin >> chooseMenu;
        saleToday.menu(chooseMenu);
    }
}
