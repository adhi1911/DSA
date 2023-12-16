https://leetcode.com/problems/remove-duplicates-from-sorted-array/description/

//Burte force solution 
//using set 
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        set<int> st;
        for(int i =0;i<n;i++){
            st.insert(nums[i]);
        }

        int index =0;
        for(auto it : st){
            nums[index]=it;
            index++;
        }

        return index;

    }
};



//optimal solution
//using two pointer
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
    int n = nums.size();

    int i =0;
    for(int j=0;j<n;j++){
        if (nums[j]!=nums[i]){
            nums[i+1]=nums[j];
            i++;
        }
    }
    return (i+1) ;

    }
};