#include <iostream>
using namespace std;

int mcd(int n, int m);
int mcm(int n, int m);

int main(){
    cout << mcm(4,67) << endl;
    cout << mcd(4,19) << endl;
    return 0;
}

int mcd (int n, int m){
    if (m == 0){
        return n;
    }
    return mcd(m, n % m);
}

int mcm(int n, int m){
    if ((n == 0) || (m == 0)){
        return 0;
    }
    return (n * m) / mcd(n,m);
}