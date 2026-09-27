class Solution {
public:

// in this problem assume we have k buckets - now to have all of their sum to be equal it must be equal to target
// Will fill the elements in bucket unless its sum is less than target

    bool solve(vector<int>& nums, vector<int>& sum, int ind, int target){
        int n = nums.size();
        int k = sum.size();

        if(ind == n){
            int sum1 = sum[0];
// checking all the sums of buckets are equal or not
            for(int i=1; i<k; i++){
                if(sum[i] != sum1) return false;
            }
            cout << endl;
            return true;
        }

// ind is index iterating in nums array and here i will iterate within k buckets

        for(int i=0; i<k; i++){
            if(sum[i] + nums[ind] <= target){
                sum[i] += nums[ind];
                if(solve(nums,sum,ind+1,target)) return true;
                sum[i] -= nums[ind];
            }
        }
        return false;
    }

    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int total = 0;
        for(int x : nums) total += x;

        if(total % k != 0) return false;

        sort(nums.begin(), nums.end(), greater<int>());
        
        vector<int> sum(k,0);
        return solve(nums, sum, 0, total/k);
    }
};