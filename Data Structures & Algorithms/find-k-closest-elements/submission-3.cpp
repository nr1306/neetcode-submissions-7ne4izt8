class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        vector<int> res;
        int n = arr.size();
        int l = 0, r = n-k;
        
        while(l < r){
            int mid = (r-l)/2 + l;
            int dist1 = abs(arr[mid] - x);
            int dist2 = abs(arr[mid+k] - x);

            if(dist1 > dist2) l = mid+1;
            else r = mid;
        }
        return vector<int> (arr.begin()+l , arr.begin()+l+k);
    }
};