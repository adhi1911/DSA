void insertionSort(int arr[], int n)
{   int i , j , k;
    for(i =0;i<n;i++){
        for(j=k=i;j<n;j++){
            if(arr[j]<arr[k]){
                k=j;
            }
        }
    int temp = arr[i];
    arr[i]=arr[k];
    arr[k]=temp;

    }
}