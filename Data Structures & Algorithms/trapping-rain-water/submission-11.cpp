class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        // If we are at the point where there is bar on left with more height and there is a bar in right with more height
        // Only in that case - we can trap the rainwater

        // Lets store all the leftMax for each point
        vector<int> left(n);
        left[0] = height[0];

        for(int i=1; i<n; i++){
            left[i] = max(height[i] , left[i-1]);
        }
        // Lets store all the rightMax for each point
        vector<int> right(n);
        right[n-1] = height[n-1];

        for(int i=n-2; i>=0; i--){
            right[i] = max(height[i], right[i+1]);
        }

        int area = 0;
        for(int i=1; i<n-1; i++){
            if(height[i] < left[i] && height[i] < right[i]){
                // width of bar = 1
                area += (min(left[i], right[i])-height[i] )* 1; 
            }
        }

        return area;
    }
};
