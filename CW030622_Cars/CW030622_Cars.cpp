
#include <iostream>
#include <string>
#include <stack>
using namespace std;
//марка, пробег, год выпуска, страна, мощность
class Car
{
    string name;
    int mileage;
    int year;
    string country;
    int power;
public:
    void Edit()
    {
        cin.ignore(1024, '\n');
        cout << "You've created new car.\nEnter car name\n";
        getline(cin, name);
        cout << "Enter mileage\n";
        cin >> mileage;
        cout << "Enter year\n";
        cin >> year;
        cin.ignore(1024, '\n');
        cout << "Enter country\n";
        getline(cin, country);
        cout << "Enter power\n";
        cin >> power;
        
    }

    void Show()
    {
        cout << "name " << name << "\nmileage " << mileage << "\nyear " << year << "\ncountry " << country << "\npower " << power << endl;
    }

    int getYear() { return year; }
};

int main()
{
    int numberOfCars;
    cout << "Enter number of cars to add in database\n";
    cin >> numberOfCars;
    Car* db = new Car[numberOfCars];

    for (int i = 0; i < numberOfCars; i++)
    {
        db[i].Edit();
        cout << "-------------\n";        
    }
    //сортировка по году выпуска от новой к старой
    for (int i = 0; i < numberOfCars; i++)
    {
        for (int j = 0; j < numberOfCars - i - 1; j++)
        {
            if (db[i].getYear() > db[j].getYear())
            {
                swap(db[i], db[j]);
            }
        }
    }
    
    cout << "\n\nYou've created " << numberOfCars << " cars in database\n";
    for (int i = 0; i < numberOfCars; i++)
    {
        db[i].Show();
        cout << "-------------\n";
    }
    
}
