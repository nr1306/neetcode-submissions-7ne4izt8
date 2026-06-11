class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n = strs.size();
        int m = strs[0].size();
        if(n == 1) return strs[0];

        map<char,int> freq;
        string res = "";

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                freq[strs[j][i]]++;
            }
            if(freq[strs[0][i]] == n){
                res += strs[0][i];
                freq.clear();
            }
            else break;
        }
        return res;
    }
};