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
        ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
            if (!l2)
                return l1;

            ListNode* output = nullptr;
            ListNode* position = output;

            int i = 0;
            int carry = 0;
            while (l1 || l2) {
                int sum = 0;
                if (l1 && l2)
                    sum = l1->val + l2->val + carry;
                else if (!l2)
                    sum = l1->val + carry;
                else if (!l1)
                    sum = l2->val + carry;

                int unitsPlace = sum % 10;
                carry = sum > 9 ? (sum - unitsPlace) / 10 : 0;

                if (!output) {
                    output = new ListNode(unitsPlace);
                    position = output;
                } else {
                    position->next = new ListNode(unitsPlace);
                    position = position->next;
                }

                l1 = l1 ? l1->next : l1;
                l2 = l2 ? l2->next : l2;
            }

            if (carry)
                position->next = new ListNode(carry);

            return output;
        }
};
