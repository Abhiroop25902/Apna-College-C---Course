#include <iostream>
#include <stack>
#include <sstream>
#include <cmath>
using namespace std;

int main()
{
    string expression;

    getline(cin, expression);

    stringstream str(expression);
    string element;
    stack<double> stk;
    double num1, num2;

    while (str >> element)
    {
        if (element == "+")
        {
            num1 = stk.top();
            stk.pop();
            num2 = stk.top();
            stk.pop();

            stk.push(num2 + num1);
        }
        else if (element == "-")
        {
            num1 = stk.top();
            stk.pop();
            num2 = stk.top();
            stk.pop();

            stk.push(num2 - num1);
        }
        else if (element == "*")
        {
            num1 = stk.top();
            stk.pop();
            num2 = stk.top();
            stk.pop();

            stk.push(num2 * num1);
        }
        else if (element == "/")
        {
            num1 = stk.top();
            stk.pop();
            num2 = stk.top();
            stk.pop();

            stk.push(num2 / num1);
        }
        else if (element == "^")
        {
            num1 = stk.top();
            stk.pop();
            num2 = stk.top();
            stk.pop();

            stk.push(pow(num2,num1));
        }
        else
            stk.push(stod(element));
    }

    cout<<stk.top();
}