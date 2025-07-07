// https://leetcode.com/problems/palindrome-linked-list/

#include <bits/stdc++.h>
using namespace std;

//   Definition for singly-linked list.
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
        ListNode *curr = head;
        ListNode *after = head;
        ListNode *before = NULL;
        while (curr != NULL)
        {
            after = after->next;
            curr->next = before;
            before = curr;
            curr = after;
        }

        head = before;
        return head;
    }
    bool isPalindrome(ListNode *head)
    {
        ListNode *slow = head;
        ListNode *fast = head;
        while (fast != nullptr && fast->next != nullptr)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode *rev = reverseList(slow);
        while (rev != nullptr)
        {
            if (head->val != rev->val)
            {
                return false;
            }
            head = head->next;
            rev = rev->next;
        }
        return true;
    }
};