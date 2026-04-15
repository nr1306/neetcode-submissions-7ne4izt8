class Solution {
public:
    int characterReplacement(string s, int k) {
        map<char, int> freq;
        int n = s.size(), maxi=0;
        int maxfreq = 0;
        
        for(int i=0,j=0; i<n && j<n; j++){
            freq[s[j]]++;
            maxfreq = max(maxfreq, freq[s[j]]);
            int length = j-i+1;

            if(length-maxfreq <= k){
                maxi = max(maxi, length);
            }
            else{
                freq[s[i]]--;
                i++;
            }
        }
        return maxi;
    }
};
