//https://leetcode.com/problems/move-zeroes/description/

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        int i =0;
        for(int j =0;j<n;j++){
            if (nums[j] != 0){
                nums[i] = nums [j];
                i++;
            }           
        }
        for(int j = i; j<n;j++){
            nums[j]=0;
        }

    }
};