class Solution {
public:
    void merge(vector<int>& nums1, int n, vector<int>& nums2, int m) {
        nums1.resize(n);
        int i=0, j=0;

        while(i<nums1.size() && j<nums2.size()){
            if(nums1[i] <= nums2[j]) i++;
            else
                nums1.insert(nums1.begin()+i, nums2[j++]);
        }
        
        while(j<nums2.size()){
            nums1.push_back(nums2[j]);
            j++;
        }

    }
};