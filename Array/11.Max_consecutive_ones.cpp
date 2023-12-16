
//https://leetcode.com/problems/max-consecutive-ones/

//brute force

#include <bits/stdc++.h>

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
      int cnt = 0;
      int max_cnt = 0;
      for(int i =0;i<nums.size();i++){
          if(nums[i] ==1) cnt++;
          else cnt =0;  

          max_cnt = max(cnt,max_cnt);
      }  
      return max_cnt;
    }
};

//Time Complexity: O(n)
//Space Complexity: O(1)



