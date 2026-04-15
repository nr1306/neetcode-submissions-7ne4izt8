class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        
        int n = gas.size();

        for(int ind = 0; ind < n; ind++){
            int gasleft = gas[ind];
            int j=0;
            for(int i=ind; j<n; j++){
                if(cost[i] > gasleft) break;

                gasleft += gas[(i+1)%n] - cost[i];

                i = (i+1)%n;
            }
            if(j == n)
                return ind;
        }
        return -1;
    }
};
