//find second largest and second smallest element in an array

//brute force approach
vector<int> getSecondOrderElements(int n, vector<int> a) {
    sort(a.begin(),a.end());
    int largest = a[n-1];
    int smallest = a[0];
    int sec_largest;
    int sec_smallest;
    for(int i =n-2;i>=0;i--){
        if(a[i]!=largest){
            sec_largest = a[i];
            break;
        }
    }

    for (int j = 1; j < n; j++) {
        if (a[j]!=smallest){
            sec_smallest=a[j];
            break;
        }
    }

    vector<int> result;
    result.push_back(sec_largest);
    result.push_back(sec_smallest);
    return result;
}

//efficient approach