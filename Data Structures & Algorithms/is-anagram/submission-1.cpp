class Solution {
public:
    bool isAnagram(string s, string t) {
        map<char, int> freq;
        for(char ch : s){
            freq[ch]++;
        }
        for(char ch : t){
            if(!freq[ch])
                return false;
            freq[ch]--;
        }
        for(auto it : freq){
            if(it.second)
                return false;
        }
        return true;
    }
};
