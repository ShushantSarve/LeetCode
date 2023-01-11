class Solution {
public:
    int dfs(unordered_map<int, vector<int>> &adj, int curr, int parent, vector<bool> &hasApple){
        
        int time = 0;
        
        for(auto &child : adj[curr]){
            
            if(child == parent){
                continue;
            }
            
            int timeFromMyChild = dfs(adj, child, curr, hasApple);
            
            if(timeFromMyChild > 0 || hasApple[child]){
                time += timeFromMyChild + 2;
            }
        }
        
        return time;
    }
    
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        
        unordered_map<int, vector<int>> adj;
        
        for(auto &i : edges){
            int u = i[0];
            int v = i[1];
            
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        return dfs(adj, 0, -1, hasApple);
        
    }
};