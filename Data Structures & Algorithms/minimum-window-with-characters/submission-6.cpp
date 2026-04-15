class Solution {
public:
    string minWindow(string s, string t) {
        if(t.size() > s.size()) return "";
        if(t == s) return t;
        map<int,int> freq;
        for(char ch : t) freq[ch]++;

        int count = 0;
        int mini = INT_MAX;
        int start = -1;
        for(int i=0, j=0; j<s.size(); j++){
            char ch = s[j];
            if(freq[ch]>0) count++;
            freq[ch]--;

            while(i<=j && count == t.size()){
                if(j-i+1 <= mini){
                    mini = j-i+1;
                    start = i;
                }
                freq[s[i]]++;
                if(freq[s[i]]>0) count--;
                i++;
            }
        }
        if(start == -1) return "";
        return s.substr(start,mini);
    }
};
