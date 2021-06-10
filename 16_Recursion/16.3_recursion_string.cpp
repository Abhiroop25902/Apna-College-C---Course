#include <bits/stdc++.h>
using namespace std;

void print_reverse_string(string s)
{
    if(s.length() == 0)
        return ;
      
    string ros = s.substr(1);
    print_reverse_string(ros);
    cout<<s[0];
    

}

void pi_replace(string s)
{
    if(s.length() == 0)
        return;

    string next;

    if(s[0] == 'p' && s[1] == 'i')
    {
        cout<<3.14;
        next = s.substr(2);
    }
    else
    {
        cout<<s[0];
        next = s.substr(1);
    }

    pi_replace(next);
    
}

void tower_of_hanoi(int n,char src, char dest, char helper)
{
    if(n == 0)
        return; //base case

    tower_of_hanoi(n-1,src,helper,dest);
    cout<<"Move from "<< src <<" to "<<dest<<endl;
    tower_of_hanoi(n-1,helper,dest,src);
}

void remove_duplicates(string s)
{
    if(s.length() == 0)
        return;

    for(int i=1;i<s.length();i++)
    {
        while(s[i] == s[0])
        {   
            s.erase(i,i+1);
        }
    }
    cout<<s[0];
    remove_duplicates(s.substr(1));
}

string move_all_x_end(string s)
{
    if(s.length() == 0)
        return "";

    string next = move_all_x_end(s.substr(1));

    if(s[0] == 'x')
        return (next + s[0]);
    else
        return (s[0] + next);
    
}

void subseq(string s, string ans = "")
{
    if(s.length() == 0)
    {
        cout<<ans<<endl;
        return;
    }


    char ch = s[0];
    string ros = s.substr(1);

    subseq(ros,ans);
    subseq(ros,ans + ch);
}

void subseq_ASCII(string s, string ans = "")
{
    if(s.length() == 0)
    {
        cout<<ans<<endl;
        return;
    }


    char ch = s[0];
    int code = ch;
    string ros = s.substr(1);

    subseq(ros,ans);
    subseq(ros,ans + ch);
    subseq(ros,ans + to_string(code));
}

string keypadArr[] = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};

void keypad(string s,string ans = "")
{
    if(s.length() == 0)
    {
        cout<<ans<<endl;
        return;
    }

    char ch = s[0];
    string code = keypadArr[ch - '0'];
    string ros = s.substr(1);

    for(int i=0;i<code.length();i++)
    {
        keypad(ros,ans+code[i]);
    }
}
int main()
{
    string s;

    cin>>s; 

    keypad(s);

    return 0;
}