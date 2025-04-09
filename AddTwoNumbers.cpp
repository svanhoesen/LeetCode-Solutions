/*
* Author: Steffan Van Hoesen
* Date: April 8th, 2025
* Name: addTwoNumbers
* Purpose: Solve the addTwoNumbers problem with optimal time and space complexity.
* Description: You are given two non-empty linked lists representing two non-negative integers. 
*              The digits are stored in reverse order, and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.
* Given Assumptions: 1) You may assume the two numbers do not contain any leading zero, except the number 0 itself.
* Constraints: 1) The number of nodes in each linked list is in the range [1, 100].
*              2) 0 <= Node.val <= 9
*              3) It is guaranteed that the list represents a number that does not have leading zeros.
* Parameters: ListNode* l1, ListNode* l2
* Return: Return a linked list that contains the sum of l1 and l2.
*/

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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
    {
        ListNode* temp = new ListNode(0);
        ListNode* current = temp;
        ListNode* list_ptr1 = l1;
        ListNode* list_ptr2 = l2;
        int carry = 0;

        while (list_ptr1 != nullptr || list_ptr2 != nullptr)
        {
            int x = (list_ptr1 != nullptr) ? list_ptr1->val : 0;
            int y = (list_ptr2 != nullptr) ? list_ptr2->val : 0;
            int sum = carry + x + y;
            carry = sum / 10;

            current->next = (list_ptr1 != nullptr) ? list_ptr1 : list_ptr2;
            current->next->val = sum % 10;

            current = current->next;
            if (list_ptr1 != nullptr) list_ptr1 = list_ptr1->next;
            if (list_ptr2 != nullptr) list_ptr2 = list_ptr2->next;
        }

        if (carry > 0)
        {
            current->next = new ListNode(carry);
        }

        return temp->next;
    }
};
