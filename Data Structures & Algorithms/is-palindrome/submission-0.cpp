class Solution {
public:
    bool isPalindrome(string s) {
        s.erase(
            remove_if(s.begin(),s.end(),[](char c){ return !isalnum(c); }),
        s.end());
        int i=0, j=s.size()-1;
        while(i < j){
            if(s[i] >= 'A' && s[i] <= 'Z')
                s[i] += 32;
            if(s[j] >= 'A' && s[j] <= 'Z')
                s[j] += 32;
            if(s[i] != s[j])
                return false;
            i++;
            j--;
        }
        return true;
    }
};
