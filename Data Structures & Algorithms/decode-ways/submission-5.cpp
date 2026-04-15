class Solution {
public:
    void solve(string s, int i, int& count){
        if(i >= s.size()){
            count++;
            return;
        }

        if(s[i] != '0') 
            solve(s,i+1,count);

        if(i+1 < s.size() && ((s[i] == '2' && s[i+1] >= '0' && s[i+1] <= '6') || s[i] == '1')){
            solve(s,i+2,count);
        }  
        
    }

    int numDecodings(string s) {
        int count = 0;
        solve(s,0,count);
        return count;
    }
};
