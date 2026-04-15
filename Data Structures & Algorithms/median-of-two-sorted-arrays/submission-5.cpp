class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int size = nums1.size()+nums2.size();
        int ind = 0;
        int res = 0;

        if(size%2 != 0){
            ind = ((size+1)/2);
        }
        else{
            ind = (size/2);
        }

        int i=0, j=0, k=0; 
        while(i<nums1.size() && j<nums2.size()){
            int mini = min(nums1[i],nums2[j]);
            res = mini;
            if(nums1[i]<= nums2[j]) i++;
            else j++;
            k++;

            if(k == ind){
                break;
            }
        }

        while(k<ind && i<nums1.size()){
            res = nums1[i];
            i++;
            k++;
            if(k == ind){
                break;
            }
        }
        while(k<ind && j<nums2.size()){
            res = nums2[j];
            j++;
            k++;
            if(k == ind){
                break;
            } 
        }
        if(size%2 != 0) return res;
        
        int res1 = 0;
        if(i<nums1.size() && j<nums2.size()) res1 = min(nums1[i], nums2[j]);
        else if(i<nums1.size()) res1 = nums1[i];
        else res1 = nums2[j];

        return ((double)res + res1)/2.0;
    }
};
