class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int sum = 0;
        int minlen = nums.size()+1;
        for(int i=0,j=0; j<nums.size(); j++){
            sum += nums[j];

            while(i<=j && sum >= target){
                minlen = min(minlen, j-i+1);
                sum -= nums[i];
                i++;
            } 
        }
        if(minlen == nums.size()+1){
            return sum >= target ? nums.size() : 0;
        }
        
        return minlen;
    }
};