class Solution {
public:
    int findMin(vector<int> &nums) {
        int l = 0 ,r = nums.size()-1;

        while(l < r){
            int mid = (r-l)/2 + l;
            if(nums[mid] < nums[r]) r = mid; // This condition is put first if the array is already sorted It will satisfy both if and else conditions, we'll decrease the range first as our ans will lie at first pos
            else l = mid+1; // left part is sorted
        }
        // as we need this condition to satisfy for mid to be our answer
        // nums[mid] > nums[l] && nums[mid] < nums[r] 
        // thats why if nums[mid] < nums[r] its a valid condition, we can't ignore the possibility of mid to be an answer here
        // if nums[mid] >= nums[l] , here mid is definitely not our answer and it will not satisfy our above req condition
        return nums[l];
    }
};
