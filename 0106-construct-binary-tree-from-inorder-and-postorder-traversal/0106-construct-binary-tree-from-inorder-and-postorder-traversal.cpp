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
    int findPosition(vector<int> inorder, int position, int n){
        for(int i=0; i<n; i++){
            if(inorder[i] == position){
                return i;
            }
        }
        return -1;
    }
    
    TreeNode* solve(vector<int> inorder, vector<int> postorder, int &index, int inStart, int inEnd, int n){
        
        //base case
        if(index < 0 || inStart > inEnd){
            return NULL;
        }
        
        int element = postorder[index--];
        TreeNode* root = new TreeNode(element);
        
        int position = findPosition(inorder, element, n);
        
        root->right = solve(inorder, postorder, index, position+1, inEnd, n);
        root->left = solve(inorder, postorder, index, inStart, position-1, n);
        
        return root;    
    }
    
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        
        int n = inorder.size();
        int index = n-1;
        
        TreeNode* ans = solve(inorder, postorder, index, 0, n-1, n);
        
        return ans;
        
    }
};