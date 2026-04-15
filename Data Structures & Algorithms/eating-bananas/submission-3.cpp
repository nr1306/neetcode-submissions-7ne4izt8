class Solution {
public:
    int hours(vector<int>& piles, int rate){
        int hrs = 0;
        for(int banana : piles){
            hrs += ceil((double)banana/rate);
        }
        return hrs;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int end = piles[0];
        for(int banana : piles)
            end = max(banana, end);
        int start = 1; // 1 banana per hour
        int mini = INT_MAX;

        while(start <= end){
            int mid = (end-start)/2 + start; // Lets see how many hours it will take to finish the piles with mid banana per hour
            if(hours(piles, mid)<=h){
                mini = min(mini, mid);
                end = mid-1;
            }
            else start = mid+1;
        }

        return mini;
    }
};
