class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        
        //  the whole concept is to use slope --> if slope of two pairs are same then they are collinear
        //  then return the max continous count
        
        int n = points.size(), ans = 0;
        
        //  two points form the line
        if(n <= 2){    
            return n;
        }
        
        for(int i=0; i<n; i++){
            
            //  map to store the frequency of the slope
            unordered_map<double, int> mp;
            
            int temp_max = 0;
            
            // taking coordinates
            int x1 = points[i][0];
            int y1 = points[i][1];
            
            for(int j=0; j<n; j++){
                
                if(i == j){
                    continue;
                }
                
                // taking coordinates
                int x2 = points[j][0];
                int y2 = points[j][1];
                
                double dx = y2 - y1;
                double dy = x2 - x1;
                
                // if denominator is 0 --> the slope is infinity
                if(dy == 0){
                    mp[INT_MAX]++;
                    
                    // update the temp max
                    temp_max = max(temp_max, mp[INT_MAX]);
                    continue;
                }
                
                // slope exists --> find the slope
                double slope = dx/dy;
                
                mp[slope]++;
                
                temp_max = max(temp_max, mp[slope]);                
            }
            // update the max slope
            ans = max(ans, temp_max);
        }
        
        //  (ans + 1) is because the first point of line was not counted before
        return ans+1;
    }
};