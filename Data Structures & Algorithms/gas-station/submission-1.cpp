class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        if(n == 1){
            if(gas[0] >= cost[0]) return 0;
            return -1;
        }
        
        int g = gas[0];
        int c = cost[0];
        for(int i=1; i<n; i++){
            g += gas[i];
            c += cost[i];
        }

        // Determining if trip is even possible or not by comparing total gas and total cost
        if(g < c) return -1;
        g = 0;
        int startIndex = 0;
        for(int start = 0; start < n; start++){
            // We'll consider every index as starting index and will move until we can
            // If we stop in between then we'll discard gas and cost value and will start with 0 with the next index as startingIndex
            // At the end if we are getting positive value of gas then its possible to start from that index and complete the loop
            if(g == 0)
                startIndex = start;
                
            g += gas[start];
            g -= cost[start];

            if(g < 0)
                g = 0;
        }
        
        return startIndex;
    }
};
