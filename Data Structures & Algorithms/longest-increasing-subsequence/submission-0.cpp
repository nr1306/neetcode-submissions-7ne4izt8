class Solution {
public:
    int f(vector<int>& nums, int start, int prev){
        if(start == nums.size()-1){
            if(nums[start] > prev) return 1;
            return 0;
        }

        int count1 = INT_MIN;
        if(nums[start] > prev){
            count1 = 1 + f(nums,start+1,nums[start]);
        }
        int count2 = 0 + f(nums,start+1,prev);

        return max(count1,count2);
    }

    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        int maxi = 1;
        for(int i=0; i<n; i++){
            if(n-i <= maxi) break;
            maxi = max(maxi, f(nums,i+1,nums[i])+1 );
        }
        return maxi;
    }
};
