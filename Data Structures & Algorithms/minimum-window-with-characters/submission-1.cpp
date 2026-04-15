class Solution {
public:
    string minWindow(string s, string t) {
        map<char,int> freqT;
        for(char ch : t) freqT[ch]--;
        int n = s.size(), m = t.size();
        if(m == 1 && find(s.begin(),s.end(),t[0]) != s.end()){
            return t;
        }
        int count = 0;
        int mini = INT_MAX;
        string res;
        for(int i=0,j=0; i<n && j<n; j++){
            if(freqT[s[j]] < 0){ // when we found char from string t
                count++;
                // if(!freq[s[j]]) count++; // we found all freq
            }   
            freqT[s[j]]++; // other char's freq will be always non-negative
            while(i<j && j<n && count == m){
                if(j-i+1 < mini){
                    mini = min(mini, j-i+1);
                    res = s.substr(i,j-i+1);
                }
                freqT[s[i]]--;
                if(freqT[s[i]]<0)
                    count--;
                i++;
            }
        }
        return res;
    }
};
