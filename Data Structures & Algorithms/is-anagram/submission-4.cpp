class Solution {
public:
    bool isAnagram(string s, string t) {
        map<char, int> freq;
        int ssize = s.size(), tsize = t.size();
        if(ssize != tsize) return false;
        for(int i=0; i<ssize; i++){
            freq[s[i]]++;
            freq[t[i]]--;
        }

        for(auto [key,val] : freq){
            if(val) return false;
        }
        return true;
    }
};
