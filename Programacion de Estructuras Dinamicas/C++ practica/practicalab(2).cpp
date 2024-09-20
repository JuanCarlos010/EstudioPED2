#include <iostream>
using namespace std;

void passByValue(int, int);
void passByRef(int *, int *);

int main()
{
    int a = 500;
    int b = 1300;
    cout << "original " << endl;
    cout << "a: " << a << endl;
    cout << "b: " << b << endl;

    passByValue(a, b);

    cout << "Por valor " << endl;
    cout << "a: " << endl;
    cout << "b: " << endl;

    passByRef(&a, &b);

    cout << "Por referencia " << endl;
    cout << "a: " << endl;
    cout << "b: " << endl;

    return 0;
}

void passByValue(int x, int y)
{
    x = 5;
    y = 10;
}

void passByRef(int *x, int *y)
{
    *x = 5;
    *y = 10;
}