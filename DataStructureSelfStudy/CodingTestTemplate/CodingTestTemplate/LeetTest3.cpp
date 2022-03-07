#include <iostream>

using namespace std;
struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2)
    {
        if (list1 == nullptr)//1 is empty
        {
            return list2;
        }
        else if (list2 == nullptr)//2 is empty
        {
            return list1;
        }
       
        if (list1->val <= list2->val)
        {
            list1->next = mergeTwoLists(list1->next,list2);
            return list1;
        }
        else
        {
            list2->next = mergeTwoLists(list1, list2->next);
            return list2;
        }
    }

};


int main()
{
    ListNode* head1 = new ListNode(1, nullptr);
    head1->next = new ListNode(2, nullptr);
    head1->next->next = new ListNode(4, nullptr);
    ListNode* head2 = new ListNode(1, nullptr);
    head2 ->next = new ListNode(3,nullptr);
    head2->next->next = new ListNode(4, nullptr);
    Solution* sol = new Solution;

    ListNode* temp;
    temp = sol->mergeTwoLists(head1,head2);

    while (temp != nullptr)
    {
        cout<<temp->val<<" ";
        temp = temp->next;
    }


}