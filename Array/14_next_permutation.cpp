#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Function to find the next permutation of a vector array
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        if(n<=1) return;

        // finding pivot
        int pivot = -1;
        for(int i = n-1;i>0;i--){
            if(nums[i-1]<nums[i]){
                pivot = i-1;
                break;
            }
        }
        
        // if no pivot, reverse the nums
        if(pivot==-1){
            reverse(nums.begin(), nums.end());
            return;
        }
        
        // find swap candidate from the suffix
        for(int i=n-1;i>0;i--){
            if(nums[i]>nums[pivot]){
                swap(nums[i],nums[pivot]);
                break;
            }
        }

        //reverse the suffix
        reverse(nums.begin()+pivot+1,nums.end());

    }


int main() {
    std::vector<int> nums = {1,9,4,6,7}; // Example input vector array

    // Find the next permutation
    nextPermutation(nums);

    // Print the updated vector array
    for (int num : nums) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}