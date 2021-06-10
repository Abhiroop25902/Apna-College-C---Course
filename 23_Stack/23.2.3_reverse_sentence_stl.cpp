#include <iostream>
#include <string>
#include <sstream>
#include <stack>
using namespace std;

int main()
{
    int t;

    cin >> t;
    cin.ignore();

    stack<string> stk;
    string sentence;
    string word;

    while (t--)
    {
        getline(cin, sentence);

        stringstream str(sentence);

        while (str >> word)
            stk.push(word);

        while (!stk.empty())
        {
            cout << stk.top() << " ";
            stk.pop();
        }

        cout << '\n';
    }
}
