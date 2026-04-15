class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), m = nums2.size();
        if(!n){
            if(m%2 != 0){
                int targetInd = (m+1)/2;
                return nums2[targetInd-1];
            }
            else{
                int targetInd = m/2;
                double median = ((double)nums2[targetInd-1] + nums2[targetInd])/2.0;
                return median;
            }
        }

        if(!m){
            if(n%2 != 0){
                int targetInd = (n+1)/2;
                return nums1[targetInd-1];
            }
            else{
                int targetInd = n/2;
                double median = ((double)nums1[targetInd-1] + nums1[targetInd])/2.0;
                return median;
            }
        }

        int size = n+m;
        double res=-1.0;
        if(size%2 != 0){
            int targetIndex = (size+1)/2;
            int k=0,i=0,j=0,curr=-1;
            while(k<targetIndex && i<n && j<m){
                if(nums1[i] < nums2[j]){
                    curr = nums1[i];
                    i++;
                }
                else{
                    curr = nums2[j];
                    j++;
                }
                k++;
            }
            res = curr;
        }
        else{
            int targetIndex = size/2+1;
            int k=0,i=0,j=0,prev=-1,curr=-1;
            while(k<targetIndex && i<n && j<m){
                prev = curr;
                if(nums1[i] < nums2[j]){
                    curr = nums1[i];
                    i++;
                }
                else{
                    curr = nums2[j];
                    j++;
                }
                k++;
            }
            while(k<targetIndex && i<n){
                prev = curr;
                curr = nums1[i];
                i++;
                k++;
            }
            while(k<targetIndex && j<m){
                prev = curr;
                curr = nums2[j];
                j++;
                k++;
            }
            if(prev!=-1)
                res = ((double)prev+curr)/2.0;
        }
        return res;
    }
};
