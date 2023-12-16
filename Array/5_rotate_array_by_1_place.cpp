#include <iostream>
#include <vector>
using namespace std;

// Given an array of size N, rotate it by 1 place in the left direction.

/*
vector<int> rotateArray(vector<int>& arr, int n) {
    vector<int> temp(n);
    
    for(int i=0;i<n;i++){
        temp[i]=arr[(i+1)%n];
    }

    return temp;
}

*/

//opitmisied solution
void rotateArray(vector<int>& arr, int n) {
    int temp=arr[0];
    for(int i=0;i<n-1;i++){
        arr[i]=arr[i+1];
    }
    arr[n-1]=temp;
}

int main() {
    // Test the rotateArray function
    vector<int> arr = {1, 2, 3, 4, 5};
    int n = arr.size();
    
    rotateArray(arr, n);
    
    cout << "Rotated Array: ";
    for(int i=0; i<n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    
    return 0;
}
