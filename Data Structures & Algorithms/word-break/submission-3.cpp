class Solution {
public:
    bool solve(string s, set<string>& dict, string word, 
    vector<vector<int>>& dp, int i, int j){
        if(j == s.size()-1){
            string temp = s.substr(i, j-i+1);
            return (dict.find(temp) != dict.end()); 
        }

        if(dp[i][j] != -1) return dp[i][j];

        word += s[j];
        string temp = s.substr(i,j-i+1); // This will be intermediate substr coz word string will calculate substr from beginning, but we are changing our starting pointer i as well, so we have to check this temp string 
// Two cases whether we find a intermediate substr which is present in the set, then too we have two paths, one is to start from empty string second is to continue taking next char

        bool res1 = false;
        if(dict.find(temp) != dict.end()){ // checking the intermediate str
            res1 = solve(s,dict,"",dp,j+1,j+1); // we are gonna start scratch and search for new string present in the set
        }
        bool res2 = solve(s,dict,word,dp,i,j+1);
        
        return dp[i][j] = (res1 || res2);
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        set<string> dict (wordDict.begin(), wordDict.end());
        vector<vector<int>> dp(s.size(), vector<int>(s.size()-1,-1));
        string word = "";
        return solve(s,dict,word,dp,0,0);
    }
};
