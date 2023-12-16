//https://leetcode.com/problems/missing-number/description/

//Burte force 
#include<algorithm>

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        for(int i =0;i<n+1;i++){
          if(find(nums.begin(),nums.end(),i) == nums.end()){
              return i;
          }  
        }
        return -1;
    }
};

//time complexity: O(n^2)
//space complexity: O(1)

//better solution
#include<algorithm>

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int s1 = n*(n+1)/2;
        int s2 = accumulate(nums.begin(),nums.end(),0);
        return (s1-s2);

    }
};

//time complexity: O(n)
//space complexity: O(1)