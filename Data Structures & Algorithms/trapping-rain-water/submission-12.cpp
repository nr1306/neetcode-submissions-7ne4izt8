class Solution {
public:
    int trap(vector<int>& height) {
        int area = 0;
        int l = 0, r = height.size()-1;
        int leftMax = height[l];
        int rightMax = height[r];

        while(l < r){
// We are gonna process lower height first
// Idea is to process the lower height first is At a point we need greater height bars on both directions to trap the water

// EXAMPLE: If left height is smaller - then we know for sure that there is more height bar on the right - so our only task left is to compare with leftMax bar - if we have a bigger bar on left then we can calculate the area of water trapped if not - will update leftMax
// Similar if the right height is smaller than leftHeight - thats why we kept 2 pointers to decide which bar to process first

            if(height[l] < height[r]){
                if(height[l] < leftMax) area += leftMax - height[l];
                else leftMax = height[l];
                
                l++;
            }
            else{
                if(height[r] < rightMax) area += rightMax - height[r];
                else rightMax = height[r];

                r--;
            }
        }

        return area;
    }
};
