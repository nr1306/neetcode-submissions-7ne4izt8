class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.size();
        map<char, int> freq;
        
        for(char ch : t) freq[ch]++;
        
        int i=0,j=0;
        int count = 0;
        int minlen = INT_MAX, startIndex = -1;

        while(j<n){
            if(freq[s[j]] > 0){
                count++;
            }
            freq[s[j]]--;

            while(i<n && count == t.size()){
                if(j-i+1 < minlen){
                    minlen = min(minlen, j-i+1);
                    startIndex = i;
                }
                freq[s[i]]++;
                if(freq[s[i]] > 0){
                    count--;
                }
                i++;
            }

            j++;
        }
        

        // Now we have found a valid window substring which contains all character in s
        // substr length is from ith index to jth index
        // Now we'll shrink it until its valid

        if(startIndex == -1) return "";
        return s.substr(startIndex,minlen);
    }
};
