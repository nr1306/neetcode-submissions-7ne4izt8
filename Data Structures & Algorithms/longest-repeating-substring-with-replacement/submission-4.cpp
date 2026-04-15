class Solution {
public:
    int characterReplacement(string s, int k) {
        map<char,int> freq;
        int maxFreq = 0;
        int maxi = 0;

        for(int i=0,j=0; j<s.size(); j++){
            freq[s[j]]++;
            maxFreq = max(maxFreq,freq[s[j]]);

            if(j-i+1 - maxFreq <= k){ // Substr is valid
                maxi = max(maxi, j-i+1);
            }
            else{ // substr becomes invalid
                freq[s[i]]--;
                i++;
            }
        }
        return maxi;
    }
};
