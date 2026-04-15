class Solution {
public:
    string minWindow(string s, string t) {
        if(t.size() > s.size()) return "";
        if(s == t) return s;

        map<char, int> freq;
        for(char ch : t) freq[ch]--; // x - -1 , y = -1 , z = -1

        int count = 0;
        int mini = s.size();
        string res = "";

        for(int i=0,j=0; j<s.size(); j++){
            if(freq[s[j]] < 0){
                count++; // increase till count == t.size()
            }
            freq[s[j]]++;

            while(i<=j && count == t.size()){
                if(j-i+1 <= mini){
                    mini = j-i+1;
                    res = s.substr(i,j-i+1);
                }
                freq[s[i]]--;
                if(freq[s[i]] < 0){
                    count--;
                }
                i++;
            }
        }
        return res;
    }
};
