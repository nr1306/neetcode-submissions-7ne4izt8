class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        if(arr.size() == k) return arr;
        
        int l = 0, r = arr.size()-1;
        while(r-l >= k){
            if(abs(arr[l]-x) <= abs(arr[r]-x)) r--; // coz if abs value is same then we'll take the lower value interger into our res array
            else l++;
        }
        
        vector<int> res(arr.begin()+l, arr.begin()+r+1);
        return res;
    }
};