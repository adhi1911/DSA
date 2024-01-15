class Solution {
public:
    int searchInsert(vector<int>& nums, int key) {
        int n = nums.size();
        int low = 0;
        int high = n-1;
        int ans=n;
        while(low<=high){
            int mid = low + (high-low)/2;
            if (nums[mid]>=key){ 
                high = mid-1;
                ans = mid;
            }
            else low = mid+1;
        }
        return ans;
    }
};