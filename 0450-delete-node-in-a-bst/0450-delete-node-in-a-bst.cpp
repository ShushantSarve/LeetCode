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
    TreeNode* solve(TreeNode* root, int key){
        
        //base case
        if(root == NULL) return root;
        
        if(root->val == key){
            
            // 0 child
            if(root->left == NULL && root->right == NULL){
                delete root;
                return NULL;
            }
            
            // 1 child
                //left child
            if(root->left != NULL && root->right == NULL){
                TreeNode* temp = root->left;
                delete root;
                return temp;
            }            
                //right child
            if(root->left == NULL && root->right != NULL){
                TreeNode* temp = root->right;
                delete root;
                return temp;
            }
            
            // 2 child
            if(root->left != NULL && root->right != NULL){
                TreeNode* tempp = root->right;
                while(tempp->left != NULL){
                    tempp = tempp->left;
                }
                int mini = tempp->val;
                root->val = mini;
                root->right = solve(root->right, mini);
                return root;
            }
    
        }
        else if(root->val > key){
            //move to left
            root->left = solve(root->left, key);
            return root;
        }
        else{
            //move to right
            root->right = solve(root->right, key);
            return root;
        }
        return root;
    }
    
    TreeNode* deleteNode(TreeNode* root, int key) {
        
        // we encounter 3 possible conditions over here
        // 1. deleting the leaf node.
        // 2. deleting node with one child.
        // 3. deleting node with both the childs or a proper subtree.
        
        return solve(root, key);
        
    }
};