class Solution {
public:
    void solve(vector<vector<int>>& res, int start, int n, int k,           vector<int>& temp){
       
        if(temp.size() == k){
            res.push_back(temp);
            return;
        }
             
        for(int i=start; i<=n; i++){
            temp.push_back(i);
            solve(res,i+1,n,k,temp);
            temp.pop_back();
        }
    }

    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        vector<int> temp;
        solve(res,1,n,k,temp);
        return res;
    }
};