class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int maxi = INT_MIN;
        int ind = -1;
        int n = gas.size();
        cout << ind;

        if(n == 1 && gas[0] - cost[0] >= 0) return 0;

        int count = 0;
        for(int ind=0; ind<n; ind++){
            if(gas[ind]-cost[ind] > 0){
                int gasleft = 0;
                int j=0;
                for(int i=ind; j<n; j++){
                    gasleft += gas[i] - cost[i];
                    
                    if(gasleft < 0) break;
                    i = (i+1)%n;
                }   
                if(j == n) return ind; 
            }
        }
        return -1;
    }
};
