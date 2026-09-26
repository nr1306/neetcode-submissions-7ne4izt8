class Solution {
public:
    bool solve(vector<int>& sticks, int i, int t, int b, int l, int r, 
    int target){
        if(i == sticks.size()){
            if(t == b && l == r && t == l){
                return true;
            }
            return false;
        }

        bool resT = false, resB = resT, resL = resT, resR = resT;

        if(t + sticks[i] <= target)
            resT = solve(sticks, i+1, t+sticks[i], b,l,r, target);
        
        if(b + sticks[i] <= target)
            resB = solve(sticks, i+1, t, b+sticks[i],l,r, target);
        
        if(l + sticks[i] <= target)
            resL = solve(sticks, i+1, t, b,l+sticks[i],r, target);
        
        if(r + sticks[i] <= target)
            resR = solve(sticks, i+1, t, b,l,r+sticks[i], target);

        return resT || resB || resL || resR;
    }

    bool makesquare(vector<int>& matchsticks) {
        int sum = 0;
        for(int x : matchsticks)
            sum += x;
        
        if(sum%4 != 0) return false;
        return solve(matchsticks, 0, 0, 0, 0, 0, sum/4);
    }
};