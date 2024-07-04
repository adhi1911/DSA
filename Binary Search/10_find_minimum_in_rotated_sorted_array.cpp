// https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/
class Solution {
public:
    int findMin(vector<int>& arr) {
        int n =arr.size();
        int low=0 , high=n-1;
        while(low<high){
            int mid = low+(high-low)/2;
            if(arr[mid]>arr[high]){
                low = mid+1;
            }
            else{
                high = mid;
            }
        }
        return arr[low] ;
    }
};