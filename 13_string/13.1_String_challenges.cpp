#include <bits/stdc++.h>
using namespace std;

string string_toupper(string s)
{  
    string s2;
    char temp;
    int i =0;

    while(s[i] != '\0')
    {
        if(islower(s[i]))
            temp = toupper(s[i]);
        else
            temp = s[i];

        s2 = s2 + temp;
        i++;
    }

    return s2;
    
}

string string_tolower(string s)
{  
    string s2;
    char temp;
    int i =0;

    while(s[i] != '\0')
    {
        if(isupper(s[i]))
            temp = tolower(s[i]);
        else
            temp = s[i];

        s2 = s2 + temp;
        i++;
    }

    return s2;
    
}

string biggest_num_from_string(string s)
{
    string s2 = s;
    sort(s2.begin(),s2.end(),greater<char>());
    return s2;

}

void highest_frequency_char (string s1,int* ans, char* ans_letter)
{
    int freq[26];

    for(int i=0;i<26;i++)
        freq[i] = 0;

    for(int i=0;i<s1.length();i++)
        freq[s1[i]-'a']++;

    int max_freq = freq[0];
    char letter = 'a';

    for(int i=0;i<26;i++)
    {
        if ( freq[i] > max_freq )
        {
            max_freq = freq[i];
            letter = 'a' + i;
        }
    }

    *ans = max_freq;
    *ans_letter = letter;
}

int main()
{
    string s1 ;
    cin >>s1;
    
    int max_freq = 0;
    char letter = 'a';
    highest_frequency_char(s1,&max_freq,&letter);
    cout<<max_freq<<endl<<letter<<endl;
    return 0;
}