#include <bits/stdc++.h>
using namespace std;

//function overloading

class AppaCollege
{
public:
    void fun()
    {
        cout << "No parameters";
    }

    void fun(int a)
    {
        cout << "Parameter: " << a;
    }
    void fun(char a)
    {
        cout << "Parameter: " << a;
    }
};

//operator overloading

class Complex
{
    int real, img;

public:
    Complex(int r = 0, int i = 0)
    {
        real = r;
        img = i;
    }

    Complex operator+(Complex const &obj)
    {
        Complex res;
        res.real = real + obj.real;
        res.img = img + obj.img;
        return res;
    }

    void display()
    {
        cout << real << " + i" << img << endl;
    }
};

//runtime polymorphism

class base
{
public:
    virtual void print()
    {
        cout << "Base Classc print"<<endl;
    }
    void display()
    {
        cout << "Base Class Display"<<endl;
    }
};

class derived: public base
{
public:
    void print()
    {
        cout << "Derived Classc print"<<endl;
    }
    void display()
    {
        cout << "Deerived Class Display"<<endl;
    }
};

int main()
{
    base *baseptr;
    derived d;

    baseptr = &d;

    baseptr->display();
    baseptr->print();
    return 0;
}