#include <bits/stdc++.h>
using namespace std;

int partition(vector<int> &arr, int low, int high) {
    int i = low-1;
    int j = low;
    while(j < high) {
        if(arr[j] < arr[high]) {
            i++;
            swap(arr[i], arr[j]);
        }
        j++;
    }
    swap(arr[i+1], arr[high]);
    return i+1;
}

void quickSort(vector<int> &arr, int low, int high) {
    if(low >= high)
        return;
    int pos = partition(arr, low, high);
    quickSort(arr, low, pos-1);
    quickSort(arr, pos+1, high);
}

int main() {

    vector<int> arr = { 2, 1, 5, 0, 6, 4, 8, -3, 0, 7, 2, 0, 54 };

    quickSort(arr, 0, arr.size()-1);
    
    for(int i = 0; i < arr.size(); ++i) {
        cout << arr[i] << " ";
    }
    cout << "\n";

    return 0;
}

