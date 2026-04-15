class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        set<char> ch;
        int maxi = 0;

        for(int i=0,j=0; j<s.size();){
    
    // If no char is repeated yet
            if(ch.find(s[j]) == ch.end()){
                ch.insert(s[j]);
                j++;
            } 
            else{
                ch.erase(s[i]);
                i++;
            }
            int size = ch.size(); // coz we can't directly use set size
            maxi = max(maxi, size);
        }
        return maxi;
    }
};
