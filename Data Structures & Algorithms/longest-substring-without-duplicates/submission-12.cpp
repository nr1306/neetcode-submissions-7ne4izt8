class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        set<char> unique;
        int i=0, j=0;
        int maxi = 0;
        for(; j<s.size(); j++){
            while(i<=j && unique.find(s[j]) != unique.end()){
                unique.erase(s[i]);
                i++;
            }
            unique.insert(s[j]);
            maxi = max(maxi, j-i+1);
        }
        return maxi;
    }
};
