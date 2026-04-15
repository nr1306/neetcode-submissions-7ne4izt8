class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        if(!n) return 0;
        set<char> subs;
        int maxi = INT_MIN;

        for(int i=0,j=0; i<n && j<n; j++){
            int size = subs.size();
            subs.insert(s[j]);
            if(subs.size() == size){// It means jth char is already present
                subs.erase(s[i]);
                i++;
                j--;
            }
            size = subs.size();
            maxi = max(maxi, size);
        }
        return maxi;
    }
};
