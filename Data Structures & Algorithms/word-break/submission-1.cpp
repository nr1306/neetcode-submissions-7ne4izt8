class Solution {
public:
    bool f(string s, map<string, int>& mp, int i, int j, string res,
    vector<vector<int>>& dp){
        if(j == s.size()-1){
            string temp = s.substr(i,j-i+1);
            if(mp[temp]) return true;
            return false;
        }
        if(dp[i][j] != -1) return dp[i][j];

        res += s[j];
        string temp = s.substr(i,j-i+1);
        if(mp[temp] && f(s,mp,j+1,j+1,"",dp)) return dp[i][j] = true;
        return dp[i][j] = f(s,mp,i,j+1,res,dp);
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        map<string, int> mp;
        for(string str : wordDict)
            mp[str] = 1;
        vector<vector<int>> dp(s.size() , vector<int>(s.size(),-1));
        return f(s,mp,0,0,"",dp);
    }
};
