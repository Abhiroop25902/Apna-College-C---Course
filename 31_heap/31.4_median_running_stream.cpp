#include <iostream>
#include <queue>
using namespace std;

//https://leetcode.com/problems/find-median-from-data-stream/

class MedianFinder
{
    priority_queue<int, vector<int>> left_side;
    priority_queue<int, vector<int>, greater<int>> right_side;

public:
    /** initialize your data structure here. */
    MedianFinder() {}

    void addNum(int num)
    {
        if (left_side.size() == right_side.size())
        {
            if (left_side.size() == 0)
                left_side.push(num);
            else
            {
                if (num > left_side.top())
                    right_side.push(num);
                else
                    left_side.push(num);
            }
        }
        else if (left_side.size() > right_side.size())
        {
            if (num < left_side.top())
            {
                //here the element is to be inserted on left, but left is already bigger than right,
                //so we take an element from left and push it in right, and then we insert num in left
                int temp = left_side.top();
                left_side.pop();
                right_side.push(temp);

                left_side.push(num);
            }
            else
            {
                //element will go to right side
                right_side.push(num);
            }
        }
        else //left_side.size() < right_side.size()
        {
            if (num >= right_side.top())
            {
                //here the element is to be inserted on right, but right is already bigger than left,
                //so we take an element from right and push it in left, and then we insert num in right
                int temp = right_side.top();
                right_side.pop();
                left_side.push(temp);

                right_side.push(num);
            }
            else
            {
                //element will go to left side
                left_side.push(num);
            }
        }
    }

    double findMedian()
    {
        //if left_size and right_side have equal size, we have even number of inputs, so we ahve to take average
        //of the middle two, which are top of the two heaps
        if (left_side.size() == right_side.size())
            return (((double)left_side.top()) + ((double)right_side.top())) / 2;
        else
        {
            //else return top of maximum sized heap
            if (left_side.size() > right_side.size())
                return left_side.top();
            else
                return right_side.top();
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */

int main()
{
    int n;
    cin >> n;

    MedianFinder *obj = new MedianFinder();
    int num;

    for (int i = 0; i < n; i++)
    {
        cin >> num;
        obj->addNum(num);
        double param_2 = obj->findMedian();
        cout << param_2 << " ";
    }
}