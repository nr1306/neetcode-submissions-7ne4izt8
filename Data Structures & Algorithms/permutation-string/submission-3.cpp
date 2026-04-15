class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        map<char, int> freq1;
        for(char ch : s1) freq1[ch]++;
        int n = s2.size(), m = s1.size();
        if(m > n) return false;
        // we are maintaining a fixed window size and then cheking the freq of char in that window
        for(int i=0,j=m-1; i<n && j<n; i++,j++){
            int count = 0; // will increase the counter when we encounter elements of s1 and then later compare to the size of s1
        // to not lose the original frequency of char of s1
            map<char, int> temp = freq1;
            for(int k=i; k<=j; k++){
                if(temp[s2[k]]){
                    temp[s2[k]]--;
                    count++;
                }
            }  
            if(count == m) return true;
        }
        return false;
    }
};
