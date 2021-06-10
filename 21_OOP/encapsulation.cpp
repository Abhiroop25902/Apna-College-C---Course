#include <bits/stdc++.h>
using namespace std;

class A
{
private:
    int b;
    void funcB()
    {
        cout<<"Func B"<<endl;
    }
    
public:
    int a;
    void funcA()
    {
        cout<<"Func A"<<endl;
    }

protected:
    int c;
    void funcC()
    {
        cout<<"Func C"<<endl;
    }
    
};




int main()
{
    A obj;
    obj.funcA();
    return 0;
}