class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int totalGas = 0, totalCost = 0;
        int n = gas.size();
        vector<int> diff(n);
        for(int i=0; i<n; i++){
            totalGas += gas[i];
            totalCost += cost[i];
            diff[i] = gas[i] - cost[i];
        }
        
        if(totalGas < totalCost) return -1;
        
// If totalgas is greater than totalcost then definitely there will be a sol
    
        int res = 0;
        int gasleft = 0;

        for(int i=0; i<n; i++){
    // we'll eliminate that start ind if diff is negative
    // If somehow will reach the end of array starting from ith ind then there is a valid sol starting from i
            gasleft += diff[i];
            if(gasleft < 0){
                gasleft = 0;
                res = i+1;
            }
        }
        return res;
    }
};
