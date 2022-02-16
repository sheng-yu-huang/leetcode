/**********************************************************************************
*
* Remove Nth Node From End of List
* Source: https://leetcode.com/problems/remove-nth-node-from-end-of-list/
* @author Sam Huang
* @version Dec 12, 2021
*
*
* Given the head of a linked list, remove the nth node from the end of the list and return its head.
*
* Example:
*
* Input: head = [1,2,3,4,5], n = 2
* Output: [1,2,3,5]
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int size = 0;
        int index = 0;
        ListNode* curr = head;
        while(curr){
            size ++;
            curr = curr->next;
        }
        if(size == n)
            return head->next;
        if(n>size)
            return NULL;
        curr = head;
        for(int i=1; i<size-n; i++){
            curr = curr-> next;
        }
        ListNode* tmp = curr->next;
        curr->next = tmp->next;
        
        return head;
    }
};