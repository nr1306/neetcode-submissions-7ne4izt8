class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n = s1.size();
        map<char,int> freqS1;
        map<char,int> freqS2;
        for(char ch : s1) freqS1[ch]++;
        
        int i=0,j=0;
        for(; j<n; j++){
            freqS2[s2[j]]++;
        }

        cout << endl;
        if(freqS1 == freqS2) return true;
        for(;j<s2.size(); i++,j++){
            freqS2[s2[i]]--;
            if(!freqS2[s2[i]]) freqS2.erase(s2[i]);
            
            freqS2[s2[j]]++;

            if(freqS1 == freqS2) return true;
        }

        return false;
    }
};
