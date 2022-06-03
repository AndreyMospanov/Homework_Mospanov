
#include <iostream>
#include <string.h>
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
        cout << "You've created new car.\nEnter car name\n";
        cin >> name;
        cout << "Enter mileage\n";
        cin >> mileage;
        cout << "Enter year\n";
        cin >> year;
        cout << "Enter country\n";
        cin >> country;
        cout << "Enter power\n";
        cin >> power;
    }

    void Show()
    {
        cout << "name " << name << "\nmileage " << mileage << "\nyear " << year << "\ncountry " << country << "\npower " << power << endl;
    }
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
    cout << "\n\nYou've created " << numberOfCars << " cars in database\n";
    for (int i = 0; i < numberOfCars; i++)
    {
        db[i].Show();
        cout << "-------------\n";
    }
}
