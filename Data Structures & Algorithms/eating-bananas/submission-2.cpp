class Solution {
public:
    int time(vector<int>& piles, int rate){
        int t = 0;
        for(int x : piles){
            t += ceil(double(x)/rate);
        }
        return t;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int end = 0;
        for(int x : piles)
            end = max(end, x);
        // we'll select the range from 1 to max pile of banana
        int start = 1;

        int res = end;
        while(start <= end){
            int mid = (end-start)/2 + start;
            if(time(piles, mid) <= h){
                res = min(res,mid);
                end = mid-1;
            }
            else start = mid+1;
        }

        return res;
    }
};
