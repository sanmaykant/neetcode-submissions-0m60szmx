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
  ListNode *mergeTwoLists(ListNode *list1, ListNode *list2) {
    if (!list1)
      return list2;
    if (!list2)
      return list1;

    ListNode *head = nullptr;
    ListNode *current = nullptr;

    bool condition = list1->val < list2->val;
    head = condition ? list1 : list2;
    if (condition)
      list1 = list1->next;
    else
      list2 = list2->next;
    current = head;

    while (list1 || list2) {
      if (!list1) {
        current->next = list2;
        break;
      }
      if (!list2) {
        current->next = list1;
        break;
      }

      bool condition = list1->val < list2->val;
      current->next = condition ? list1 : list2;
      if (condition)
        list1 = list1->next;
      else
        list2 = list2->next;
      current = current->next;
    }

    return head;
  }
};
