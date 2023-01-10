#include<bits/stdc++.h>

class node{
    public:
        int data;
        int row;
        int col;
    
    node(int d, int r, int c){
        data = d;
        row = r;
        col = c;
    }
};

class compare{
    public:
        bool operator()(node* a, node* b){
            return a->data > b->data;
        }
};

class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        
        int mini = INT_MAX, maxi = INT_MIN;
        
        priority_queue<node* , vector<node*>, compare> minHeap;
        
        for(int i=0; i<nums.size(); i++){
            int element = nums[i][0];
            maxi = max(maxi, element);
            mini = min(mini, element);
            minHeap.push(new node(element, i, 0));
        }
        
        int start = mini, end = maxi;
        
        
        while(!minHeap.empty()){
            
            // fetching the mininum element from minHeap
            node* temp = minHeap.top();
            minHeap.pop();
            
            // updating the mini to new mini (minHeap top)
            mini = temp->data;
            
            // checking for minimum range and updating the answer
            if(maxi - mini < end - start){
                start = mini;
                end = maxi;
            }
            
            // push to minHeap if next element exists in the input
            int n = nums[0].size();
            if(temp->col + 1 < nums[temp->row].size()){
                maxi = max(maxi, nums[temp->row][temp->col + 1]);
                minHeap.push(new node(nums[temp->row][temp->col + 1], temp->row, temp->col + 1));
            }
            else{
                break;
            }
        }
        
        vector<int> ans = {start, end};
        return ans;
    }
};