#include <iostream>
using namespace std;

struct Dato0{
    int dat0;
    string datS;

};
struct Dato1{
    struct Dato0 dat1,dat2;
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
    cin >> Ptr->datoe.dat1.dat0;
    cout << endl;
    cout << "Dato ingresado: " << Ptr->datoe.dat1.dat0;
cout << endl;
    cout << "Ingrese dato: ";
    cin >> Ptr->datoe.dat2.datS;
    cout << endl;
    cout << "Dato ingresado: " << Ptr->datoe.dat2.datS;



return 0;
}
