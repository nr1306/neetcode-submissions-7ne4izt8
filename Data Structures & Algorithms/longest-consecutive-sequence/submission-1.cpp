class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size() <= 1)
            return nums.size();
        map<int, int> freq;
        for(int i=0; i<nums.size(); i++){
            freq[nums[i]]=i+1;
        }
        int maxlen = 1;
        for(int i=0; i<nums.size(); i++){
            int ele = nums[i],count = 1;
            while(freq[ele+1]){
                ele = ele+1;
                count++;
            }
            maxlen = max(maxlen , count);
            if(count == nums.size()){
                break;
            }
        }  
        return maxlen;      
    }
};
