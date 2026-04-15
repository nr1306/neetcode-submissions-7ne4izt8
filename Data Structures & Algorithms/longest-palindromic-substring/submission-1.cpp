class Solution {
public:

    void f(string s, string& res, int i, int j, int& maxlen){
        while(i>=0 && j<s.size() && s[i] == s[j]){
            int len = j-i+1;
            if(len > maxlen){
                maxlen = len;
                res = s.substr(i,j-i+1);
            }
            i--;
            j++;
        }
    }

    string longestPalindrome(string s) {
        string res = "";
        int maxlen = 0;
        for(int i=0; i<s.size(); i++){
            // for odd length palindrome substrings
            f(s,res,i,i,maxlen);

            // for even length palindrome substring
            f(s,res,i,i+1,maxlen);

        }
        return res;
    }
};
