
int firstOcc(vector<int>& arr, int n , int key){
    int s =0;
    int e = n-1;
    int ans =-1;
    int mid = s + (e-s)/2;

    while(s<=e){
        if ( arr[mid]==key ){
            ans = mid;
                e=mid-1;
        }

        else if (key > arr[mid])
        { //right mdhe jayla
                s=mid+1; 
        }

        else if (key < arr[mid]){
            //left mdhe jayla
                e=mid-1;
        }

        mid= s + (e-s)/2;

    }
    return ans;
}

int lastOcc(vector<int>& arr, int n , int key){
    int s =0;
    int e = n-1;
    int ans =-1;
    int mid = s + (e-s)/2;

    while(s<=e){
        if ( arr[mid]==key ){
            ans = mid;
                s=mid+1;
        }

        else if (key > arr[mid])
        { //right mdhe jayla
                s=mid+1; 
        }

        else if (key < arr[mid]){
            //left mdhe jayla
                e=mid-1;
        }

        mid= s + (e-s)/2;

    }
    return ans;
}
int count(vector<int>& arr, int n, int x) {
	
	int first = firstOcc(arr,n,x);
	int last = lastOcc(arr,n,x);
	if(first ==-1) return 0;
	else return (last-first)+1;
}
