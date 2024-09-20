#include <iostream>
using namespace std;

void array();
int num;

int main()
{
    //(ejemplo)
    /*int a = 15;
    int b = 60;
    int *ptr;
    int *ptr2;
    ptr = &a;
    ptr2 = nullptr;
    ptr2 = ptr;
    *ptr = 20;
    cout << *ptr << "||" << ptr << "||" << ptr2 << endl;*/
    //(1)
    /*int n = 33;
    int &r = n;
    cout << "&n ="<< &n << ",&r = " << &r << endl;*/
    //(2)
    /*int n = 35;
    int *p = &n;
    int &r = *p;
    cout << "r=" << r << endl;  */
    //(3)
    /*int n = 35;
    int *p = &n;
    cout << "*P = " << *p << endl;*/
    //(prueba)
    /*if (&ptr == &ptr2)
    {
        cout << "Son iguales";
    }else{
        cout << "no son iguales";
    }*/
    //(arreglo)
    /*int vector[5] = {4, 5, 8, 1, 9};
    int *ptr = vector;
    cout << vector << endl;
    cout << *(vector + 1) << endl;
    cout << *(vector + 4) << endl;
    for (int i = 0; i < 5; i++)
    {
        cout << *(vector + i) << "||" << ptr++ << endl;
    }*/

    cout << "Ingrese un numero del 1 - 10 " << endl;
    cin>>num;
    array();
    return 0;
}

void array()
{
    int i;
    int valor[5] = {2, 3, 5, 1, 6};
    if (num == valor[5])
    {
        cout << "puso un numero valido";
    }else{
        cout << "Puso un numero invalido";
    }
}