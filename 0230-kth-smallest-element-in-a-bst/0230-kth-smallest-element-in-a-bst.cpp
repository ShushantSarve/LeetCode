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
    int kthSmallest(TreeNode* root, int k) {
        
        //Morris traversal
        TreeNode *curr , *prev;
        int i = 0, ans = 0;
        
        while(curr){
                
            if(curr->left){
                
                prev = curr->left;
                while(prev->right != NULL && prev->right != curr){
                    prev = prev->right;
                }
                
                if(prev->right){
                    prev->right = NULL;
                    i++;
                    if(i == k){
                        ans = curr->val;
                    }
                    curr = curr->right;
                }
                else{
                    prev->right = curr;
                    curr = curr->left;
                }
                
            }
            else{
                i++;
                if(i == k){
                    ans = curr->val;
                }
                curr = curr->right;
            }
            
        }
        return ans;
    }
};