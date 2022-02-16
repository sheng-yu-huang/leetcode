/**********************************************************************************
*
* Binary Tree Inorder Traversal
* Source: https://leetcode.com/problems/binary-tree-inorder-traversal/
* @author Sam Huang
* @version Dec 23, 2021
*
*
* Given the root of a binary tree, return the inorder traversal of its nodes' values.
*
* Example:
*
* Input: root = [1,null,2,3]
* Output: [1,3,2]
*
*
**********************************************************************************/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        if(root == NULL)
            return res;
        recurive(root, res);
        return res;
    }
    
   void recurive(TreeNode* node, vector<int> &res){
        if(node->left != NULL){
            recurive(node->left, res);
        }
        res.push_back(node->val);
        if(node->right != NULL){
            recurive(node->right, res);
        }
    }
};