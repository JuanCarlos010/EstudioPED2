#include <iostream>
using namespace std;

int main()
{
    int op;
    cout << "Ingrese la opcion 1) para abrir documentos; 2) para abrir capturas" << endl;
    cin >> op;
    if (op == 1)
    {
        system("Start C:\\Users\\lucky\\OneDrive\\Documents");
    }
    else if (op == 2)
    {
        system("Start C:\\Users\\lucky\\Videos\\Captures");
    }

    return 0;
}