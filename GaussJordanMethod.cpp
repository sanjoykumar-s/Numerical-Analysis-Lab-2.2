#include<bits/stdc++.h>
using namespace std;

void GaussElimination() {
    int n;
    cout << "Enter the Number of Variables\n";
    cin >> n;
    double a[n][n+2];
    cout << "Enter the co-efficients\n";
    // Equations like  ax + by + cz = d
    for(int i=0;i<n;i++) {
        for(int j=0;j<n+1;j++) {
            cin >> a[i][j];
        }
    }

    // Elimination step
    for(int i=0;i<n;i++) {
        if(a[i][i]==0) {
            cout << "There is some (may 1) free variable. Therefore this system has no unique solution."
             << "The number of solution is infinity." << endl;
            return;
        }
        for(int j=i+1;j<n;j++) {
            double coef = a[j][i]/a[i][i];
            for(int k=i;k<n+1;k++) {
                a[j][k]-=coef*a[i][k];
            }
        }
    }
    for(int i=0;i<n;i++) {
        int tem = a[i][i];
        for(int j=i;j<n+1;j++) {
            a[i][j]/=tem;
        }
    }
    // Elimination step
    for(int i=n-1;i>=0;i--) {
        if(a[i][i]==0) {
            cout << "There is some (may 1) free variable. Therefore this system has no unique solution."
             << "The number of solution is infinity." << endl;
            return;
        }
        for(int j=i-1;j>=0;j--) {
            double coef = a[j][i]/a[i][i];
            for(int k=i;k<n+1;k++) {
                a[j][k]-=coef*a[i][k];
            }
        }
    }
    //Ans
    for(int i=0;i<n;i++) {
        cout << "x[" << i << "] = " << a[i][n] << endl;
    }
}

int32_t main() {
    GaussElimination();
    return 0;
}