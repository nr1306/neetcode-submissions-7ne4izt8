class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size()) return false;

        map<int,int> freq;
        for(int i=0; i<s.size(); i++){
            freq[s[i]]++;
            freq[t[i]]--;
        }

        for(auto& [key,val] : freq){
            if(val) return false;
        }
        return true;
    }
};
