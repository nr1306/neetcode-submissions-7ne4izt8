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
            if(nums[i] < nums[s] && nums[i] < nums[f])
                return i;
            i++;
        }
        return -1;
    }

    int search(vector<int>& nums, int target) {
        int n = nums.size();
        if(n == 1){
            if(target == nums[0])
                return 0;
            else
                return -1;
        }
        if(n == 2){
            if(target == nums[0])
                return 0;
            else if(target == nums[1]){
                return 1;
            }
            else
                return -1;
        }
        int minIndex = findMin(nums);

        int rotateFigure = nums.size()-minIndex;
        rotate(nums.begin(),nums.begin()+minIndex, nums.end());

        int start = 0, end = n-1;
        while(start <= end){
            int mid = (start+end)/2;
            if(nums[mid] == target){
                return mod(mid-rotateFigure,n);
            }
            else if(target > nums[mid])
                start = mid+1;
            else
                end = mid-1;
        }
        return -1;
    }
};
