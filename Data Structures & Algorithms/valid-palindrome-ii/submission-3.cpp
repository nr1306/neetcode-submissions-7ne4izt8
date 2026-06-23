class Solution {
public:
    bool ispallindrome(string s , int i, int j){
        while(i<=j){
            if(s[i] != s[j]) return false;
            i++;
            j--;
        }
        return true;
    }

    bool validPalindrome(string s) {
        int i=0, j = s.size()-1;

        while(i <= j){

            if(s[i] != s[j]){
                if(j-1 >= i && s[i] == s[j-1])
                    if(ispallindrome(s,i,j-1)) return true;

                if(i+1 <= j && s[j] == s[i+1])
                    return ispallindrome(s,i+1,j);

                else return false;
            }

            i++;
            j--;
        }
        return true;
    }
};