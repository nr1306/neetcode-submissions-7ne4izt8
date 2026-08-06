class Solution {
public:
    bool isalphanum(char ch){
        if((ch >= 'A' && ch <= 'Z')
        || (ch >= 'a' && ch <= 'z')
        || (ch >= '0' && ch <= '9'))
            return true;
        return false;
    }

    bool isPalindrome(string s) {

       int l = 0, r = s.size()-1;
       while(l <= r){
        if(!isalphanum(s[l])) l++;
        else if(!isalphanum(s[r])) r--;
        else if(tolower(s[l]) != tolower(s[r])) return false;
        else{
            l++;
            r--;
        }
       }

       return true;
    }
};
