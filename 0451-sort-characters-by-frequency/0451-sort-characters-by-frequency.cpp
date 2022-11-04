class Solution {
public:
    string frequencySort(string s) {

        unordered_map<char, int> mp;

        //mapping characters with their frequency
        for(int i=0; i<s.length(); i++){
            mp[s[i]]++;
        }
        
        // put it in vector to sort the map
        vector<pair<int, char>> v;
        for(auto i : mp){
            v.push_back({i.second, i.first});
        }

        //sorting
        sort(v.begin(), v.end(), greater<>());

        //pushing sorted characters to empty ans string
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