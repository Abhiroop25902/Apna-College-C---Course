#include <iostream>
#include <vector>
using namespace std;

int minimumJumpsToReachEnd_Recursive(vector<int> path, int currIndex = 0, int currSteps = 0){
    if(currIndex >= path.size())
        return INT32_MAX;

    if(currIndex == path.size() - 1)
        return currSteps;

    int minStep = INT32_MAX;

    for(int i=1; i<=path[currIndex]; i++){
        minStep = min(minStep, minimumJumpsToReachEnd_Recursive(path, currIndex + i, currSteps + 1));
    }

    return minStep;
}


int main(){
    int n;
    cin>> n;

    vector<int> path(n);
    for(int i=0;i<n;i++)
        cin>> path[i];

    cout<<minimumJumpsToReachEnd_Recursive(path);
}