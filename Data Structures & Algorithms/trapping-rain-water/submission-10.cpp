class Solution {
public:
    int trap(vector<int>& height) {
        // Intuition is will check the height on left and right
        // Water is stored whenever there is a higher wall beside it
        // and height of water stored is equal to shorter height either on left or right
        int n = height.size();
        vector<int> leftMax(n) , rightMax(n);

        leftMax[0] = height[0];

        for(int i=1; i<n; i++){
            leftMax[i] = max(height[i] , leftMax[i-1]);
        }

        rightMax[n-1] = height[n-1];

        for(int i=n-2; i>=0; i--){
            rightMax[i] = max(height[i] , rightMax[i+1]);
        }   
        
        int water = 0;
        for(int i=1; i<n; i++){
            water += min(leftMax[i], rightMax[i]) - height[i];
        }

        return water;
    }
};
