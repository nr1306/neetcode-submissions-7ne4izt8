class Solution {
public:
    void f(set<vector<int>>& s, vector<int>& nums, int i, vector<int> temp){
        if(i == nums.size()){
            sort(temp.begin(),temp.end());
            s.insert(temp);
            return;
        }

        f(s,nums,i+1,temp);
        temp.push_back(nums[i]);
        f(s,nums,i+1,temp);
        temp.pop_back();
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        set<vector<int>> s;
        vector<int> temp;
        f(s,nums,0,temp);
        
        vector<vector<int>> res (s.begin(), s.end());
        return res;
    }
};
