class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        map<char, int> freqS1;
        for(char ch : s1) freqS1[ch]++;

        int n = s1.size(), m = s2.size(); 
        if(n > m) return false; // not possible

        for(int i=0,j=n-1; i<m && j<m; i++,j++){
            int count = 0;
            map<char,int> temp = freqS1;
            for(int k=i; k<=j; k++){
                if(temp[s2[k]]){
                    temp[s2[k]]--;
                    count++;
                }
            }
            if(count == n) return true;
        }
        return false;
        
    }
};
