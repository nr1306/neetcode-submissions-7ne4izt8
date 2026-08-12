class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        set<int> st;
        int maxlen = 0;
        for(int i=0,j=0; j<s.size(); j++){
    // If our substring is invalid - will shrink our window
            while(st.find(s[j]) != st.end()){
                st.erase(s[i]);
                i++;
            }
        // It will be our valid substring
            maxlen = max(maxlen , j-i+1);
            st.insert(s[j]);
        }

        return maxlen;
    }
};
