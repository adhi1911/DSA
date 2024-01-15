int findceil(vector<int> arr, int n, int x) {
	//lowerbound >=x
	int low = 0, high = n-1;
	int ans = -1;
	while(low<=high){
		int mid = low + (high - low)/2;
		if (arr[mid]>=x){
			ans = arr[mid];
			high = mid-1;
		}
		else low = mid+1;
	}
	return ans;

}

int findfloor(vector<int> &arr, int n, int x){
	//<=x
	int low = 0, high = n-1;
	int ans = -1;
	while(low<=high){
		int mid = low + (high - low)/2;
		if (arr[mid]<=x){
			ans = arr[mid];
			low = mid+1;
			
		}
		else high = mid-1;
	}
	return ans;
}

pair<int, int> getFloorAndCeil(vector<int> &a, int n, int x) {
    int floor = findfloor(a, n, x);
    int ceil = findceil(a, n, x);


    return {floor, ceil};
}