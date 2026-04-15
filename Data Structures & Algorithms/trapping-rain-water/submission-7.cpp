class Solution {
public:
    int trap(vector<int>& height) {
        int l = 0, r = height.size()-1;
        // we can maintain the array of leftmax and rightmax but its not space optimized
        // we'll just keep moving and calculating the leftmax and rightmax

        int leftmax = height[l];
        int rightmax = height[r];
        
        int area = 0;
        while(l<r){
            // wea are operating on smaller one so we'll compare left and right heights and then we'll compare it with prefix and suffix max
            if(height[l] <= height[r]){
                if(height[l] < leftmax){
                    area += leftmax-height[l];
                }
                else leftmax = height[l];
                
                l++;
            }
            else{
                if(height[r] < rightmax){
                    area += rightmax - height[r];
                }
                else rightmax = height[r];
                r--;
            }
        }

        return area;
    }
};
