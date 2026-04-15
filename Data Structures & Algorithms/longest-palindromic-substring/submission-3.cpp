class Solution {
public:
    void solve(string s, int i, int j, int& start, int& maxi){
        while(i>=0 && j<s.size() && s[i] == s[j]){
            if(j-i+1 > maxi){
                start = i;
                maxi = max(maxi, j-i+1);
            }

            i--;
            j++;
        }
    }

    string longestPalindrome(string s) {
        int start = 0, maxi = 1;
        for(int i=0; i<s.size(); i++){
            // odd pallindrome string
            solve(s,i,i,start,maxi);

            // even pallindrome string
            solve(s,i,i+1,start,maxi);
        }

        return s.substr(start, maxi);
    }
};
