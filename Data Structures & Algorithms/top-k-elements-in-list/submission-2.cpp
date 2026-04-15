class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int,int> mp;
        for(int x : nums) mp[x]++;
        
        vector<pair<int,int>> freq(mp.begin(), mp.end());
        sort(freq.begin(),freq.end(), [](const auto& a, const auto& b){
            return a.second > b.second;
        });

        vector<int> res;
        for(auto itr=freq.begin(); k>0 && itr!= freq.end(); itr++,k--){
            res.push_back(itr->first);
        }
        return res;
    }
};
