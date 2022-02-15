/**********************************************************************************
*
* Add Two Numbers
* Source: https://leetcode.com/problems/add-two-numbers/
* @author Sam Huang
* @version Dec 12, 2021
*
*
* You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order, 
* and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.
* You may assume the two numbers do not contain any leading zero, except the number 0 itself.
*
* Example:
*
* Input: prices = [7,1,5,3,6,4]
* Output: 5
* Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit = 6-1 = 5.
* Note that buying on day 2 and selling on day 1 is not allowed because you must buy before you sell.
*
*
**********************************************************************************/

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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int sum = 0;
        int carry = 0;
        ListNode *head = NULL;
        ListNode *cur = NULL;
        while ( l1 || l2 ){
            if(l1 == NULL) {
                sum = l2->val + carry;
            } else if (l2 == NULL){
                sum = l1->val + carry;
            } else {
                sum = l1->val + l2->val + carry;
            }
            if(sum>9)
                carry = 1;
            else 
                carry = 0;
            
            ListNode *tmp = new ListNode(sum%10);
            if(cur==NULL){
                cur = tmp;
                head = cur;
            } else{
                cur->next = tmp;
                cur = cur->next;
            }
            
            l1 = (l1 != NULL)?l1->next:NULL;
            l2 = (l2 != NULL)?l2->next:NULL;
        }
        if(carry==1){
            ListNode *carry_1 = new ListNode(1);
            cur->next = carry_1;
        }

        return head;    
    }
};