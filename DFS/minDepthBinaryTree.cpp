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

//FIND THE MIN DEPTH IN A BINARY TREE 

//LeetCode Q: 111. Minimum Depth of Binary Tree

class Solution {
public:
    int min_depth_dfs( TreeNode* root ){
        if( root == nullptr ) return 0;
        int left = 1 + min_depth_dfs( root->left ); 
        int right = 1 + min_depth_dfs( root->right ); 
        if( left == 1 && right ==  1 ) return 1; 
        else if( left == 1 && right != 1 ) return right; 
        else if( left != 1 && right == 1 ) return left; 
        else return min( left, right ); 
    }
    int minDepth(TreeNode* root) {
        return min_depth_dfs( root ); 
    }
};
