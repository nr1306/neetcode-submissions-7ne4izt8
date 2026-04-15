class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int k = s1.size(),n = s2.size();
        sort(s1.begin(), s1.end());

        for(int i=0,j=i+k-1; j<n; i++,j++){
            string temp = s2.substr(i, j-i+1);
            sort(temp.begin(), temp.end());
            if(temp == s1) return true;
        }
        return false;
    }
};
