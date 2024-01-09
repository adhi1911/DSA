#include<bits/stdc++.h>
using namespace std;

//using linear search
// int lowerBound(vector<int> arr, int n, int x) {
// 	for(int i =0;i<n;i++){
// 		if(arr[i]>=x){
// 			return i;
// 			break;
// 		}
// 	}
// 	return n;
// }
//time complexity O(n)
//space complexity O(1)

//using binary search
int lowerBound(vector<int> arr, int n, int x) {
	int low = 0;
	int high = n-1;
	int ans=n;
	while(low<=high){
		int mid = low + (high-low)/2;
                if (arr[mid] >= x) {
                  high = mid - 1;
                  ans = mid;
                } else
                  low = mid + 1;
        }
        return ans;
}
//time complexity O(logn)
//space complexity O(1)