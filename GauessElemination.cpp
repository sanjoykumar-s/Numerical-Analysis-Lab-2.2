#include<bits/stdc++.h>
using namespace std;

void GaussElimination() {
    int n;
    cout << "Enter the Number of Variables\n";
    cin >> n;
    double a[n][n+2];
    cout << "Enter the co-efficients\n";
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

    //Back Substitution
    if(a[n-1][n]==0) {
        cout << "Invalid Linear system.\n";
        return;
    }
    double res[n+1];
    res[n-1]=a[n-1][n]/a[n-1][n-1];
    for(int i=n-2;i>=0;i--) {
        double sum = a[i][n];
        for(int j=i+1;j<n;j++) {
            sum -= a[i][j]*res[j];
        }
        res[i] = sum/a[i][i];
    }
    // Ans
    for(int i=0;i<n;i++) {
        cout << "x[" << i << "] = " << res[i] << endl;
    }
}

int32_t main() {
    GaussElimination();
    return 0;
}