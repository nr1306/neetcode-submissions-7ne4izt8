class Solution {
public:
    int mySqrt(int x) {
        if(x <= 1) return x;
        int end = x/2;
        int start = 1;

        while(start <= end){
            int mid = (end-start)/2 + start;
            long long square = (long long)mid*mid;
            if(square == x) return mid;
            else if(square > x) end = mid-1;
            else start = mid+1;
        }
        if(start*start > x) return end;
        return end;
    }
};