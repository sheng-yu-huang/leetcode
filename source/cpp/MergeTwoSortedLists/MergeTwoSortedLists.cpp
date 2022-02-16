/**********************************************************************************
*
* Merge Two Sorted Lists
* Source: https://leetcode.com/problems/merge-two-sorted-lists/
* @author Sam Huang
* @version Dec 12, 2021
*
*
* You are given the heads of two sorted linked lists list1 and list2.
* Merge the two lists in a one sorted list. 
* The list should be made by splicing together the nodes of the first two lists.
* Return the head of the merged linked list.
*
* Example:
*
* Input: list1 = [1,2,4], list2 = [1,3,4]
* Output: [1,1,2,3,4,4]
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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode *head=NULL, *curr=NULL;
        int value = 0;
        while(list1 || list2){
            if(list1==NULL){
                value = list2->val;
                list2 = list2->next;
            } else if(list2 == NULL){
                value = list1->val;
                list1 = list1->next;
            } else if (list1->val < list2->val){
                value = list1->val;
                list1 = list1->next;
            } else {
                value = list2->val;
                list2 = list2->next;
            }
            ListNode *tmp = new ListNode(value);
            if(curr == NULL){
                curr = tmp;
                head = curr;
            } else {
                curr->next = tmp;
                curr = curr->next;
            }  
        }
        return head;
    }
};