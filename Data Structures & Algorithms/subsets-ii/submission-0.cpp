class Solution {
public:
    void f(set<vector<int>>& s, vector<int>& nums, int i, vector<int> temp,
    map<vector<int>,int>& freq){
        if(i == nums.size()){
            vector<int> dummy (temp.begin(),temp.end());
            sort(temp.begin(),temp.end());
            if(!freq[temp]){
                s.insert(dummy);
                freq[temp] = 1;
            }
            return;
        }

        f(s,nums,i+1,temp,freq);
        temp.push_back(nums[i]);
        f(s,nums,i+1,temp,freq);
        temp.pop_back();
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        set<vector<int>> s;
        vector<int> temp;
        map<vector<int>,int> freq;
        f(s,nums,0,temp,freq);
        
        vector<vector<int>> res (s.begin(), s.end());
        return res;
    }
};
