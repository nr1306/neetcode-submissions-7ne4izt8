class Solution {
public:
    int characterReplacement(string s, int k) {
        map<char,int> freq;
        int maxfreq = 0;
        int maxi = 0;
        for(int i=0,j=0; j<s.size();j++){
            freq[s[j]]++;
            maxfreq = max(maxfreq,freq[s[j]]);
            if(j-i+1 - maxfreq <= k){
                maxi = max(maxi, j-i+1);
            }
            else{
                freq[s[i]]--;
                i++;
            }
        }
        return maxi;
    }
};
