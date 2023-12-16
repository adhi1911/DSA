//Reversal algorithm

//rotate right by k places
//reverse first k elements
//reverse the remaining elements
//reverse the whole array

//rotate left by k places
//reverse the whole array
//reverse the first n-k elements
//reverse the remaining elements


    void reverse(vector<int>&arr , int start , int end){
        while(start<=end){
            int temp = arr[start];
            arr[start]=arr[end];
            arr[end]=temp;
            start++;
            end--;
        }
    }

    void rotate_right(vector<int> & arr , int n , int k){

        k%=n;
        //reversing first k elements
        reverse(arr , 0 , n-k-1);
        //reversing last n-k elements
        reverse(arr,n-k,n-1);
        //reversing whole array
        reverse(arr,0,n-1);
    }

    void rotate_left(vector<int> & arr , int n , int k){
    k%=n;
    
    //reversing first k elements
    reverse(arr , 0,k-1);
    //reversing last n-k elements
    reverse(arr, k, n-1);
    //reversing whole array
    reverse(arr, 0, n-1);
    }
