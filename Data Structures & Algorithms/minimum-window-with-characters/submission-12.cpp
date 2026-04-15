class Solution {
public:
    string minWindow(string s, string t) {
        if(t.size() > s.size() || t == "") return "";

        map<char, int> freq;
        for(char ch: t) freq[ch]++; // m storing negative freq of t
        
        int count = 0, mini = INT_MAX, start = -1;

        for(int i=0,j=0; j<s.size(); j++){
            if(freq[s[j]] > 0) // if we found a char from t string
                count++;
            freq[s[j]]--; // abnormally increasing freq of every char

            while(i<=j && count == t.size()){ // if we found a valid substr, we have to find the smallest one, so we'll reduce our window size until its min valid substr
                if(j-i+1 < mini){
                    start = i;
                    mini = min(mini, j-i+1);
                }
                
                freq[s[i]]++;
                if(freq[s[i]] > 0) count--;
                i++;
            }
        }

        if(start == -1) return "";
        return s.substr(start, mini);
    }
};
