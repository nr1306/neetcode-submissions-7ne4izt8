class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        if(nums.size() == 1) return 1;

        map<int,int> freq;
        for(int x : nums) freq[x]++;

        int maxi = 1;
        int count = 0;
        int prev = 0;
        for(auto [key,val] : freq){
            if(!count){
                prev = key;
                count++;
                continue;
            }
            if(key == prev+1){
                count++;
                prev = key;
            }
            else{
                prev = key;
                count=1;
            }
            maxi = max(maxi, count);
        }
        return maxi;
    }
};
