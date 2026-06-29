class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        if(n <= 1) return n;

        set<char> ss;
        int i=0, j=0;
        int maxi = 1;

        for(; j<n; j++){
            while(i<j && ss.find(s[j]) != ss.end()){
                ss.erase(s[i]);
                i++;
            }
            ss.insert(s[j]);
            int size = ss.size();
            maxi = max(maxi, size);
        }

        return maxi;
    }
};
