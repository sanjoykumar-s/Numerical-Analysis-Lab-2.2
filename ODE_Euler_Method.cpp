#include<bits/stdc++.h>
using namespace std;

double f(double x,double y) {
    return -y;
}

void ODE_Euler_Method() {
    double x0,y0,xn,h;
    cout << "Enter x0 :\n";
    cin >> x0;
    cout << "Enter y0 :\n";
    cin >> y0;
    cout << "Enter value of h :\n";
    cin >> h;
    int n;
    cout << "Enter the number of steps\n";
    cin >> n;
    double res;
    double temX = x0;
    double temY = y0;
    for(int i=1;i<=n;i++) {
        double yi = temY + h*f(temX,temY);
        cout << "Step " << i << " Y["  << i << "] = " << yi << endl;
        temX = x0+h;
        temY = yi; 
    }
    cout << "Y[n] = " << temY << endl;

}

int32_t main() {
    ODE_Euler_Method();
    return 0;
}