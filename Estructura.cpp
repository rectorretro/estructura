#include <iostream>
#include <conio.h>
#include <stdlib.h>

using namespace std;
struct direccion{
    char calle[20];
    int cp;
    char ciudad[20];

};//podemos coloarlos aqui arriba;
struct persona{
    char nombre [20];
    int edad ;
    float estatura ;
    struct direccion dire;
};

int main(){
    /*
    char salir;
    do{
    struct persona P1;
    cout << "Nombre: ";
    cin.getline(P1.nombre,20, '\n');
    cout << endl;
    cout << "Edad: ";
    cin >> P1.edad;
    cout << endl;
    cout << "Estatura: ";
    cin >> P1.estatura;
    cout << endl;
    //Variables dentro de otra estructura
    cout << "Calle: ";
    //fflush(stdin);
    cin.getline (P1.dire.calle,20,'\n');
    cin.getline (P1.dire.calle,20,'\n');
    cout << endl;
    cout << "Codigo Postal: ";
    cin >> P1.dire.cp;
    cout << endl;
    cout << "Ciudad: ";
    cin.getline(P1.dire.ciudad,20, '\n' );
    cin.getline(P1.dire.ciudad,20, '\n' );

    cout << "Nombre guardado: " <<P1.nombre << endl;

    cout << "Edad guardad: " <<P1.edad << endl;

    cout << "Estarua guardada: " <<P1.estatura << endl;
cout << endl;

    cout << "Ciudad guardada: " <<P1.dire.calle << endl;

    cout << "Codigo guardado: " <<P1.dire.cp << endl;

    cout << "Ciudad guardada: " <<P1.dire.ciudad << endl;
    getch();
        cout << "Salir (N/Y): ";
        cin >> salir;
        system("cls");
    }while (salir=='N'||salir=='Y');
*/
    struct persona P2[5];
    for (int i; i<=5; i++){
    cout << "Nombre: ";
    cin.getline(P2[i].nombre,20, '\n');
    cin.getline(P2[i].nombre,20, '\n');
    cout << endl;
    cout << "Edad: ";
    cin >> P2[i].edad;
    cout << endl;
    cout << "Estatura: ";
    cin >> P2[i].estatura;
    cout << endl;
    //Variables dentro de otra estructura
    cout << "Calle: ";
    //fflush(stdin);
    cin.getline (P2[i].dire.calle,20,'\n');
    cin.getline (P2[i].dire.calle,20,'\n');
    cout << endl;
    cout << "Codigo Postal: ";
    cin >> P2[i].dire.cp;
    cout << endl;
    cout << "Ciudad: ";
    cin.getline(P2[i].dire.ciudad,20, '\n' );
    cin.getline(P2[i].dire.ciudad,20, '\n' );
    }
    return 0;
}
