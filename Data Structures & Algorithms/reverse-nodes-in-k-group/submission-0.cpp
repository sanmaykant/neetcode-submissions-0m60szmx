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
  std::vector<ListNode *> reverseN(ListNode *head, int n) {
    if (!head || !(head->next) || n <= 1)
      return {head, nullptr, nullptr};

    ListNode *current = head;
    ListNode *next = current->next;
    int swaps = 1;

    while (swaps < n) {
      if (!next)
        return reverseN(current, swaps);

      ListNode *afterNext = next->next;
      next->next = current;
      current = next;
      next = afterNext;
      swaps++;
    }

    head->next = nullptr;

    ListNode *&start = current;
    ListNode *&end = head;
    ListNode *&nextGroup = next;
    return {start, end, nextGroup};
  }

  ListNode *reverseGroups(ListNode *head, int k) {
    std::vector<ListNode *> r = reverseN(head, k);
    ListNode *&start = r[0];
    ListNode *&end = r[1];
    ListNode *&nextGroup = r[2];

    if (!nextGroup || (start == head))
      return start;

    end->next = reverseGroups(nextGroup, k);
    return start;
  }

  ListNode *reverseKGroup(ListNode *head, int k) {
    return reverseGroups(head, k);
  }
};
