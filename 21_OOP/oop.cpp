#include <bits/stdc++.h>
using namespace std;

class student
{

    string name;

public:
    int age;
    bool gender;

    student()
    {
        cout << "Default" << endl;
    } //default constructor

    student(string s, int a, bool g)
    {
        cout << "Parameterised" << endl;
        name = s;
        age = a;
        gender = g;
    } //parameterised constructor

    student(student &s)
    {
        cout << "Copy" << endl;
        name = s.name;
        age = s.age;
        gender = s.gender;
    }

    ~student()
    {
        cout << "Destruction" << endl;
    }

    void setName(string s)
    {
        name = s;
    }

    void getName()
    {
        cout << "Name = " << name << endl;
    }

    void printInfo()
    {
        getName();
        cout << "Age = " << age << endl;
        cout << "Gender = " << gender << endl;
    }

    bool operator==(student &a)
    {
        return (name == a.name && age == a.age && gender == a.gender);
    }
};

int main()
{
    // student arr[1];

    // for (auto &i : arr)
    // {
    //     string s;
    //     cin >> s;
    //     i.setName(s);
    //     cin >> i.age;
    //     cin >> i.gender;
    // }

    // for (auto i : arr)
    //     i.printInfo();

    student s("Abhiroop", 18, 1);
    //s.printInfo();
    student b("xyz",21,0);
    student c = s;

    if (b == s)
        cout << "same" << endl;
    else
    {
        cout << "Not Same" << endl;
    }

    return 0;
}