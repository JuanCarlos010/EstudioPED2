#include <iostream>
using namespace std;
int b;
int h;
void Area(int &areaT,int &areaR);

int main(){
    int areaT, areaR;
    int n;
    cout << "ingrese el valor de base: ";
    cin >> b;
    cout << "Ingrese el valor de la altura: ";
    cin >> h;
    Area(areaT, areaR);
    cout << "Desea ver el area del triangulo 1 = si" << endl;
    cin >> n;
    if (n == 1)
    {
        cout << areaT;
    }else
    {
        cout << areaR;
    }
    
    
    return 0;
}

void Area(int &areaT, int &areaR){
    areaT = (b * h)/2;
    areaR = b * h;
}