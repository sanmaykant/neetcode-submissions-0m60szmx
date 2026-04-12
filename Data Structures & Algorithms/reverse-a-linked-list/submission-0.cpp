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
    ListNode* reverseList(ListNode* head) {
        if (!head)
            return nullptr;

        ListNode* prev = head;
        ListNode* next = head->next;
        while (next) {
            ListNode* fwd = next->next;
            next->next = prev;
            prev = next;
            next = fwd;
        }
        head->next = nullptr;
        return prev;
    }
};
