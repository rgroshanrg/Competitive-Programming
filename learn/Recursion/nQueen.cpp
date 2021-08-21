#include<bits/stdc++.h>

using namespace std;


bool isValid(vector<vector<int> > mat, int x, int y) {
    int n = mat[0].size();
    for(int i = 0; i < n; ++i) {
        if(mat[i][y])
            return false;
    }
    for(int i = 0; i < n; ++i) {
        if(mat[x][i])
            return false;
    }
    int i = x, j = y;
    while(i >= 0 && j >= 0) {
        if(mat[i][j])
            return false;
        i--; j--;
    }
    i = x, j = y;
    while(i >= 0 && j < n) {
        if(mat[i][j])
            return false;
        i--;
        j++;
    }
    return true;
}

void solve(vector<vector<int> > &matrix, int i, int j, vector<vector<int> > &ans, int &cnt) {
    int n = matrix[0].size();
    if(cnt == n) {
        vector<int> temp;
            for(int id = 0; id < n; ++id) {
                for(int jd = 0; jd < n; ++jd) {
                    temp.push_back(matrix[id][jd]);
                }
            }
            ans.push_back(temp);
        return;
    }
    if(i == n)
        return;
    for(;j<n;j++){
    	if(isValid(matrix, i, j)) {
            matrix[i][j] = 1;
            cnt++;
            solve(matrix, i+1, 0, ans, cnt);
            matrix[i][j] = 0; cnt--;
        }    	    
    }    
}

void tp(vector<vector<int>> matrix, vector<vector<int>> &ans, int i) {
    int cnt = 1;
    matrix[0][i] = 1;
	
    solve(matrix, 1, 0, ans, cnt);
}

vector<vector<int>> nQueens(int n)
{
	// Write your code here
    vector<vector<int>> ans;
    vector<vector<int>> matrix(n, vector<int>(n, 0));
    
    for(int i = 0; i < n; ++i) {
        tp(matrix, ans, i);
    }
    
    return ans;
	
}
int main() {
    int n = 4;
    vector<vector<int>> ans = nQueens(n);
    if(ans.size() > 0) {
        cout << ans.size() << "\n";
        for(int i = 0; i < ans.size(); ++i) {
            for(int j = 0; j < ans[0].size(); ++j) {
                cout << ans[i][j] << " "; 
            }
            cout << "\n";
        }
    } else {
        cout << "0";
    }
    return 0;
}

