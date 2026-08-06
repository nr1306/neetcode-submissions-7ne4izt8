class Solution {
public:
    bool isValidPalindrome(string s){
        int i=0, j=s.size()-1;

        while(i<=j){
        if(s[i] != s[j]) return false;
        i++;
        j--;
       } 
       return true;

    }

    bool validPalindrome(string s) {
       int i=0, j=s.size()-1;

       while(i<=j){
        if(s[i] != s[j]){
            return isValidPalindrome(s.substr(i,j-i)) || 
            isValidPalindrome(s.substr(i+1,j-i));
        }
        i++;
        j--;
       } 
       return true;
    }
};