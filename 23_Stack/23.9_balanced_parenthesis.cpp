#include <iostream>
#include <stack>
using namespace std;

void is_balanced(string &expression)
{
    stack<char> stk;

    for (int i = 0; i < expression.size(); i++)
    {
        if (expression[i] == '(' || expression[i] == '{' || expression[i] == '[')
            stk.push(expression[i]);
        else if (expression[i] == ')')
        {
            if (!stk.empty() && stk.top() == '(')
                stk.pop();
            else
            {
                cout << "no";
                return;
            }
        }
        else if (expression[i] == '}')
        {
            if (!stk.empty() && stk.top() == '{')
                stk.pop();
            else
            {
                cout << "no";
                return;
            }
        }
        else if (expression[i] == ']')
        {
            if (!stk.empty() && stk.top() == '[')
                stk.pop();
            else
            {
                cout << "no";
                return;
            }
        }
    }

    if (stk.empty())
        cout << "yes";
    else
        cout << "no";
}

int main()
{
    string expression;

    cin >> expression;

    is_balanced(expression);
}
