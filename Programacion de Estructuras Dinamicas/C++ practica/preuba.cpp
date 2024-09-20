#include <iostream>
using namespace std;
void compania(int opcion ,int paquete)
{
    switch (opcion,paquete)
    {
    case 1:
        cout << "Haz elegido Digicel." << endl;
        cout << "Te ofrecemos los siguientes paquetes de datos :)" << endl;
        cout << "1. 500 MG + 50 Min a todas las redes por $1.00.<<endl; \n2. 4GB + 60 Min a todas las redes + Whatssap gratis por 5 dias por $2.50. \n3. 8GB a todas las redes + Whatssap ilimitado por 7 dias por $3.00. \n4. Paquetes chivito." << endl;
        if (paquete == 1)
        {
            /* code */
        }
        
        break;
    case 2:
        cout << "Haz elegido Movistar." << endl;
        break;
    case 3:
        cout << "Haz elegido Tigo." << endl;
        break;
    case 4:
        cout << "Haz elegido Claro." << endl;
        break;
    case 5:
        break;

    default:
        cout << "Opcion no valida." << endl;
        break;
    }
}

int main()
{
    int opcion, paquete;
    cout << "Compra tus paquetes en linea :) " << endl;
    cout << "Selecciona la compania : " << endl;
    cout << "1.Digicel. \n2.Movistar. \n3.Tigo. \n4.Claro. \n5.Salir." << endl;
    cin >> opcion;
    cin >> paquete;
    compania(opcion,paquete);
    return 0;
}