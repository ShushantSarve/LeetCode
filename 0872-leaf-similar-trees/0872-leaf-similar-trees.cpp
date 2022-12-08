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
    void leafNode(TreeNode* root, vector<int> &v){
    
        // base case
        if(root == NULL){
            return;
        }
        
        //leaf node condition
        if(root->left == NULL && root->right == NULL){
            v.push_back(root->val);
        }
        
        //recursive calls
        leafNode(root->left, v);
        leafNode(root->right, v);
        
    }
    
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        
        vector<int> r1; 
        leafNode(root1, r1);
        
        vector<int> r2; 
        leafNode(root2, r2);
        
        //comparing the leaf nodes from vector
        if(r1 == r2){
            return true;
        }
        return false;
        
    }
};