class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k %= n;
        vector<int> temp (nums.begin()+n-k, nums.end());
        nums.insert(nums.begin(),temp.begin(), temp.end());
        nums.resize(n);
    }
};