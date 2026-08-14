class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int l = 0, r = arr.size()-1;

        while(r-l+1 > k){
            int dist1 = abs(arr[l] - x);
            int dist2 = abs(arr[r] - x);

            if(dist1 <= dist2) r--;
            else l++;
        }
        return vector<int> (arr.begin()+l, arr.begin()+r+1);
    }
};