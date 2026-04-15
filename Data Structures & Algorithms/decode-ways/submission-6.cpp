class Solution {
public:
    int solve(string s, int i, vector<int>& dp){
        if(i == s.size()) return 1;

        if(dp[i] != -1) return dp[i];

        int ways = 0;
        if(s[i] != '0')
            ways += solve(s,i+1, dp);
        
        if(i+1 < s.size() && ((s[i] == '2' && s[i+1] <= '6') || s[i] == '1'))
            ways += solve(s,i+2, dp);

        return dp[i] = ways; 
    }

    int numDecodings(string s) {
        vector<int> dp(s.size()+1, -1);
        return solve(s,0,dp);
    }
};
