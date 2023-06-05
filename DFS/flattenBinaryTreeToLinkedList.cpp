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

//TURN A BINARY SEARCH TREE INTO A LINKED LIST 

//LeetCode Q: 114. Flatten Binary Tree to Linked List
/*
"Given the root of a binary tree, flatten the tree into a "linked list":

The "linked list" should use the same TreeNode class where the right child pointer points to the next node in the list 
and the left child pointer is always null.
The "linked list" should be in the same order as a pre-order traversal of the binary tree."
*/

class Solution {
public:
    void flatten_dfs( TreeNode* root, TreeNode* prev ){

        if( root == nullptr || prev == nullptr ) return; 
        if( prev->right == root ){
            if( prev->left != nullptr ){
                prev->right = prev->left; 
                TreeNode* temp = prev; 
                while( temp->right != nullptr ) temp = temp->right; 
                temp->right = root; 
                prev->left = nullptr; 
            } 
        }
        else if( prev->right == nullptr && prev->left == root ){
                prev->right = root; 
                prev->left = nullptr; 
        }
        
            flatten_dfs( root->left, root ); 
            flatten_dfs( root->right, root ); 
    
    }

    void flatten(TreeNode* root) {
        TreeNode* newNode = new TreeNode( 0 ); 
        flatten_dfs( root, newNode ); 
        root = newNode->right; 
    }
};
