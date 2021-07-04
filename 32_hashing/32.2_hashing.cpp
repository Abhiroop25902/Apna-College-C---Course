#include <iostream>
#include <map>
#include <unordered_map>
using namespace std;

int main()
{
    //name, age pair
    map<string, int> mp;
    mp["abhiroop"] = 18;
    mp["sanjana"] = 21;
    mp["arnab"] = 21;

    cout << mp["abhiroop"] << endl;
    cout << mp.at("abhiroop") << endl;

    mp["abhiroop"] = 19;
    cout << mp["abhiroop"] << endl;

    mp.erase("abhiroop");
}