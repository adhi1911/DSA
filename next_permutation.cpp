#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Function to find the next permutation of a vector array
void nextPermutation(std::vector<int>& nums) {
    //start from right
    int i = nums.size() - 2;
    //find first sorted pair and point at the smallest one 
    for(i=nums.size()-2; i>=0; i--){
        if(nums[i] < nums[i+1]){
            break;
        }
    }
    cout<<i<<endl;
    //now i points to that smaller element in pair
    //if i is not found, then the array is sorted in descending order
    //so we reverse the array
    if(i<0){
        reverse(nums.begin(), nums.end());
    }
    else{
        int j;
        //find the element just greater than nums[i] from right
        for(j=nums.size()-1; j>=0; j--){
            if(nums[j] > nums[i]){
                break;
            }
        }
        cout<<j<<endl;
        cout<<nums[i]<<endl;
        cout<<nums[j]<<endl;
        //now j points to that element
        //swap nums[i] and nums[j]
        swap(nums[i], nums[j]);
        //reverse the array from i+1 to end
        reverse(nums.begin()+i+1, nums.end());
    }
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
