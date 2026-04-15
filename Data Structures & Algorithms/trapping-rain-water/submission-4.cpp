class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int area = 0;
        int l=0, r=n-1;
        int leftMax = height[l], rightMax = height[r];
        // Here we will only operate on the smaller ones
        // If we find smaller one on left we'll check if water can be stored or not then we'll move the left pointer
        // Same on the right pointer, 
        // We only need minimum height and we are operating on minimum height first on both the sides so we are sure that water is gonna stored
        
        while(l < r){
            if(height[l] <= height[r]){
                if(height[l] < leftMax)
                    area += leftMax-height[l];
                else
                    leftMax = height[l];
                l++;
            }
            else{
                if(height[r] < rightMax)
                    area += rightMax-height[r];
                else
                    rightMax = height[r];
                r--;
            }
        }

        return area;
    }
};
