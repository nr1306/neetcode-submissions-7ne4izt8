class Solution {
public:

    int jump(vector<int>& nums) {
        int destination = nums.size()-1; 
        int coverage = 0, lastJumpIndex = 0;
        int jumpCount = 0;

        if(nums.size() == 1) return 0;

        for(int i=0; i<nums.size(); i++){
            coverage = max(coverage, i+nums[i]);

// When the current window is fully explored then the below cond will be true
            if(i == lastJumpIndex){
                lastJumpIndex = coverage;
                jumpCount++;
            
// Below condition is inside if condition, it means, we won't return
// jumpcount before exploring all elements in window, coz it might be local maxima
                if(coverage >= destination) return jumpCount;
            }

        }

    }
};
