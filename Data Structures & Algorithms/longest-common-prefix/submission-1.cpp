class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n = strs.size();
        int m = strs[0].size();
        
        string res = "";
        for(int j=0; j<m; j++){
            char ch = strs[0][j];
            int i=0;
            for(; i<n; i++){
                if(strs[i][j] != ch) break;
            }
            if(i == n) res += ch;
            else break;
        }

        return res;
    }
};