class Solution {
public:
    void f(string s, int i, int j, int& count){
        while(i>=0 && j<s.size() && s[i] == s[j]){
            count++;
            i--;
            j++;
        }
    }

    int countSubstrings(string s) {
        int count = 0;
        for(int i=0; i<s.size(); i++){
            // for odd length palindrome substrings
            f(s,i,i,count);

            // for even length palindrome substring
            f(s,i,i+1,count);

        }
        return count;
    }
};
