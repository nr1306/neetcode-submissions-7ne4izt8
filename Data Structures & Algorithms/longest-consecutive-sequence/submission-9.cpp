class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        map<int,int> mp;
        for(int i=0; i<nums.size(); i++){
            mp[nums[i]] = i+1;
        }
    // We are told to find the longest sequence of consecutive elements
    // 2 5 4 3 4 6 7 
    // Longest consecutive sequence would be [2,3,4] or [5,6,7]
    // That's why I utilized map to locate next consecutive element easily
    // Also here we are told to find sequence of elemnts not Subsequence, it means order of elements doesn't matter
        int maxi = 1;
        for(int i=0; i<nums.size(); i++){
            int ele = nums[i];
            int count = 1;
            while(mp[ele+1]){
                ele++;
                count++;
                
                maxi = max(maxi, count);
            }
        }
        return maxi;
    }
};
