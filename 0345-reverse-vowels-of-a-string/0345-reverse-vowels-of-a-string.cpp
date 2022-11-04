class Solution {
public:
    string reverseVowels(string s) {
        
        unordered_set<char> st = {'a','A', 'e', 'E', 'i', 'I', 'o', 'O', 'u', 'U'};
        int i = 0;
        int j = s.length()-1;
        
        while(i < j){
            
            //search if lef side vowel is present or not
            while(!st.count(s[i]) && i<j){
                i++;
            }
            //search if right side vowel is present or not
            while(!st.count(s[j]) && i<j){
                j--;
            }
            //both are present, swap them
            swap(s[i], s[j]);
            
            //update both pointers
            i++;
            j--;
            
        }
        return s;
        
    }
};