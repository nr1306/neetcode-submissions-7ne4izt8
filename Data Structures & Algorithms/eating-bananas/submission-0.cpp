class Solution {
public:
    int time(vector<int> piles, int rate){
        int timeTaken = 0;
        for(int x : piles){
            if(x >= rate)
                timeTaken += x/rate + (x%rate ? 1 : 0);
            else
                timeTaken += 1;
        }
        return timeTaken;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int maxi = INT_MIN;
        for(int x : piles){ maxi = max(maxi, x); }
        if(h == piles.size()) return maxi;

        int start = 1, end = maxi-1, mini = maxi;
        while(start <= end){
            int mid = (end-start)/2 + start;
            int timeTook = time(piles,mid);
            if(timeTook <= h){ 
                mini = min(mini, mid); 
                end = mid-1;
            }
            else{
                start = mid+1;
            }
        }
        return mini;
    }
};
