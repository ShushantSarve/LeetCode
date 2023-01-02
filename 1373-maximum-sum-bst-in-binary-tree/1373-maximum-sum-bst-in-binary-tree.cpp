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
    class info{
        public:
            int maxi;
            int mini;
            int sum;
            bool isBST;
    };
    
    info solve(TreeNode* root, int &ans){
        
        if(root == NULL){
            return {INT_MIN, INT_MAX, 0, 1};
        }
        
        info currNode;
        info left = solve(root->left, ans);
        info right = solve(root->right, ans);
        
        if(left.isBST && right.isBST && root->val > left.maxi && root->val < right.mini){
            currNode.isBST = true;
            currNode.sum = left.sum + right.sum + root->val;
            currNode.maxi = max(root->val, right.maxi);
            currNode.mini = min(root->val, left.mini);
        }
        else{
            currNode.isBST = false;
            currNode.sum = max(left.sum, right.sum);
        }
        
        ans = max(ans, currNode.sum);
        return currNode;
    }
    
    int maxSumBST(TreeNode* root) {
        
        int maxSum = 0;
        solve(root, maxSum);
        return maxSum;
        
    }
};