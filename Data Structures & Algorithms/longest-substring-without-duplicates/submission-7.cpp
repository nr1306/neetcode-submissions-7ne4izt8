class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        set<char> ss;
        int maxi = INT_MIN;
        for(int i=0,j=0; j<s.size(); j++){
            while(i<j && ss.find(s[j]) != ss.end()){
                int size = ss.size();
                maxi = max(maxi, size);
                ss.erase(s[i]);
                i++;
            }
            ss.insert(s[j]);
        }
        int size = ss.size();
        maxi = max(maxi, size);
        return maxi;
    }
};
