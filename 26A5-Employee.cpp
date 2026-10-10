#include <iostream>
#include <string>
using namespace std;

class Employee
{
private:
    string name;
    int age;
    string department;

public:
    void setName(string name)
    {
        this->name = name;
    }

    void setAge(int age)
    {
        this->age = age;
    }

    void setDepartment(string department)
    {
        this->department = department;
    }

    virtual void ShowEmployee()
    {
        cout << "name: " << name << endl;
        cout << "age: " << age << endl;
        cout << "department: " << department << endl;
    }
};

class Manager : public Employee
{
private:
    int level;

public:
    void setLevel(int level)
    {
        this->level = level;
    }

    void ShowEmployee()
    {
        cout << "level: " << level << endl;
    }
};


int main()
{
    Employee emp1;
    Employee emp2;
    Manager mana;

    string n1, n2;
    int ag1, ag2;
    string d1, d2;
    int l1;

    cout << "Enter the name of the employee 1: " << endl;
    cin >> n1;
    cout << "Enter the age of the employee 1: " << endl;
    cin >> ag1;
    cout << "Enter the department of the employee 1: " << endl;
    cin >> d1;
    cout << "Enter the name of the employee 2: ";
    cin >> n2;
    cout << "Enter the age of the employee 2: " << endl;
    cin >> ag2;
    cout << "Enter the department of the employee 2: " << endl;
    cin >> d2;

    cout << "Enter the level of the manager: " << endl;
    cin >> l1;

    emp1.setName(n1);
    emp1.setAge(ag1);
    emp1.setDepartment(d1);
    emp1.ShowEmployee();

    emp2.setName(n2);
    emp2.setAge(ag2);
    emp2.setDepartment(d2);
    emp2.ShowEmployee();

    mana.setLevel(l1);
    mana.ShowEmployee();

    system("pause");
    return 0;
}
