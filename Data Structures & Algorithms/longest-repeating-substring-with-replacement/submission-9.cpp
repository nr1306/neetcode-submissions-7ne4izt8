class Solution {
public:
    int characterReplacement(string s, int k) {
        map<char, int> freq;
    // We'll iterate and keep on calculate the freq to determine the maxFreq till ith position we traversed
        int maxlen = 0;
        int maxfreq = 0;
        for(int i=0,j=0; j<s.size(); j++){
            freq[s[j]]++;
            maxfreq = max(maxfreq , freq[s[j]] );

            int len = j-i+1;
            if(len - maxfreq <= k){
                maxlen = max(maxlen , len);
            } 
            else{
                freq[s[i]]--; // we should reduce the freq of element we are passing from, its fine if we dont update maxfreq
                i++;
            }
        }
    // Why we won't reduce the size of window when window becomes invalid?
    // coz there is not use of reducing the max size of window we have reached coz we have to find the greater and greater values
    // Decreasing it will never give us our answer, so we are increasing our window size every time and if window is invalid we are shrinking it as well and reducing the freq of ith element to avoid incorrect freq value in window when expanding
    
        return maxlen;
    }
};
