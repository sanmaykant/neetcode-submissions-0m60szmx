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
  void reorderList(ListNode *head) {
    if (!head || !head->next || !head->next->next)
      return;

    int size = 0;
    ListNode *current = head;
    while (current) {
      size++;
      current = current->next;
    }

    int nextHalfBeginIdx = size / 2;
    ListNode *prevPtr = nullptr;
    ListNode *nextHalfBeginPtr = head;
    int i = 0;
    while (i <= nextHalfBeginIdx) {
      i++;
      prevPtr = nextHalfBeginPtr;
      nextHalfBeginPtr = nextHalfBeginPtr->next;
    }

    ListNode *reversedHalf = reverseList(nextHalfBeginPtr);
    prevPtr->next = nullptr;

    ListNode *a = head;
    ListNode *b = head->next;
    current = reversedHalf;
    while (current) {
      ListNode *nextA = b;
      ListNode *nextB = b->next;
      ListNode *nextCurrent = current->next;

      a->next = current;
      current->next = b;

      a = nextA;
      b = nextB;
      current = nextCurrent;
    }
  }

private:
  ListNode *reverseList(ListNode *head) {
    if (!head || !head->next)
      return head;

    ListNode *prev = nullptr;
    ListNode *current = head;
    while (current->next) {
      ListNode *next = current->next;
      current->next = prev;
      prev = current;
      current = next;
    }

    current->next = prev;
    return current;
  }
};
