#include <bits/stdc++.h>
using namespace std;

bool check_palindrome(char *str)
{
    int len = strlen(str);

    int start =0;
    int end = len-1;

    while(start < len)
    {
        if(str[start] == str[end])
        {
            start ++;
            end--;
        }
        else
        {
            return false;
        }
        
    }
    return true;
}

void largest_word_sentence(char *str)
{
    int i=0;
    int max_len = 0;
    int len = 0;
    int start=0;
    int max_start=0;

    while(1)
    {
        if(str[i] == ' ')
        {   
            if(len > max_len)
            {
                max_len = len;
                max_start = start;
            }
            start = i+1;
            len =0;
        }
        else if(str[i] == '\0')
        {
            if(len > max_len)
            {
                max_len = len;
                max_start = start;
            }
            break;
        }
        else
            len ++;
        i++;

    }
    
    i=max_start;

    while(str[i] != ' ' && str[i] != '\0')
    {
        cout<<str[i];
        i++;
    }   
    cout<<endl;
}
int main()
{
    int n;
    cin>>n;
    cin.ignore();
    char str[n+1];
    cin.getline(str,n);
    cin.ignore();

    largest_word_sentence(str);

    return 0;
}