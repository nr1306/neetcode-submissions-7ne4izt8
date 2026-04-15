class Solution {
public:
    void f(vector<int>& nums, int i, vector<int> temp, set<vector<int>>& s){
        if(i == nums.size()){
            s.insert(temp);
            return;
        }
        // Not including the element
        f(nums,i+1,temp,s);
        temp.push_back(nums[i]);
        // Then invoking the func after adding element
        f(nums,i+1,temp,s);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        set<vector<int>> s;
        vector<int> temp;
        f(nums,0,temp,s);
        vector<vector<int>> res (s.begin(), s.end());
        return res;
    }
};
