class Solution {
public:
    void swap(int& a, int& b){
        int temp = a;
        a = b;
        b = temp;
    }
    void reverse(vector<int>& nums, int i, int j){
        while(i<j){
            swap(nums[i],nums[j]);
            i++;
            j--;
        }
    }

    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k %= n;
    // I took the last k elements and then inserted at the beginning of nums array
    // and then resize the array to its original size
        reverse(nums, 0, n-1);
        reverse(nums,0,k-1);
        reverse(nums,k,n-1);
    }
};