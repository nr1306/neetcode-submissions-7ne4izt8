class Solution {
public:
    int characterReplacement(string s, int k) {
        int maxfreq = 0;
        map<char,int> freq;
        int i=0, j=0, maxi = 1;

        for(; j<s.size(); j++){
            freq[s[j]]++;
            maxfreq = max(maxfreq, freq[s[j]]);
            int len = j-i+1;

            while(i<=j && len - maxfreq > k){
                freq[s[i]]--;
                i++;
                len = j-i+1;
            }
            maxi = max(maxi, j-i+1);
        }
        return maxi;
    }
};
