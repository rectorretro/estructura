#include <iostream>
using namespace std;

struct Dato{
    int dato1;
    char dato2[20];
};


int main(){
struct Dato var1;
struct Dato *Ptr;
 //var1.dato1=1;
 Ptr=&var1;

    //var1.dato1 = 12;
  cout << "Puntero: " << Ptr << endl;
  cout << "Direccion de Ptr: " << &Ptr << endl;
  //cout << "Dato1: " << var1.dato1 << endl;
  cout << "Var1: " << &var1 << endl;
  cout << "Ingresar por puntero: ";
  cin >> Ptr->dato1;
  cout << endl;
  cout << "Valor ingresado: " <<Ptr->dato1 << endl;
  cout << "Ingresar por puntero: ";
  cin >> Ptr->dato2;
  cout << endl;
  cout <<  "Cadena ingresada: " <<Ptr->dato2;



return 0;
}
