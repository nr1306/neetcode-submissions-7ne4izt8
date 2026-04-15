class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        
        set<vector<int>> res;
        int n = nums.size();
        sort(nums.begin(), nums.end());

        for(int i=0; i<n; i++){
            for(int j=n-1; j>i; j--){
                int target = 0-nums[i]-nums[j];
                int start=i, end=j;
                if(target > nums[end] || target < nums[start]) continue;
                while(start < end){
                    int mid = (start+end)/2;
                    if(nums[mid] < target)
                        start = mid+1;
                    else if(nums[mid] > target)
                        end = mid;
                    else{
                        if(i!=mid && mid!=j){
                            vector<int> triplet = {nums[i],nums[mid],nums[j]};
                            res.insert(triplet);
                        }
                        break;
                    }
                } 
            }
        }
        vector<vector<int>> ans (res.begin(), res.end());
        return ans;
    }
};
