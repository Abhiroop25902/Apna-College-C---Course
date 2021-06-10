#include <iostream>
#include <stack>
using namespace std;

bool balanced_parenthesis()
{
    stack<char> stk;
    char c;

    while (cin >> c)
    {
        if (c == '(' || c == '+' || c == '-' || c == '/' || c == '*')
            stk.push(c);
        else if (c == ')')
        {
            if (stk.empty())
                return false;
            else if (stk.top() == '(')
                return false;
            else
            {
                bool done = false;
                while (!stk.empty() && !done)
                {
                    if (stk.top() == '(')
                        done = true;

                    stk.pop();
                }

                if (done == false)
                    return false;
            }
        }
    }

    if (!stk.empty())
        return false;

    return true;
}

int main()
{
    cout << !balanced_parenthesis();
}
