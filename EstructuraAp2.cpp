#include <iostream>
using namespace std;

struct Dato1{
    int dat1;
    string dat2;
};

struct Dato2{
    struct Dato1 datoe;
    int dat3;
};

int main(){
    struct Dato2 dato;
    struct Dato2 *Ptr;
    Ptr = &dato;
    cout << "Ingrese dato: ";
    cin >> Ptr->datoe.dat1;
    cout << endl;
    cout << "Dato ingresado: " << Ptr->datoe.dat1;
cout << endl;
    cout << "Ingrese dato: ";
    cin >> Ptr->datoe.dat2;
    cout << endl;
    cout << "Dato ingresado: " << Ptr->datoe.dat2;



return 0;
}
