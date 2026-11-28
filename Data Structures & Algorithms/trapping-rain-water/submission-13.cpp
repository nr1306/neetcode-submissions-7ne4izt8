class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int l = 0, r = n-1;
        int leftMax = height[l], rightMax = height[r];
        int total = 0;

        while(l <= r){
// this much rain water will get trapped - if we are the instance where it is smaller than the right wall and smaller than leftMax - it means here rain water will get trapped
            if(height[l] < height[r]){
                if(height[l] > leftMax) leftMax = height[l];
                else total += leftMax - height[l]; 

                l++;
            }
            else{
                if(height[r] > rightMax) rightMax = height[r];
                else total += rightMax - height[r];

                r--;
            }
        }

        return total;
    }
};
