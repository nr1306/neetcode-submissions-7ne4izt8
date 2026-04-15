class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // Remember Bucket sort is most optimized for Top K frequent elements
    // We are gonna calculate the frequency like we did before
    // Then we are using indexes representing the freq of elements
    // And we'll store elements in 2D array according to their frequency
    // There can be multiple elements of same freq that's why 2D array
    // Then we can just start iterating from the back of that array and insert elements into res array until its size == k

        map<int,int> freq;
        for(int x : nums) freq[x]++;

// nums.size()+1 because there could be an element of freq nums.size()
        vector<vector<int>> bucket(nums.size()+1);
        for(auto it : freq){
    // using freq as an index and storing the element
            bucket[it.second].push_back(it.first);
        }

        vector<int> res;
        for(int i=nums.size(); i>=0; i--){
            for(int x : bucket[i]){
                res.push_back(x);
                if(res.size() == k)
                    break;
            }
            if(res.size() == k) break;
        }
        return res;
    }
};
