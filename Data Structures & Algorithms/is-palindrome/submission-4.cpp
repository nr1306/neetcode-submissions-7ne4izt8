class Solution {
public:
    bool isPalindrome(string s) {
        // first Will format the string - remove alphanumeric
        // stay consistent with the alphabet's case

        for(int i=0; i<s.size(); i++){
            if(s[i] >= 'A' && s[i] <= 'Z'){
                s[i] += 32;
            }
            else if(!( 
            (s[i] >= 'a' && s[i] <= 'z') || 
            s[i] >= '0' && s[i] <= '9' ) ){
                s.erase(s.begin()+i);
                i--;
            }
        }

        int i=0, j = s.size()-1;
        while(i<=j){
            if(s[i] != s[j]) return false;
            i++; j--;
        }

        return true;
    }
};
