class Solution {
public:
    int characterReplacement(string s, int k) {
        int maxFreq = 0;
        map<char, int> freq;
        int n = s.size();
        int maxi = INT_MIN;

        for(int i=0, j=0; j<n; j++){
            freq[s[j]]++;
            maxFreq = max(maxFreq, freq[s[j]]);

            while(i<j && (j-i+1)-maxFreq > k){
                freq[s[i]]--;
                i++;
            }
            int len = j-i+1;
            maxi = max(maxi, len);
        }
        return maxi;
    }
};
