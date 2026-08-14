class Solution {
public:
    string minWindow(string s, string t) {
        if(t.size() > s.size()) return "";

        map<char,int> freq;
        for(char ch : t) freq[ch]++;

        int minlen = INT_MAX;

        int count = 0;
        int start = -1;

        for(int i=0,j=0; j<s.size(); j++){
            if(freq[s[j]] > 0)
                count++;
            
            freq[s[j]]--;

            while(i<=j && count == t.size()){
                if(j-i+1 < minlen){
                    minlen = j-i+1;
                    start = i;
                }

                freq[s[i]]++;
                if(freq[s[i]] > 0) count--;
                i++;
            }
        }
        return start == -1 ? "" : s.substr(start, minlen);
    }
};
