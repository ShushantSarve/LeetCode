class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        
        // used min heap priority queue 
        priority_queue<int, vector<int>, greater<int>> pq;
        
        // insert k elements in pq
        for(int i=0; i<k; i++){
            pq.push(nums[i]);
        }
        
        // insert remaining (n-k) elements in pq
        for(int i=k; i<nums.size(); i++){
            if(nums[i] > pq.top()){
                pq.pop();
                pq.push(nums[i]);
            }
        }
        
        // pq top is the kth largest element
        int ans = pq.top();
        return ans;
        
    }
};