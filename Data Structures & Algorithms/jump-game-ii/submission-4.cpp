class Solution {
public:
    int jump(vector<int>& nums) {
        int coverage = 0, lastJumpIndex = 0;
        int jumpCnt = 0;
        int n = nums.size();

        if(n == 1) return 0;

        for(int i=0; i<n; i++){
        // determining the max window we can jump
            coverage = max(coverage , i+nums[i]);

            // There is no need for cond where we are stuck , coz there will always a valid ans
            // Will always reach at the end

            if(i == lastJumpIndex){
                lastJumpIndex = coverage;
                jumpCnt++;

// If the following condn is out of this if condn then , 
// it will return jumpcnt before we update our last jump, 
// coz until we reach the last index jumpcnt wont get updated
                if(coverage >= n-1) return jumpCnt;
                
            }

        }
    }
};
