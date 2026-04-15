/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
// Intuition is that from peak both left and right portion of arrays are sorted , first finding peak element and then applying binary search to both the portions of the array
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int start = 1, end = mountainArr.length()-2;
        int peak = -1;
        
    // Finding the peak element in the array
    // Now peak element will never be at start and end position, then it will be comes normal sorted array
    // Coz array will always be a mountain array 

        while(start <= end){
            int mid = start + (end-start)/2;
            int midEle = mountainArr.get(mid);
            int nextEle = mountainArr.get(mid+1);
            int prevEle = mountainArr.get(mid-1);

            if(midEle >= nextEle && midEle >= prevEle){
                peak = mid;
                break;
            }
            else if(midEle >= prevEle){ // Its on the increasing side of array
                start = mid+1;
            }
            else end = mid-1;
        }

        cout << peak;
        // applying BS on left side
        start = 0;
        end = peak-1;
        int res = -1;
        while(start <= end){
            int mid = (start+end)/2;
            int midEle = mountainArr.get(mid);

            if(midEle == target){
                res = mid;
                end = mid-1;
            }
            else if(midEle < target)
                start = mid+1;
            else end = mid-1;
        }
        if(res!=-1) return res;

    // checking right portion wherre elements are sorted in decreasing order
        start = peak;
        end = mountainArr.length()-1;
        while(start <= end){
            int mid = (start+end)/2;
            int midEle = mountainArr.get(mid);

            if(midEle == target){
                res = mid;
                end = mid-1;
            }
            else if(midEle < target)
                end = mid-1;
            else start = mid+1;
        }

        return res;
    }
};