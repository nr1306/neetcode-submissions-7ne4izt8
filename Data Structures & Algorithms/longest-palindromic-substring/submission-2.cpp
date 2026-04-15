class Solution {
public:
    void solve(string s, int i, int j, string& res, int& maxi){
        while(i>=0 && j<s.size() && s[i] == s[j]){
            int len = j-i+1;
            if(len > maxi){
                maxi = len;
                res = s.substr(i, len);
            }
            i--;
            j++;
        }
    }

    string longestPalindrome(string s) {
        string res = "";
        int maxi = 0;
        for(int i=0; i<s.size(); i++){
            // odd pallindrome string
            solve(s,i,i,res,maxi);

            // even pallindrome string
            solve(s,i,i+1,res,maxi);

            int size = res.size();
            maxi = max(maxi,size);
        }

        return res;
    }
};
