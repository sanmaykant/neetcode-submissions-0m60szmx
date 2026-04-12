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
  ListNode *mergeKLists(vector<ListNode *> &lists) {
    ListNode *result = nullptr;
    ListNode *current = nullptr;

    while (true) {
      int minIdx = -1;
      for (int i = 0; i < lists.size(); i++) {
        ListNode *node = lists[i];
        if (node && (minIdx == -1 || node->val < lists[minIdx]->val)) {
          minIdx = i;
        }
      }

      if (minIdx < 0)
        break;

      if (result) {
        current->next = lists[minIdx];
        current = current->next;
        lists[minIdx] = lists[minIdx]->next;
      } else {
        result = lists[minIdx];
        current = lists[minIdx];
        lists[minIdx] = lists[minIdx]->next;
      }
    }

    return result;
  }
};