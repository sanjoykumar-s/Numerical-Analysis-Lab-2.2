#include<bits/stdc++.h>
using namespace std;

double f(double x) {
    return 1/(1+x);
}

void integrationUsingTrapezoidal() {
    cout << "Enter lower Bound:\n";
    double a;
    cin >> a;
    double b;
    cout << "Enter upper bound :\n";
    cin >> b;
    int n;
    cout << "Enter number of interval:\n";
    cin >> n;
    double h = (b-a)/n;
    vector<double>v;
    double res = 0;
    v.push_back(f(a));
    res+=v[0];
    double tem = a;
    while(tem+h<b) {
        tem+=h;
        res+=2*f(tem);
    } 
    res+=f(b);
    res*=h/2.0;
    cout << "Integrated value = " << res << endl;

}

int32_t main() {
    integrationUsingTrapezoidal();
    return 0;
}