class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        
        int a=0, b=0;
        
        for(int i=0; i<nums.size(); i++){
            if(nums[a] != nums[b]){
                a++;
                nums[a] = nums[b];
            }
            b++;
        }
        return a+1;
    }
};