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

//LeetCode Q: 98. Validate Binary Search Tree

/*
"Given the root of a binary tree, determine if it is a valid binary search tree (BST).

A valid BST is defined as follows:

The left 
subtree
 of a node contains only nodes with keys less than the node's key.
The right subtree of a node contains only nodes with keys greater than the node's key.
Both the left and right subtrees must also be binary search trees."
*/

class Solution {
public:
    bool validate_dfs( TreeNode* root, long lastLeft, long lastRight ){
        if( root == nullptr ) return true; 
        else if( root->val <= lastLeft || root->val >= lastRight ){
            return false; 
        } 
        else{
         return true && validate_dfs( root->left, lastLeft, root->val ) && validate_dfs( root->right, root->val, lastRight ); 
        }

    }
    bool isValidBST(TreeNode* root) {
        return validate_dfs( root, -10000000000000, +1000000000000 ); 
    }
};
