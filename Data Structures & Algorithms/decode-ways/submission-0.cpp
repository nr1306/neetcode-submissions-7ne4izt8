class Solution {
public:
    bool isValid(string str){
        if(str[0] == '0') return false;
        if(str.size() == 1) return true;
        if(str[0] == '1' || (str[0] == '2' && str[1] <= '6')) return true;
        return false;
    }

    void f(string s, int i, int j, int& count){
        if(i != -1 && j!= -1 && (j>=s.size() || !isValid(s.substr(i,j-i+1)))) return;
        if(j == s.size()-1){
            if(isValid(s.substr(i,j-i+1))) count++;
            return;
        }
        
        f(s,j+1,j+1,count);
        f(s,j+1,j+2,count);
    }

    int numDecodings(string s) {
        int count = 0;
        f(s,-1,-1,count);
        return count;
    }
};
