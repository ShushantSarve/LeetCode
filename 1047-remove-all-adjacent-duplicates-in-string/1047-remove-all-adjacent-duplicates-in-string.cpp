class Solution {
public:
    string removeDuplicates(string s) {
        
        //using string as a stack
        
        string ans = "";
        
        for(auto &c : s){
            if(ans.size() && ans.back() == c){
                ans.pop_back();
            }
            else{
                ans.push_back(c);
            }
        }
        return ans;
    }
};