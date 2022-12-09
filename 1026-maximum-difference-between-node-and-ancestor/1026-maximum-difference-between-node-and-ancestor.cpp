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
    int ans = INT_MIN;
    
    void getMax(TreeNode* root, int mini, int maxi){
     
        //edge case
        if(!root) return;
        
        //updates minimum while going dowm the tree
        mini = min(mini, root->val);
        //updates maximum while going down the tree
        maxi = max(maxi, root->val);
        
        //stores  the maximum difference between ancestor and child
        ans = max(ans, maxi - mini);
        
        //recursive calls
        getMax(root->left, mini, maxi);
        getMax(root->right, mini, maxi);
        
    }
    int maxAncestorDiff(TreeNode* root) {
        
        if(!root) return 0;
        
        int mini = INT_MAX;
        int maxi = INT_MIN;
        
        getMax(root, mini, maxi);
        
        return ans;
        
    }
};