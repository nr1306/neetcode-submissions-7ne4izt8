class Solution {
public:
    int hoursEatingBanans(vector<int>& piles, int rate){
        int hours = 0;
        for(int x : piles){
            hours += ceil((double)x/rate);
        }
        return hours;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int i = 1, j = h;
        for(int x : piles) j = max(j,x);

        int rate = h;
        while(i<=j){
            int mid = (j-i)/2 + i;

            if(hoursEatingBanans(piles,mid) <= h){
                j = mid-1;
                rate = mid;
            }
            else i = mid+1;
        }

        return rate;
    }
};
