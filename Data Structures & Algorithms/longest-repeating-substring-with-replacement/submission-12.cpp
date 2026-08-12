class Solution {
public:
    int characterReplacement(string s, int k) {
        map<char,int> freq;
        int maxFreq = 0;

        int maxLen = 0;
        for(int i=0,j=0; j<s.size(); j++){
            char ch = s[j];
            freq[ch]++;
            maxFreq = max(maxFreq, freq[ch]);

            while((j-i+1)-maxFreq > k){
                freq[s[i]]--;
                i++;
            }
            
            int len = j-i+1;
            maxLen = max(maxLen, len);
        }

        return maxLen;
    }
};
