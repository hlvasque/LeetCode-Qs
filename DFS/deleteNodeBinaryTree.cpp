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

//LeetCode Q: 450. Delete Node in a BST

class Solution {
public:

    void connect_left( TreeNode* root, TreeNode* newLeft ){
        while( root->left != nullptr ){
            root = root->left; 
        }
        root->left = newLeft;  
    }
    
    void delete_dfs( TreeNode*& root, int key ){
       
        if( root == nullptr ) return; //the value is not in the BST
       
        if( root->val == key ){ //we found the key, now we need to delete it
            if( root->right == nullptr && root->left == nullptr ) {
                root = nullptr; 
            }
            else if( root->right != nullptr ){ 

                //we want to replace the deleted node w/ its right child 
                //and set the right child's last left, 
                //equal to the deleted node's first left 
               
                TreeNode* temp1 = root->right->right; 
                TreeNode* temp2 = root->right->left; 
                TreeNode* temp3 = root->left; 
                
                 
                
                root->val = root->right->val; 
                root->right = temp1; 
                root->left = temp2; 
                connect_left( root, temp3 );
               
            } 
            else{
                 //if the deleted node has no right child 
                 //replace it with its left child 
                 TreeNode* temp = root->left->left; 
                 TreeNode* temp2 = root->left->right; 
                 root->val = root->left->val; 
                 root->left = temp; 
                 root->right = temp2; 
            } 
            return; 
        }
        else {
            if( root->val > key ){
                //search on the left
                delete_dfs( root->left, key ); 
            }
            else {
                //search on the right 
                delete_dfs( root->right, key ); 
            }
        }

    }

    TreeNode* deleteNode(TreeNode* root, int key) {
        delete_dfs( root, key ); 
        return root; 
    }
};
