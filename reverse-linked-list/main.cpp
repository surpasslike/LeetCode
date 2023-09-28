#include <iostream>
using namespace std;
// 反转链表
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
    ListNode *reverseList(ListNode *head)
    {
        ListNode *prev = nullptr; // 指向前一个节点的指针
        ListNode *curr = head;    // 指向当前节点的指针

        while (curr != nullptr)
        {                                    // 当当前节点不为空时，继续遍历
            ListNode *nextTemp = curr->next; // 暂存下一个节点
            curr->next = prev;               // 将当前节点的 next 指针指向前一个节点，实现反转
            prev = curr;                     // 将前一个节点指针向后移动
            curr = nextTemp;                 // 将当前节点指针向后移动
        }
        return prev; // 当前节点指针到达链表末尾，返回前一个节点指针，即反转后的头节点
    }

    /*
    解析：初始链表为1->2->3->4->5->null
    此时prev为null，curr为1->2->3->4->5->null

    第一轮：
    nextTemp变成2->3->4->5->null
    curr->next变成prev也就是null，那么curr就变成了1->null（因为curr是指向1的）
    prev变成了curr，也就是prev变成了1->null
    curr变成了nextTemp，也就是curr变成了2->3->4->5->null
    综上所述：第一轮的结果是prev变成了1->null，curr变成了2->3->4->5->null

    第二轮：
    nextTemp变成3->4->5->null
    curr->next变成prev也就是1->null，那么curr就变成了2->1->null（因为curr是指向2的）
    prev变成了curr，也就是2->1->null
    curr变成了nextTemp，也就是3->4->5->null
    综上所述：第一轮的结果是prev变成了2->1->null，curr变成了3->4->5->null

    以此类推...
    返回prev即为答案
    */
};

int main()
{
    // 创建链表：1 -> 2 -> 3 -> 4 -> 5 -> nullptr
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    // 打印初始链表
    cout << "Initial List: ";
    ListNode *current = head;
    while (current != nullptr)
    {
        cout << current->val << "->";
        current = current->next;
    }
    cout << "nullptr" << endl;

    // 创建Solution对象
    Solution sol;

    // 调用reverseList方法反转链表
    ListNode *newHead = sol.reverseList(head);

    // 打印反转后的链表
    cout << "Reversed List: ";
    while (newHead != nullptr)
    {
        cout << newHead->val << "->";
        newHead = newHead->next;
    }
    cout << "nullptr" << endl;

    // 释放链表节点内存
    while (head != nullptr)
    {
        ListNode *temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}

/*
给你单链表的头节点 head ，请你反转链表，并返回反转后的链表。


示例 1：


输入：head = [1,2,3,4,5]
输出：[5,4,3,2,1]
示例 2：


输入：head = [1,2]
输出：[2,1]
示例 3：

输入：head = []
输出：[]
*/