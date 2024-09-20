#include <iostream>
using namespace std;

void cuentaregresiva(int start);

int main()
{
    cuentaregresiva(15);
    return 0;
}

void cuentaregresiva(int start)
{
    if (start == 0)
    {
        return;
    }
    cout << "\n" << start;
    cuentaregresiva(start - 1);
}