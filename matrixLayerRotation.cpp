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

    vector<int> f(n*m , 0);
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

    for(long i = 0; ;) {
        long st = m*n - (m-2)*(n-2);
        vector<int> temp(r%st);
        long tj, j;
        for(tj = 0; tj < r%st; tj++) {
            temp[tj] = f[i+tj];
            // cout << temp[tj] << " ";
        }
        // cout << endl;
        tj = 0;
        j = 0;
        while(j < st-r%st) {
            f[i+j] = f[i+(j+r)%st];
            j++;
        }
        while(j < st) {
            f[i+j] = temp[tj++];
            j++;
        }
        if(!min(m,n)) { 
            break;
        }
        i += m*n - (m-2)*(n-2);
        m -= 2; n -= 2;
    }
     
    c = 0, m = matrix.size(), n = matrix[0].size();
    
    for(long i = 0; i < rings; i++) {
        for(long j = i; j < n - i; j++) {
            matrix[i][j] = f[c++];
        }
        for(long j = i+1; j < m - i ; j++) {
            matrix[j][n-i-1] = f[c++];
        }
        for(long j = n-i-2; j >= i; j--) {
            matrix[m-i-1][j] = f[c++];
        }
        for(long j = m-i-2; j > i; j--) {
            matrix[j][i] = f[c++];
        }
    }
    
    c = 0;
    for(long i = 0; i < m; i++) {
        for(long j = 0; j < n; j++) {
            cout << matrix[i][j] << " ";
            c++;
        }
        cout << '\n';
    }

    return 0;
}

