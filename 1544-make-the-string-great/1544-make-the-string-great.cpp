class Solution {
public:
    string makeGood(string s) {
        
        // Brute-Force approach
        
        if(s.length() < 2){
            return s;
        }
        
        int l = 0;
        
        //until we don't have new changes(no change in length of string)
        while(l != s.length()){
            l = s.length();
            for (int i = 0; i + 1 < s.size(); ++i){
                if(abs(s[i] - s[i + 1]) == 32){
                    s.erase(i, 2);
                }
            }
        }
        return s;        
    }
};