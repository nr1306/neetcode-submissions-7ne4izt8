class Solution {
public:
    int numberDays(vector<int>& weights, int weight){
        int days = 0;
        int sum = 0;
        for(int w : weights){
            if(sum + w <= weight){
                sum += w;
            }
            else{
                days++;
                sum = w;
            }
        }
        return days+1;
    }

    int shipWithinDays(vector<int>& weights, int days) {
        int end = 0; // will store sum of weights
        int start = 0; // will store max weight (min required to ship every cargo)
        for(int x : weights){
            start = max(start, x);
            end += x;
        }
        // we'll select the range from max weight to sum of weights
        // As we can't break down a weight and ship them different days
        // We can decide whether we can send all weights within days by simply adding all the weights and dividing it by the weight we are selecting at a moment, to see how many days will it take
        int res = end;
        while(start <= end){
            int mid = (end-start)/2 + start;
            if(numberDays(weights,mid) <= days){
                res = min(res,mid);
                end = mid-1;
            }
            else start = mid+1;
        }

        return res;
    }
};