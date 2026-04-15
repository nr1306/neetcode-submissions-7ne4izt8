class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int k = s1.size(),n = s2.size();
        if(k > n) return false; // impossible

        map<char, int> freqS1;
        for(char ch : s1) freqS1[ch]++;

        for(int i=0,j=k-1; i<n && j<n; i++,j++){
            int count = 0;
            map<char, int> temp = freqS1;
            for(int l=i; l<=j; l++){
                if(temp[s2[l]]){
                    temp[s2[l]]--;
                    count++;
                }
            }
            if(count == k) return true;
        }
        return false;
    }
};
