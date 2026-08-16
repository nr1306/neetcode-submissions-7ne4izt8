class Solution {
public:
    int daysShipTake(vector<int>& weights, int maxW){
        int n = weights.size();
        int days = 0;
        for(int i=0; i<n;){
            int weight = 0;

            while(i<n && weight + weights[i] <= maxW){
                weight += weights[i];
                i++;
            }
            
            days++;
        }

        return days;
    }

    int shipWithinDays(vector<int>& weights, int days) {
        int i = 0,j = 0;

        for(int x : weights){
            i = max(i,x);
            j += x;
        }

        int res = j;

        while(i<=j){
            int mid = (j-i)/2 + i;

            if(daysShipTake(weights, mid) <= days){
                res = mid;
                j=mid-1;
            }
            else i = mid+1;
        }

        return res;
    }
};