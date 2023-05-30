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

//FIND THE MAX DEPTH/HEIGHT OF A BINARY TREE 
class Solution {
public:

    int findMax( TreeNode* root, int num ){
        if( root == nullptr ) return num; 
        int left = findMax( root->left, num + 1 ); 
        int right = findMax( root->right, num + 1 );
        return max( left, right );  
    }

    int maxDepth(TreeNode* root) {
        //find the maximum depth of the tree
        if( root == nullptr ) return 0; 
        return findMax( root, 0 ); 
    }
};
