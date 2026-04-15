class Solution {
public:
    bool isPalindrome(string s) {
        for(int i=0; i<s.size(); i++){
            if(s[i] >= 'A' && s[i] <= 'Z'){
                s[i] += 32;
            } 
            else if(s[i] >= 'a' && s[i] <= 'z') continue;
            else if(s[i] >= '0' && s[i] <= '9') continue;
            else{
                s.erase(s.begin()+i);
                i--;
            } 
        }
        cout << s;
        int n = s.size();
        for(int i=0; i<n/2; i++){
            if(s[i] != s[n-i-1]) return false;
        }
        return true;
    }
};

