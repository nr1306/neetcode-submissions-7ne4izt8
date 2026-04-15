class Solution {
public:
    bool isPalindrome(string s) {

        for(int i=0; i<s.size(); i++){
            if((s[i] >= 'a' && s[i] <= 'z') || 
            (s[i] >= '0' && s[i] <= '9')) continue;

            else if(s[i] >= 'A' && s[i] <= 'Z') s[i] += 32; // making all upercase to lowercase
            else{
                s.erase(s.begin()+i);
                i--;
            }
        }
        cout << s;
        int i=0, j=s.size()-1;
        while(i<=j){
            if(s[i] != s[j]) return false;
            i++;
            j--;
        }
        return true;
    }
};
