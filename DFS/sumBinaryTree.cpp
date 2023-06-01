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
    //LeetCode Q: 938. Range Sum of BST

    //'Given the root node of a binary search tree and two integers low and high, 
    //return the sum of values of all nodes with a value in the inclusive range [low, high].'

    int sum_dfs( TreeNode* root, int low, int high ){
        if( root == nullptr ) return 0; 
        int sum = 0; 
        if( root->val >= low && root->val <= high ) sum += root->val; 
        sum += sum_dfs( root->left, low, high ); 
        sum += sum_dfs( root->right, low, high ); 
        return sum;  

    }

    int rangeSumBST(TreeNode* root, int low, int high) {
        return sum_dfs( root, low, high ); 
    }
};
