//https://www.codingninjas.com/studio/problems/sorted-array_6613259?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf&leftPanelTabValue=PROBLEM


//brute force
/*
#include<set>

vector<int> sortedArray(vector<int> a, vector<int> b) {
    set<int> st;
    int n = a.size();
    int m = b.size();
    for(int i=0; i<n; i++){
        st.insert(a[i]);
    }
    for(int i =0;i<m;i++){ 
        st.insert(b[i]);
    }
    vector<int> result; 
    set<int>::iterator it;
    for (it = st.begin(); it != st.end(); ++it) {
        result.push_back(*it);
    }

    return result;
}

*/

//using two pointers
//provided that both arrays are sorted
vector<int> sortedArray(vector<int> a, vector<int> b) {
    int n = a.size();
    int m = b.size();
    int i=0,j=0;
    vector<int> result;
    while(i<n && j<m){
        if(a[i]<b[j]){
            result.push_back(a[i]);
            i++;
        }
        else{
            result.push_back(b[j]);
            j++;
        }
    }
    while(i<n){
        result.push_back(a[i]);
        i++;
    }
    while(j<m){
        result.push_back(b[j]);
        j++;
    }
    return result;
}