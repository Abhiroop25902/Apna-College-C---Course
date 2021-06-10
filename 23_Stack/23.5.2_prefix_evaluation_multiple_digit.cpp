#include <iostream>
#include <stack>
#include <algorithm> //for reverse()
#include <sstream>   //string stream
using namespace std;

int main()
{
    string expression;

    getline(cin, expression);

    reverse(expression.begin(), expression.end());

    stringstream str(expression);

    string element;
    double num1, num2;
    stack<double> stk;

    while (str >> element)
    {
        if (element == "+")
        {
            num1 = stk.top();
            stk.pop();
            num2 = stk.top();
            stk.pop();

            stk.push(num1 + num2);
        }
        else if (element == "-")
        {
            num1 = stk.top();
            stk.pop();
            num2 = stk.top();
            stk.pop();

            stk.push(num1 - num2);
        }
        else if (element == "*")
        {
            num1 = stk.top();
            stk.pop();
            num2 = stk.top();
            stk.pop();

            stk.push(num1 * num2);
        }
        else if (element == "/")
        {
            num1 = stk.top();
            stk.pop();
            num2 = stk.top();
            stk.pop();

            stk.push(num1 / num2);
        }
        else
        {
            reverse(element.begin(), element.end());
            stk.push(stod(element));
        }
    }

    cout << stk.top();
}