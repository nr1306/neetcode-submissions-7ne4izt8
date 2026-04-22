class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        map<int,int> freq;
        for(int x : nums) freq[x]++;

        int maxi = 0;
        for(int x : nums){
            int count = 1;
            while(freq[x+1]){
                count++;
                x++;
            }
            maxi = max(maxi,count);
        }
        return maxi;
    }
};
