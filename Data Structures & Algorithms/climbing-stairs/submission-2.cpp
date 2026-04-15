class Solution {
public:
    int solve(int n){
        if(n < 1) return 0;
        if(n == 2) return 2;
        if(n == 1) return 1;

        int count1 = solve(n-1);
        int count2 = 0;
        if(n > 2)
            count2 = solve(n-2);

        return count1 + count2;
    }

    int climbStairs(int n) {
        return solve(n);
    }
};
