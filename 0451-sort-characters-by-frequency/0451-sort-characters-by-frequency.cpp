class Solution {
public:
    string frequencySort(string s) {

        unordered_map<char, int> mp;

        //mapping characters with their frequency
        for(int i=0; i<s.length(); i++){
            mp[s[i]]++;
        }
        
        // put it in vector to
        vector<pair<int, char>> v;
        for(auto i : mp){
            v.push_back({i.second, i.first});
        }

        sort(v.begin(), v.end(), greater<>());

        string ans = "";
        for(auto i : v){
            int count = i.first;
            while(count--){
                ans += i.second;
            }
        }
        return ans;
    }
};