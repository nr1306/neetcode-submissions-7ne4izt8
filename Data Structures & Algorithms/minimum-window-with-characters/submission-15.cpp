class Solution {
public:
    string minWindow(string s, string t) {
        if(s.size() < t.size()) return "";

        map<char,int> freqT;
        for(char ch : t){
            freqT[ch]--;
        }

        int mini = INT_MAX;
        int start = -1;
        int count = 0;
        for(int i=0,j=0; j<s.size(); j++){
            if(freqT[s[j]] < 0)
                count++;

            freqT[s[j]]++;

            while(i<=j && count == t.size()){
                if(j-i+1 < mini){
                    mini = min(mini, j-i+1);
                    start = i;
                }
                freqT[s[i]]--;
                if(freqT[s[i]] < 0) count--;
                i++;

            }
        }

        return start == -1 ? "" : s.substr(start, mini);
    }
};
