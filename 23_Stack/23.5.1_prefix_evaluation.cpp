#include <iostream>
#include <stack>
using namespace std;

int to_num(char a)
{
    return a - '0';
}

int main()
{
    string expression;

    cin >> expression;

    stack<int> stk;

    int num1, num2;

    for (int i = expression.size() - 1; i >= 0; i--)
    {
        if (expression[i] == '+')
        {
            num1 = stk.top();
            stk.pop();
            num2 = stk.top();
            stk.pop();

            stk.push(num1 + num2);
        }
        else if (expression[i] == '-')
        {
            num1 = stk.top();
            stk.pop();
            num2 = stk.top();
            stk.pop();

            stk.push(num1 - num2);
        }
        else if (expression[i] == '*')
        {
            num1 = stk.top();
            stk.pop();
            num2 = stk.top();
            stk.pop();

            stk.push(num1 * num2);
        }
        else if (expression[i] == '/')
        {
            num1 = stk.top();
            stk.pop();
            num2 = stk.top();
            stk.pop();

            stk.push(num1 / num2);
        }
        else if (expression[i] >= '0' && expression[i] <= '9')
        {
            stk.push(to_num(expression[i]));
        }
    }

    cout<<stk.top();
}