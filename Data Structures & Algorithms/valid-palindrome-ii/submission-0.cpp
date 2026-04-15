class Solution {
public:
    bool isPalindrome(string s, int i, int j){
        while(i<j){
            if(s[i] != s[j]) return false;
            i++;
            j--;
        }
        return true;
    }
    bool validPalindrome(string s) {
        int i=0, j=s.size()-1;
        while(i<j){
            if(s[i] != s[j]){
    // If there is a mismatch, then we'll try both ways where we are skipping one char from the left and one char from the right
                if(isPalindrome(s,i+1,j) || isPalindrome(s,i,j-1))
                    return true;
                return false; // if after trying both ways, second mismatch found then it can't be a palindrome after removing a char
            }
            i++;
            j--;
        }
        return true; // The string is already a palindrome
    }
};