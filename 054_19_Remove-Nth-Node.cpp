// https://leetcode.com/problems/remove-nth-node-from-end-of-list/description/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* fast = head;
        ListNode* slow = head;
        int i;
        for(i = 0; i < n; ++i){
            fast = fast->next;
        }
        if(fast == NULL){
            return head->next;
        }
        while(fast->next != NULL){
            fast = fast->next;
            slow = slow->next;
        }
        ListNode* delNode = slow->next;
        slow->next = slow->next->next;
        delete(delNode);
        return head;

    }
};