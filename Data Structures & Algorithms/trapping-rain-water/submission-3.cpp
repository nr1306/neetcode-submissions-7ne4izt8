class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();

    // Calculating suffixMax
        vector<int> suffixMax(n);
        suffixMax[n-1] = height[n-1];
        for(int i=n-2; i>=0; i--){
            suffixMax[i] = max(suffixMax[i+1], height[i]);
        }

        int area = 0, leftMax = height[0];
        for(int i=1; i<n; i++){
            leftMax = max(leftMax, height[i]);
            int rightMax = suffixMax[i];
            cout << leftMax << " ";
            if(height[i] < leftMax && height[i] < rightMax){
                cout << height[i] << " " << area << endl;
                area += min(leftMax, rightMax) - height[i];
            }
            // cout << area << " "; 
        }
        return area;
    }
};
