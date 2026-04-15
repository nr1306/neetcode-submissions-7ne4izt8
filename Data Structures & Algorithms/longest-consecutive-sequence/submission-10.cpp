class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        map<int,int> freq;
        int maxi = 0;
        for(int x : nums) freq[x]++;

        for(int i=0; i<nums.size(); i++){
            int ele = nums[i];
            int count = 0;
            while(freq[ele]){
                ele++;
                count++;
            }
            maxi = max(maxi, count);
        }
        return maxi;
    }
};
