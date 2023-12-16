https://www.codingninjas.com/studio/problems/left-rotate-an-array-by-one_5026278?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf&leftPanelTabValue=SUBMISSION

// Given an array of size N, rotate it by 1 place in the left direction.
vector<int> rotateArray(vector<int>& arr, int n) {
    vector<int> temp(n);
    
    for(int i=0;i<n;i++){
        temp[i]=arr[(i+1)%n];
    }

    return temp;
}

//time complexity: O(n)
//space complexity: O(n)

//opitmisied solution
void rotateArray(vector<int>& arr, int n) {
    int temp=arr[0];
    for(int i=0;i<n-1;i++){
        arr[i]=arr[i+1];
    }
    arr[n-1]=temp;
}

//time complexity: O(n)
//space complexity: O(1)
