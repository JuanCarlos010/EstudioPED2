#include <iostream>
using namespace std;

int suma (int n);
int factorial(int n);
int fibonacci(int n);
int mcd(int n, int m);
int mcm(int n, int m);

int main(){
    //cout << suma(5) << endl;
    //cout << factorial(2) << endl;
    //cout << fibonacci(7) << endl;
    //cout << mcd(150, 39) << endl;
    cout << mcm(4, 39) << endl;
    return 0;
}

int factorial(int n){
    if (n == 1)
    {
        return 1;
    }
    return n * factorial(n - 1);
}

int suma(int n){
    if (n == 0){
        return 0;
    }
    return n + suma(n - 1);
}

int fibonacci(int n){
    if (n < 2){
        return n;
    }
    return fibonacci(n - 1) + fibonacci(n - 2);
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