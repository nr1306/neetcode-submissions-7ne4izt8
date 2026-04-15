class Solution {
public:
    int trap(vector<int>& height) {
        int l = 0, r = height.size()-1;
        int area = 0;
        int leftMax = height[l];
        int rightMax = height[r];
        while(l<r){
            if(height[l] <= height[r]){
                if(height[l] < leftMax){
                    area += leftMax - height[l];
                }
                else{
                    leftMax = height[l];
                }
                l++;
            }
            else{
                if(height[r] < rightMax){
                    area += rightMax - height[r];
                }
                else{
                    rightMax = height[r];
                }
                r--;
            }
        }
        return area;
    }
};
