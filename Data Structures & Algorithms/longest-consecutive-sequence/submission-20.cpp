class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        map<int,int> mp;
        int n = nums.size();
        if(n == 0) return 0;
        
        for(int i=0; i<n; i++){
            mp[nums[i]] = i+1;
        }

        int count = 0;
        int maxi = 1;
        int prev = -1;
        // Instead of iterating through vector nums
        // will iterate in map which stores key in sorted fashion
        for(auto [key,value] : mp){
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
                count = 1;
            }

            maxi = max(maxi, count);
        }

        return maxi;
    }
};
