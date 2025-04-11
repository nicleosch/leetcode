// https://leetcode.com/problems/add-two-numbers/

/*
You are given two non-empty linked lists representing two non-negative integers.
The digits are stored in reverse order, and each of their nodes contains a
single digit. Add the two numbers and return the sum as a linked list.

You may assume the two numbers do not contain any leading zero, except the
number 0 itself.
*/

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  explicit ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
  ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
    if (l1 == nullptr)
      return l2;
    if (l2 == nullptr)
      return l1;

    ListNode *begin = new ListNode();
    ListNode *it = begin;
    int carry = 0;

    while (l1 != nullptr || l2 != nullptr || carry > 0) {
      int sum = 0;
      if (l1 != nullptr) {
        sum += l1->val;
        l1 = l1->next;
      }
      if (l2 != nullptr) {
        sum += l2->val;
        l2 = l2->next;
      }
      sum += carry;

      int val = sum % 10;
      carry = sum / 10;

      it->next = new ListNode(val);
      it = it->next;
    }

    ListNode *result = begin->next;
    delete begin;
    return result;
  }
};