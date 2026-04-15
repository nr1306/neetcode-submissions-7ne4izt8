class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s2.size() < s1.size()) return false;
        map<char,int> freqS1;
        for(char ch : s1) freqS1[ch]++;
        
        int count = 0;
        for(int i=0; i<s1.size()-1; i++){
            if(freqS1[s2[i]]){
                count++;
            }
            freqS1[s2[i]]--;
        } 

        for(int i=0,j=s1.size()-1; j<s2.size(); i++,j++){
            if(freqS1[s2[j]]){
                count++;
            }
            freqS1[s2[j]]--;
            if(count == s1.size()) return true;
            
            // We are moving our window by 1 place so we'll restore the ith element's freq
            freqS1[s2[i]]++;
            if(freqS1[s2[i]]) count--;
        }
        return false;
    }
};
