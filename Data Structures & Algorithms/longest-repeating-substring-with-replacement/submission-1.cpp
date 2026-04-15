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
    // Here technically we should be updating the maxfreq too as we are decreasing the freq of certain element which could be max freq 
    // But we have to find the longest length of substr so decreasing the maxfreq won't ever give us the longest one
    // Instead we can leave it as it is if the length and maxfreq increases, we could find the bigger one but there is no use in fining the maxfreq smaller than current one
                freq[s[i]]--;
                i++;
            }
        }
        return maxi;
    }
};
