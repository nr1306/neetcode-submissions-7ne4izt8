class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.size() > s2.size()) return false;

        // storing the freq of s1 first
        map<char,int> freqs1;
        for(int k=0; k<s1.size(); k++){
            freqs1[s1[k]]++;
        }

        int i=0, j=0;
        int count = 0; // will keep track of how many s1 ele found in substr
        // we'll keep a const window in s2 with i and j pointer
        for(; j<s1.size()-1; j++){
            if(freqs1[s2[j]]){
                count++;
            }
            freqs1[s2[j]]--; // reducing the freq of ele to identify which ele is abnormal for us (except s1)
        }

        for(; j<s2.size(); i++,j++){
            if(freqs1[s2[j]]){
                count++;
                if(count == s1.size()) return true;
            }
            freqs1[s2[j]]--;
            freqs1[s2[i]]++; // removing the ith ele from window and increaseing its freq back to normal
            if(freqs1[s2[i]]) count--;
        }
        return false;
    }
};
