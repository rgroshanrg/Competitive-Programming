#include <bits/stdc++.h>
using namespace std;

void merge(vector<int> &arr, int l, int r) {
    int mid = (l+r) >> 1;
    vector<int> ans;
    for(int i = l, j = mid+1; i <= mid || j <= r;) {
        if(i <= mid && j <= r) {
            ans.push_back(min(arr[i], arr[j]));
            if(arr[i] <= arr[j]) i++; else j++;
        } else if(i <= mid) {
            ans.push_back(arr[i]); i++;
        } else {
            ans.push_back(arr[j]); j++;
        }
    }
    for(int i = 0; i < ans.size(); ++i) {
        arr[i+l] = ans[i];
    }
}

void mergeSort(vector<int> &arr, int l, int r) {
    if(l == r)
        return;
    mergeSort(arr, l, ((l+r)>>1));
    mergeSort(arr, ((l+r)>>1)+1, r);
    merge(arr, l, r);
}

int main() {

    vector<int> arr = { 2, 1, 5, 0, 6, 4, 8, -3, 0, 7, 2, 0, 54 };

    mergeSort(arr, 0, arr.size()-1);
    
    for(int i = 0; i < arr.size(); ++i) {
        cout << arr[i] << " ";
    }
    cout << "\n";

    return 0;
}