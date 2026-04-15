class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        set<char> unique;
        int maxi = 0;
        for(int i=0,j=0; j<s.size(); ){
            char ch = s[j];
            int size = unique.size();
            unique.insert(ch);
            if(unique.size() == size){
                unique.erase(s[i]);
                i++;
            }
            else{
                maxi = max(maxi, j-i+1);
                j++;
            }
        }
        return maxi;
    }
};
