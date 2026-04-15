class Solution {
public:
    bool solve(string s, set<string>& dict, string word, int i, int j,
    vector<vector<int>>& dp){

        if(j == s.size()-1){
            string temp = s.substr(i, j-i+1);
            return dict.find(temp) != dict.end();
        }

        if(dp[i][j] != -1) return dp[i][j];

        // we are gonna take every char in our superstr word
        word += s[j];
        string temp = s.substr(i, j-i+1); // intermediate string

        if(dict.find(temp) != dict.end()){
            if(solve(s,dict,"",j+1,j+1,dp))
                return dp[i][j] = true;
        }
        return dp[i][j] = solve(s,dict,word,i,j+1,dp);
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        set<string> dict(wordDict.begin(), wordDict.end());
        vector<vector<int>> dp(s.size(), vector<int>(s.size()+1, -1));
        return solve(s,dict,"",0,0, dp);
    }
};
