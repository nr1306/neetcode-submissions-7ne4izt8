class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size(), n2 = nums2.size();
        int n = n1+n2;
        int ind = 0;
        if(n%2 == 0) ind = n/2;
        else ind = (n+1)/2;
        
        int i=0, j=0,k=0;
        int ele1 = 0;
        while(i<n1 && j<n2){
            int mini = min(nums1[i], nums2[j]);
            ele1 = mini;
            if(nums1[i] <= nums2[j]) i++;
            else j++;

            k++;

            if(k == ind) break; 
        }

        while(i<n1 && k<ind){
            ele1 = nums1[i];
            k++;
            i++;

            if(k == ind) break;
        }

        while(j<n2 && k<ind){
            ele1 = nums2[j];
            k++;
            j++;

            if(k == ind) break;
        }

        if(n%2 != 0) return (double)ele1;

        int ele2 = 0;
        if(i<nums1.size() && j<nums2.size()){
            ele2 = min(nums1[i], nums2[j]);
        }
        else if(i<nums1.size()){
            ele2 = nums1[i];
        }
        else ele2 = nums2[j];

        return (ele1 + ele2)/2.0;
    }
};
