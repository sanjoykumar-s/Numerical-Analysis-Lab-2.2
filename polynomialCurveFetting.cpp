#include<bits/stdc++.h>
using namespace std;
#define double long double

double a[20][20];
double res[20];

void GaussElimination(int n) {
    cout << "Enter the co-efficients\n";
    // Equations like  ax + by + cz = d;

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

void FeettheCurve() {
    int n;
    cout << "Enter the number of Data: \n";
    cin >> n;
    double x[n],y[n];
    double Tx[n];
    double sumY=0;
    for(int i=0;i<n;i++) {
        cin >>x[i] >> y[i];
        Tx[i]=x[i];
        sumY += y[i];
    }
    cout << "Enter the degree of Polynomial:\n";
    int deg;
    cin >> deg;
    int dd = deg;
    deg*=2;
    double Px[deg+1]={0.0},XY[deg+1]={0.0};
    for(int i=0;i<deg;i++) {
        for(int j=0;j<n;j++) {
            Px[i+1]+=Tx[j];
            XY[i+1]+=Tx[j]*y[j];
            Tx[j]*=x[j];
        }
    }
    XY[0]=sumY;
    Px[0]=n;
    for(int j=0;j<n;j++) {
        for(int i=0;i<n;i++) {
            a[i][j]=Px[i+j];
        }
    }
    for(int i=0;i<n;i++) {
        a[i][n]=XY[i];
    }
    GaussElimination(n);
    cout << "So, the required polynomial is: \n";
    cout << res[0] << " + ";
    for(int i=1;i<dd;i++) {
        cout << res[i] << "x^(" << i << ") + ";
    }
    cout << res[dd] << "x^(" << dd << ")" << endl;
}


int32_t main() {
    FeettheCurve();
    return 0;
}