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


//Optimal approach
int secondlargest(vector<int> &a , int n){
  int largest = a[0];
  int s_largest = -1;
  for(int i =1;i<n;i++){
    if (a[i]>largest){
      s_largest = largest;
      largest = a[i];
    } else if (a[i] < largest && a[i] > s_largest) {
      s_largest = a[i];
    }
  }
  return s_largest;
}
int secondsmallest(vector<int> &a, int n){
  int smallest = a[0];
  int s_smallest = INT_MAX;
  for(int i =1;i<n;i++){
    if(a[i]<smallest){
      s_smallest = smallest;
      smallest = a[i];
    }
    else if (a[i]>smallest && a[i] < s_smallest){
      s_smallest = a[i];
    }
  }
  return s_smallest;
}


vector<int> getSecondOrderElements(int n, vector<int> a) {
    int sec_largest = secondlargest(a,n);
    int sec_smallest = secondsmallest(a,n);

    return {sec_largest , sec_smallest};
}
