 = (l+r) >> 1;
    vector<int> ans;
    for(int i = l, j = mid+1; i <= mid || j <= r; ++i, ++j) {
        if(i <= mid && j <= r) {
            ans.push_back(min(arr[i], arr[j]));
        } else if(i <= mid) {
            ans.push_back(arr[i]);
        } else {
            ans.push_back(arr[j]);
        }
    }
    for(int i = 0; i < ans.size(); ++i) {
        arr[i+l] = ans[i];
    }