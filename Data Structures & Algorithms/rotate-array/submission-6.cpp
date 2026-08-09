class Solution {
public:
    void swap(int& a, int& b){
        int temp = a;
        a = b;
        b = temp;
    }

    void rotateArray(vector<int>& nums, int i, int j){
        while(i<j){
            swap(nums[i] , nums[j]);
            i++;
            j--;
        }
    }

    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k %= n;
        rotateArray(nums, 0, n-1);
        rotateArray(nums, 0, k-1);
        rotateArray(nums,k,n-1);
    }
};