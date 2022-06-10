#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Student
{
    string name;
    int age, id, course;
public:
    Student()
    {
        cout << "Student created\n";
        name = "new student";
        age = 17;
        id = 0;
        course = 1;
    }

    Student(string new_name, int new_age, int new_id, int new_course)
    {
        cout << "Student " << new_name << " created\n";
        name = new_name;
        age = new_age;
        id = new_id;
        course = new_course;
    }

    ~Student()
    {
        cout << "Student " << name << " deleted\n";
    }

    void Edit()
    {
        cout << "Enter name: ";
        cin.ignore(1024, '\n');
        getline(cin, name);
        cout << "Enter age: ";
        cin >> age;
        cout << "Enter id: ";
        cin >> id;
        cout << "Enter course: ";
        cin >> course;
    }
    void Print()
    {
        cout << "Student " << name << ", age " << age << ". id " << id << ", course " << course << endl;
    }
};

vector<Student> AddSampleStudents()
{
    vector<Student> db;
    db.push_back(Student("Vasya Vasin", 17, 1, 1));
    db.push_back(Student("Petya Savin", 16, 2, 1));
    db.push_back(Student("Alex Jones", 23, 3, 5));
    db.push_back(Student("Johan Steinberg", 19, 4, 3));
    db.push_back(Student("Francois Grenouille", 20, 5, 4));    
    return db;
}
int main()
{
    int choice;
    vector<Student> db;
    cout << "Do you want to add sample students?\n1 - yes, other number - no\n";
    cin >> choice;
    if (choice == 1)
    {        
        db = AddSampleStudents();        
    }
    else
    {
        cout << "how much students do you want to add?\n";
        cin >> choice;
        for (int i = 0; i < choice; i++)
        {
            db.push_back(Student());
            db.at(db.size() - 1).Edit();
        }
    }
    cout << "--------------------\n";
    for (int i = 0; i < db.size(); i++)
    {
        db[i].Print();
    }
    cout << "--------------------\n";
}
