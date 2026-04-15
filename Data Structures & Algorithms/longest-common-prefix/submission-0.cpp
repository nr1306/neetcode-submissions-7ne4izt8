class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string res = "";
        for(int j=0; j<strs[0].size(); j++){
            char ch = strs[0][j];
            bool present = true;
            for(int i=0; i<strs.size(); i++){
                if(strs[i][j] != ch){
                    present = false;
                    break;
                }
            }
            if(present) res.push_back(ch);
            else break;
        }
        return res;
    }
};