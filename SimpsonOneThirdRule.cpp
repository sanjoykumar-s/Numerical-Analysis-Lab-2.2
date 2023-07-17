#include<bits/stdc++.h>
using namespace std;

double f(double x) {
    return 1/(1+x);
}

void integrationUsingSimpsonOneThird() {
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
    double res = 0;
    res+=f(a);
    double tem = a;
    int index = 1;
    while(tem+h<b) {
        tem+=h;
        if(index&1)res+=4*f(tem);
        else res+=2*f(tem);
        index++;
    } 
    res+=f(b);
    res*=h/3.0;
    cout << "Integrated value = " << res << endl;

}

int32_t main() {
    integrationUsingSimpsonOneThird();
    return 0;
}