class Solution {
public:
    int characterReplacement(string s, int k) {
        int maxFreq = 0;
        map<char,int> freq;
        int maxi = 0;

        for(int i=0,j=0; j<s.size(); j++){
            freq[s[j]]++;
            maxFreq = max(maxFreq, freq[s[j]]);
            
            if((j-i+1)-maxFreq > k){
                freq[s[i]]--; // crucial step, coz we are shrinking the window so we must decrease the freq of that removed element for accurate computation
                i++;
            }
            maxi = max(maxi, j-i+1);
        }
        return maxi;
    }
};
