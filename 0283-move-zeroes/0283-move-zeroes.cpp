class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        
        vector<int> ans;
        
        int zeroCnt = 0;
        for(int i=0; i<nums.size(); i++){
            if(nums[i] != 0){
                ans.push_back(nums[i]);
            }
            else{
                zeroCnt++;
            }
        }
        
        for(int i=0; i<zeroCnt; i++){
            ans.push_back(0);
        }
        
        // operation is in-place 
        nums = ans;
    }
};