#include <bits/stdc++.h>
using namespace std;

int main() {
    int
    long m, n, r;
    cin >> m >> n >> r; 
    vector<vector<int>> matrix(m);
    for(long i = 0; i < m; i++) {
        matrix[i] = vector<int>(n);
        for(long j = 0; j < n; j++) {
            cin >> matrix[i][j];
        }
    }

    vector<long> f(n*m , 0);
    long c = 0;
    long rings = min(m,n) / 2;
    for(long i = 0; i < rings; i++) {
        for(long j = i; j < n - i; j++) {
            f[c++] = matrix[i][j];
        }
        for(long j = i+1; j < m - i ; j++) {
            f[c++] = matrix[j][n-i-1];
        }
        for(long j = n-i-2; j >= i; j--) {
            f[c++] = matrix[m-i-1][j];
        }
        for(long j = m-i-2; j > i; j--) {
            f[c++] = matrix[j][i];
        }
    }
    //cout << c << endl;
    
    // for(long i : f) {
    //     cout << i << " ";
    // }
    // cout << endl;

    vector<long> ans(n*m, 0);

    for(long i = 0; ;) {
        long st = m*n - (m-2)*(n-2);
        for(long j=0; j < st; j++) {
            //cout << i+j << " " << i+(j+r)%st << endl ;
            ans[i+j] = f[i+(j+r)%st];
            // swap(f[i+j], f[i+(j+r)%st]);
        }
        if(m == 0 || n ==0) { 
            break;
        }
        i += m*n - (m-2)*(n-2);
        m -= 2; n -= 2;
    }
    
    //for(long i : ans) {
        //cout << i << '\n';
    //}
    //for(int i = 0; i < ans.size(); i++) {
        //if(ans[i] == 0) {
            //cout << i ;
        //}
    //}
    //cout << '\n';
     
    c = 0, m = matrix.size(), n = matrix[0].size();
    
    for(long i = 0; i < rings; i++) {
        for(long j = i; j < n - i; j++) {
            matrix[i][j] = ans[c++];
        }
        for(long j = i+1; j < m - i ; j++) {
            matrix[j][n-i-1] = ans[c++];
        }
        for(long j = n-i-2; j >= i; j--) {
            matrix[m-i-1][j] = ans[c++];
        }
        for(long j = m-i-2; j > i; j--) {
            matrix[j][i] = ans[c++];
        }
    }
    //cout << c << endl;
    
    c = 0;
    for(long i = 0; i < m; i++) {
        for(long j = 0; j < n; j++) {
            //if(matrix[i][j] == 0) 
                //cout << i << " " << j << endl;
            cout << matrix[i][j] << " ";
            c++;
        }
        cout << '\n';
    }
    //cout << c << endl;
    
    return 0;
}
