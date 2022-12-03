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
    void createMap(vector<int> inorder, int n, map<int, int> &NodeToIndex){
        for(int i=0; i<n; i++){
            NodeToIndex[inorder[i]] = i;
        }
    }
    TreeNode* solve(vector<int> &inorder, vector<int> &postorder, int &index, int inStart, int inEnd, int n, map<int, int> &NodeToIndex){
        
        //  Base case
        if(index < 0 || inStart > inEnd){
            return NULL;
        }
        
        int element = postorder[index--];
        
        TreeNode* root = new TreeNode(element);
        
        int position = NodeToIndex[element];
        
        // IMP --> calling the right side of tree first as we are traversing back int the array
        
        root->right = solve(inorder, postorder, index, position+1, inEnd, n, NodeToIndex);
        root->left = solve(inorder, postorder, index, inStart, position-1, n, NodeToIndex);
        
        return root;
        
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        
        int index = postorder.size()-1;
        int n = inorder.size();
        
        //  mapping the elements
        map<int, int> NodeToIndex;
        createMap(inorder, n, NodeToIndex);
        
        TreeNode* ans = solve(inorder, postorder, index, 0, n-1, n, NodeToIndex);
        
        return ans;
        
    }
};