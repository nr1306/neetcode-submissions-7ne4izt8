class Solution {
public:
    void f(int n, int& count){
        if(n<=0){
            count++;
            return;
        }

        f(n-1,count);
        if(n>1)
            f(n-2,count);
    }

    int climbStairs(int n) {
        int count = 0;
        f(n,count);
        return count;
    }
};
