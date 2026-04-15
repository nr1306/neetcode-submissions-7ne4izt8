class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int, int> freq;
        for(int x : nums){
            freq[x]++;
        }
        map<int,vector<int>> revFreq;
        for(auto it : freq){
            revFreq[it.second].push_back(it.first);
        }
        freq.clear();
        vector<int> res;
        for(auto itr=revFreq.rbegin(); itr!=revFreq.rend() && k>0; itr++){
            vector<int> temp = itr->second;
            if(temp.size() > k){
                res.insert(res.end(), temp.begin(),temp.begin()+k);
                k-=k;
            }
            else{
                res.insert(res.end(), temp.begin(),temp.end());
                k-=temp.size();
            }
        }
        return res;
    }
};
