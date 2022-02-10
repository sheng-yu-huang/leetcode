/**********************************************************************************
*
* Search Insert Position
* Source: https://leetcode.com/problems/search-insert-position/
* @author Sam Huang
* @version Nov 1, 2021
*
*
* Given a sorted array of distinct integers and a target value, return the index if the target is found. If not, 
* return the index where it would be if it were inserted in order.
* You must write an algorithm with O(log n) runtime complexity.
*
* Example:
*
* Input: nums = [1,3,5,6], target = 5
* Output: 2
*
*
**********************************************************************************/

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int size = nums.size();
        int mid = 0;
        int start = 0;
        int end = size -1;
        if(target<nums[start])
            return 0;
        if(target>nums[end])
            return size;
        
        while(1){
            mid = (end-start)/2 + start;
            if(target == nums[mid])
                return mid;
            if(target>nums[mid] && target<nums[mid+1] )
                return mid+1;
            if(target<nums[mid]){
                end = mid;
            } else {
                start = mid+1;
            }
            if(start == end){
                return start;
            }
        }
    }

};