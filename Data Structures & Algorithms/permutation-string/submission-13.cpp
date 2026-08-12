class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        map<int,int> freq;
        for(char ch : s1) freq[ch]++;
        
        int count = 0;

        int i=0, j=0;
        for(; j<s1.size()-1; j++){
            if(freq[s2[j]] > 0) count++;
            freq[s2[j]]--;
        }

        for(; j<s2.size(); i++,j++){
            if(freq[s2[j]] > 0) count++;
            freq[s2[j]]--;

            if(count == s1.size()) return true;

            freq[s2[i]]++;
            if(freq[s2[i]] > 0) count--;
        }
        return false;
    }
};
