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
    void inorder(TreeNode* root, vector<int> &inorderv){
        
        if(root == NULL){
            return;
        }    
        
        inorder(root->left, inorderv);
        inorderv.push_back(root->val);
        inorder(root->right, inorderv);
        
    }
    
    TreeNode* inorderToBST(int s, int e, vector<int> &inorderv){
        
        //base case
        if(s>e){
            return NULL;
        }
        
        int mid = (s+e)/2;
        TreeNode* root = new TreeNode(inorderv[mid]);
        root->left = inorderToBST(s, mid-1, inorderv);
        root->right = inorderToBST(mid+1, e, inorderv);
        return root;
    }
    
    TreeNode* balanceBST(TreeNode* root) {
        
        vector<int> inorderv;
        inorder(root, inorderv);
        
        return inorderToBST(0, inorderv.size()-1, inorderv);
        
    }
};