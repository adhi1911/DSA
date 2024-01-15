class Solution {
public:
    int firstocc(vector<int>& a, int x){
        int n = a.size();
        int low =0,high = n-1;
        int ans = -1;
        while(low<=high){
            int mid = low+(high-low)/2;

            if(a[mid]==x){
                ans = mid;
                high = mid-1;
            }
            else if (a[mid]>x) high = mid -1;
            else low = mid+1;
        }
        return ans;
    }

int lastocc(vector<int>& a, int x){
        int n = a.size();
        int low =0,high = n-1;
        int ans = -1;
        while(low<=high){
            int mid = low+(high-low)/2;

            if(a[mid]==x){
                ans = mid;
                low = mid+1;
            }
            else if (a[mid]>x) high = mid -1;
            else low = mid+1;
        }
        return ans;
    }
vector<int> searchRange(vector<int>& nums, int target) {
    int first = firstocc(nums,target);
    int last = lastocc(nums,target);
    vector<int> ans = {first,last};
    return ans;
    }
};