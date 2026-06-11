class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size()) return false;
        
        map<int,int> freq;
        for(int i=0; i<s.size(); i++){
            freq[s[i]]++;
            freq[t[i]]--;
        }

        for(auto [key,value] : freq){
            if(value) return false; // If value is positive for any char then they are not anagrams
        }
        return true;
    }
};
