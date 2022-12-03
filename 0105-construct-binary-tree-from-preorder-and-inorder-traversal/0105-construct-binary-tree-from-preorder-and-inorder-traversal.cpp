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
    int findPosition(vector<int> inOrder, int element, int n){
        for(int i=0; i<n; i++){
            if(inOrder[i] == element){
                return i;
            }
        }
        return -1;
    }
    
    TreeNode* solve(vector<int> &preOrder, vector<int> &inOrder, int &preIndex, int inStart, int inEnd, int n){
        
        //base case
        if(preIndex >= n || inStart > inEnd){
            return NULL;
        }
        
        //  taking element from preorder
        int element  = preOrder[preIndex++];
        
        //  converting it into a node
        TreeNode* root = new TreeNode(element);
        
        //  find element's position in in-order array in inorder to call left and right
        int position = findPosition(inOrder, element, n);
        
        // recursion calls
        root->left = solve(preOrder, inOrder, preIndex, inStart, position-1, n);
        root->right = solve(preOrder, inOrder, preIndex, position+1, inEnd, n);
        
        return root;
        
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        
        int preOrderIndex = 0;
        int n = inorder.size();
        
        TreeNode* ans = solve(preorder, inorder, preOrderIndex, 0, n-1, n);
        
        return ans;
        
    }
};