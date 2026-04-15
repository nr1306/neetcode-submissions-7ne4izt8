class Solution {
public:
    bool validPalindrome(string s, int i, int j){
        while(i<=j){
            if(s[i] != s[j]) return false;
            i++;
            j--;
        }
        return true;
    }

    void f(string s, string& res, int i, int j){
        if(i == s.size()){
            return;
        }
        for(; j<s.size(); j++){
            if(validPalindrome(s,i,j)){
                if(j-i+1 > res.size()) res = s.substr(i,j-i+1);
            }
        }
        f(s,res,i+1,i+1);
    }

    string longestPalindrome(string s) {
        string res = "";
        f(s,res,0,0);
        return res;
    }
};
