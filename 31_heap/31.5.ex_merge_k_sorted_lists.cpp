//https://leetcode.com/problems/merge-k-sorted-lists/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

//  * Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    struct comparator
    {
        bool operator()(pair<ListNode *, int> a, pair<ListNode *, int> b)
        {
            return a.first->val > b.first->val;
        }
    };

    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        priority_queue<pair<ListNode *, int>, vector<pair<ListNode *, int>>, comparator> min_heap;

        ListNode *answer = nullptr;
        ListNode *ans_iter = nullptr;

        for (int i = 0; i < lists.size(); i++)
            if (lists[i] != nullptr)
                min_heap.push(make_pair(lists[i], i));

        while (!min_heap.empty())
        {
            if (answer == nullptr)
            {
                answer = min_heap.top().first;
                ans_iter = answer;
            }
            else
            {
                ans_iter->next = min_heap.top().first;
                ans_iter = ans_iter->next;
            }

            lists[min_heap.top().second] = lists[min_heap.top().second]->next;

            if (lists[min_heap.top().second] != nullptr)
                min_heap.push(make_pair(lists[min_heap.top().second], min_heap.top().second));

            min_heap.pop();
        }

        return answer;
    }
};

void iter(ListNode *ans)
{
    while (ans != nullptr)
    {
        cout << ans->val;
        ans = ans->next;
    }
    cout << "\n";
}

int main()
{
    vector<ListNode *> list;

    ListNode *l1 = new ListNode(1, new ListNode(4, new ListNode(5)));
    list.push_back(l1);
    iter(l1);

    ListNode *l2 = new ListNode(1, new ListNode(3, new ListNode(4)));
    list.push_back(l2);
    iter(l2);

    ListNode *l3 = new ListNode(2, new ListNode(6, new ListNode(7)));
    list.push_back(l3);
    iter(l3);

    ListNode *l4 = nullptr;
    list.push_back(l4);

    Solution s;
    ListNode *ans = s.mergeKLists(list);
    iter(ans);
}
