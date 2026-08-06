class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        
        nums1.resize(m);

        int i = 0, j = 0;
        int n2 = nums2.size();

        if(nums1.size() == 0){
            nums1 = nums2;
            return;
        }

        while(j < n2 && nums2[j] < nums1[i]){
            nums1.insert(nums1.begin(), nums2[j]);
            j++;
        }

        while(i<nums1.size() && j < n2){
            if(nums1[i] <= nums2[j]){
                i++;
            }
            else{
                nums1.insert(nums1.begin()+i, nums2[j]);
                i++;
                j++;
            }
        }

        if(j < n2)
            nums1.insert(nums1.end(), nums2.begin()+j, nums2.end());
        
    }
};