class Solution {
public:
    int maximum69Number (int num) {
        
        vector<int> v;
        int temp = num;
        
        //breaking the number
        while(temp){
            int a = temp%10;
            temp /= 10;
            v.push_back(a);
        }
        
        //reordering the number in vector
        int i=0, j=v.size()-1;
        while(i<j){
            swap(v[i], v[j]);
            i++;
            j--;
        }
        
        //checking for least significant '6'
        for(int i=0; i<v.size(); i++){
            if(v[i] == 6){
                v[i] = 9;
                break;
            }
        }
        
        //constructing the new number
        int ans = 0;
        for(int i=0; i<v.size(); i++){
            ans = (ans*10) + v[i];
        }
        
        return ans;
    }
};