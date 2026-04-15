class Solution {
public:
    int timeEatBananas(vector<int>& piles, int k){
        int time = 0;
        for(int x : piles){
            time += ceil((double)x/k);
        }
        return time;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int maxi = 0;
        for(int x : piles) maxi = max(maxi, x);
        int res = maxi;

    // maxi number of bananas in any pile will be the max eating rate to eat all bananas
    // We'll check rates at which we can eat under h hours and calc the minimum
        int start = 1, end = maxi;
        while(start <= end){
            int mid = (start+end)/2;
            int timeTaken = timeEatBananas(piles, mid);

            if(timeTaken <= h){
                res = min(res, mid);
                end = mid-1;
            }
            else start = mid+1;
        }
        
        return res;
    }
};
