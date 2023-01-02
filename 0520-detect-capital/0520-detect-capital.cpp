class Solution {
public:
    bool detectCapitalUse(string word) {
        
            if(word.length() == 1){
                return true;
            }
        
            // All capital
            if(word[0] >= 65 && word[0] <= 90 && word[1] >= 65 && word[1] <= 90){
                for(int i=0; i<word.length(); i++){
                    if(word[i] >= 97 && word[i] <= 122){
                        return false;
                    }
                }
            }
        
            //  1st capital and all lowerCase
            else if(word[0] >= 65 && word[0] <= 90 && word[1] >= 97 && word[1] <= 122){
                for(int i=1; i<word.length(); i++){
                    if(word[i] >= 65 && word[i] <= 90){
                        return false;
                    }
                }
            }
            
            //  All LowerCase
            else{
               
                for(int i=0; i<word.length(); i++){
                    if(word[i] >= 65 && word[i] <= 90){
                        return false;
                    }
                }
            }
        return true;
    }
};