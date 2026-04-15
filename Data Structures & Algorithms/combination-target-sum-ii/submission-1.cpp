class Solution {
public:
    void f(vector<int>& candidates, int target, set<vector<int>>& res, vector<int> temp, int i){
        if(!target){
            sort(temp.begin(),temp.end());
            res.insert(temp);
        }
        if(i == candidates.size()) return;
        f(candidates,target,res,temp,i+1);
        if(target >= candidates[i]){
            temp.push_back(candidates[i]);
            f(candidates,target-candidates[i],res,temp,i+1);
            temp.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        set<vector<int>> s;
        vector<int> temp;
        f(candidates,target,s,temp,0);
        vector<vector<int>> res (s.begin(),s.end());
        return res;
    }
};
