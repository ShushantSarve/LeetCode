class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        
        //  store and return the ans
        vector<vector<int>> ans;
        
        // sort the input with it's last element
        sort(intervals.begin(), intervals.end());
        
        // push 1st element for speculation
        ans.push_back(intervals[0]);
        
        // j pointer for tracking the current position of ans
        int j = 0;
        
        for(int i=1; i<intervals.size(); i++){
            // check if the 2nd element is in the range of 1st element 
            if(ans[j][1] >= intervals[i][0]){
                // if yes, increase the range of 1st element (basically, merging two range to one)
                ans[j][1] = max(ans[j][1], intervals[i][1]);
            }
            else{
                // if not, then increase the tracking pointer and push the element
                j++;
                ans.push_back(intervals[i]);
            }
            
        }
        return ans;
    }
};