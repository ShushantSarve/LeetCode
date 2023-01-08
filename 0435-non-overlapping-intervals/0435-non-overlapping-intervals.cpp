bool comp(vector<int> &a, vector<int> &b){
    return a[1] < b[1];
}

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        
        sort(intervals.begin(), intervals.end(), comp);
        int ans = 0;
        int p = intervals[0][1];
        
        for(int i=1; i<intervals.size(); i++){
            if(p > intervals[i][0]){
                ans++;
            }
            else{
                p = intervals[i][1];
            }
        }
        return ans;        
    }
};