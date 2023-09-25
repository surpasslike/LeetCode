#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        if (headA == nullptr || headB == nullptr)
        {
            return nullptr;
        }
        ListNode *pA = headA, *pB = headB;
        while (pA != pB)
        {
            pA = pA == nullptr ? headB : pA->next;
            pB = pB == nullptr ? headA : pB->next;
        }
        return pA;
    }
};

int main()
{
    int intersectVal, m, n, skipA, skipB;
    cout << "Enter intersectVal, m (nodes in listA), n (nodes in listB), skipA, skipB: ";
    cin >> intersectVal >> m >> n >> skipA >> skipB;

    vector<int> valuesA(m), valuesB(n);
    cout << "Enter " << m << " values for List A: ";
    for (int &val : valuesA)
        cin >> val;
    cout << "Enter " << n << " values for List B: ";
    for (int &val : valuesB)
        cin >> val;

    ListNode *common = nullptr;
    ListNode *prev = nullptr;
    for (int i = skipA; i < m; ++i)
    {
        ListNode *node = new ListNode(valuesA[i]);
        if (prev)
            prev->next = node;
        if (!common)
            common = node;
        prev = node;
    }

    ListNode *listA = nullptr;
    prev = nullptr;
    for (int i = 0; i < skipA; ++i)
    {
        ListNode *node = new ListNode(valuesA[i]);
        if (prev)
            prev->next = node;
        if (!listA)
            listA = node;
        prev = node;
    }
    if (prev)
        prev->next = common;

    ListNode *listB = nullptr;
    prev = nullptr;
    for (int i = 0; i < skipB; ++i)
    {
        ListNode *node = new ListNode(valuesB[i]);
        if (prev)
            prev->next = node;
        if (!listB)
            listB = node;
        prev = node;
    }
    if (prev)
        prev->next = common;

    Solution sol;
    ListNode *intersection = sol.getIntersectionNode(listA, listB);

    if (intersection)
        cout << "Intersected at '" << intersection->val << "'\n";
    else
        cout << "The lists do not intersect.\n";
}
