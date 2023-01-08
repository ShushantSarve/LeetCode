class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        
        // using kadane's algorithm
        
        int maxi = INT_MIN, sum = 0;
        
        for(int i=0; i<nums.size(); i++){
            sum += nums[i];
            maxi = max(maxi, sum);
            
            // if at any point sum becomes negative then no point keeping it because 0 is obviously greater                     than negative, so just make your sum 0.
            if(sum < 0){
                sum = 0;
            }
        }        
        return maxi;
    }
};