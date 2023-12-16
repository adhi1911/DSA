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

//better approach
vector<int> getSecondOrderElements(int n, vector<int> a) {
    int largest = a[0];
    int smallest = a[0];
    
  for(int i =0; i<n;i++){
    if(a[i]>largest){
      largest = a[i];
    }
    if(a[i]<smallest){
      smallest = a[i];
    }
  }

  int sec_largest = numeric_limits<int>::min();
  int sec_smallest = numeric_limits<int>::max();

  for(int i =0; i<n;i++){
    if(a[i]>sec_largest && a[i]!=largest){
      sec_largest = a[i];
    }

    if(a[i]<sec_smallest && a[i]!=smallest){
      sec_smallest = a[i];
    }
  }


    vector<int> result;
    result.push_back(sec_largest);
    result.push_back(sec_smallest);
    return result;
}
