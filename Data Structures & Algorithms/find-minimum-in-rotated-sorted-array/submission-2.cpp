class Solution {
public:
    int mod(int a, int b) {
        int result = a % b;
        return result < 0 ? result + std::abs(b) : result;
    }

    int findMin(vector<int> &nums) {
        if(nums.size() == 1)
            return nums[0];
        if(nums.size() == 2){
            return min(nums[0],nums[1]);
        }
        int i=0,n=nums.size();
        while(i<n){
            int f = mod(i+1,n);
            int s = mod(i-1,n);
            cout << (-1)%n;
            if(nums[i] < nums[s] && nums[i] < nums[f])
                return nums[i];
            i++;
        }
        return -1;
    }
};
