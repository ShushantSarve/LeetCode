class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        
        int n = gas.size();
        int index = 0;
        int balance = 0;
        int deficit = 0;
        
        for(int i=0; i<n; i++){
            balance += gas[i] - cost[i];
            if(balance < 0){
                index = i+1;
                deficit += balance;
                balance = 0;
            }
        }
        
        if(balance + deficit >= 0){
            return index;
        }
        else{
            return -1;
        }
        
    }
};