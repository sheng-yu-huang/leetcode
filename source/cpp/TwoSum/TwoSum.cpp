/**********************************************************************************
*
* Two Sum
* Source: https://leetcode.com/problems/two-sum/
* @author Sam Huang
* @version Sep 15, 2021
*
*
* Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.
* You may assume that each input would have exactly one solution, and you may not use the same element twice.
* You can return the answer in any order.
*
* Example:
*
* Input: nums = [2,7,11,15], target = 9
* Output: [0,1]
* Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].
*
*
**********************************************************************************/


class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans;
        int need_num;
        unordered_map<int, int> nums_map;
        for(int i=0; i<nums.size(); i++){
            need_num = target -nums[i];
            if(nums_map.find(need_num) != nums_map.end()){
                ans.push_back(nums_map[need_num]);
                ans.push_back(i);
                return ans;
            } else {
                nums_map[nums[i]] = i;
            }
        }
        return ans;
    }
};