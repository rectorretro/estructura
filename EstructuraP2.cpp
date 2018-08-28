#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <iomanip>
#include <fstream>
using namespace std;
///CONSTANTES UTILIZADAS EN TODO EL PROYECTO
const int NUM = 20;
const int SAL = 1;
struct Saldo
{
    int saldo;

};
Saldo compras[SAL];
struct Almacen
{
    int Clave;
    int cantidad;
    double Precio;
};
struct COMPRADAS
{
    string NombreProducto;
    string Distribuidor;
    string Tipo;
    string Contenido;
    struct Almacen almacen;
};

COMPRADAS listaCompradas[NUM];

struct Productos
{
    string NombreProducto;
    string Distribuidor;
    string Tipo;
    string Contenido;
    struct Almacen almacen;
};

Productos listaProductos[NUM];

string reemplazarEspacios(string);
string reemplazarSharp(string);
void insertar(int, string,string,string,string,int,double);
void mostrarDatos();
void escribirEnArchivo();
void recuperarDeArchivo();
void pedirDatos();
void inicializar();
int buscarLugarVacio();
void menu();
void menu2();
void ordenacionBurbujaPorPrecio();
void ordenacionBurbujaPorNombre();
int busquedaSecuencial(int);
int busquedaBinaria(int);
void mostrarRegistro(int);



void restarCantidad(int);

void menuAdmin(int);
void menuComprador(int);



///Funciones para el saldo
void escribirEnArchivoS();
void abonarSaldo();
void restarsaldo(int);
void obtenersaldo();
void insertarS(int);
void inicializarS();
void recuperarDeArchivoS();
void ordenacionBurbujaPorClave();

///Funciones del comprador
void escribirEnArchivoComp();
void recuperarDeArchivoComp();

void inicializarComp();
void DatosCompradas(int);
void insertarC(int, string,string,string,string,int,double);
int buscarLugarVacioComp();
void mostrarDatosC();

void borrar(int);
int main()
{
    char*locale;
    locale=setlocale(LC_ALL,"");
    int opcion, resultado, caso;
    string contrasena,tipo;
    do
    {
        caso=0;
        cout << "Administador (Admin) o Comprador (Cons); (Salir): ";
        getline(cin, tipo);
        system("cls");
        if (tipo == "Salir")
        {
            return 0;
        }
        if (tipo == "Admin")
        {
            caso = 1;
        }
        if (tipo == "Cons")
        {
            caso = 2;
        }
        switch(caso)
        {
        case 1:
                menu();
            break;
        case 2:
                menu2();
            break;

        }


    }
    while (opcion != 3);
    system("cls");

    return 0;
}

void menuAdmin(int caso)
{
    inicializar();
    recuperarDeArchivo();
    int resultado,buscar;
    //menu();
    switch (caso)
    {
    case 1:
        mostrarDatos();
        pedirDatos();
        ordenacionBurbujaPorClave();
        escribirEnArchivo();
        system("pause");
        system("cls");
        break;
    case 2:
        mostrarDatos();
    default:
        cout << "Opcion no valida" << endl;
        system("pause");
        system("cls");

        break;
    }

}

void menuComprador(int caso)
{
    inicializar();
    recuperarDeArchivo();
    inicializarS();
    inicializarComp();
    recuperarDeArchivoComp();
    escribirEnArchivoComp();
    recuperarDeArchivoS();
    int resultado = 0,buscar,compra;
    switch(caso)
    {
    case 1:
        mostrarDatos();
        cout << "Tu saldo es: ";
        obtenersaldo();
        cout << endl;
        cout << "Introdusca la clave del producto: " ;
        cin >> compra;
        restarsaldo(compra);
        ordenacionBurbujaPorClave();
        resultado = busquedaBinaria(compra);
        if (resultado == -1)
        {
            cout << "No encontrado" << endl;
        }
        //escribirEnArchivo();

        DatosCompradas(resultado);
        escribirEnArchivoComp();
        restarCantidad(compra);
        cout << endl;
        cout << "Saldo actual: ";
        obtenersaldo();
        cout << endl;
        system("pause");
        system("cls");
        break;
    case 2:
        cout << "SALDO ACTUAL: ";
        obtenersaldo();
        cout << endl;
        abonarSaldo();
        escribirEnArchivoS();
        obtenersaldo();
        cout << endl;
        system("pause");
        system("cls");
        break;
    case 3:
        mostrarDatosC();
        break;
    default:
        break;
    }
}
void menu()
{
    int caso = 0;
    do
    {
        cout << "E L I G E   T U  O P C I O N" << endl;
        cout << "1.-Agregar producto" << endl;
        cout << "2.-Ver productos" << endl;
        cout << "3.- Salir "<< endl;
        cout << "opción: ";
        cin >> caso;
        system("cls");
        //system("pause");
        menuAdmin(caso);
    }
    while (caso != 3);
}
void menu2()
{
    int caso = 0;
    do
    {
        cout << "ELIGE UNA OPCIÓN" << endl;
        cout << "1.-Comprar producto" << endl;
        cout << "2.-Abonar saldo" << endl;
        cout << "3.-Productos comprados" << endl;
        cout << "4.- Salir" << endl;
        cout << "opción: ";
        cin >> caso;
        system("cls");
        menuComprador(caso);
    }
    while (caso != 5);
}

void restarCantidad(int a)
{


    for(int i = 0; i< NUM-1; i++)
    {
        int Clavex = listaProductos[i].almacen.Clave;
    string NombreProductox = listaProductos[i].NombreProducto;
    string Distribuidorx =listaProductos[i].Distribuidor;
    string Tipox = listaProductos[i].Tipo;
    string Contenidox = listaProductos[i].Contenido;
    int cantidadx = listaProductos[i].almacen.cantidad;
    double Preciox = listaProductos[i].almacen.Precio;

        if(listaProductos[i].almacen.Clave == a )
        {
                if(cantidadx == 0) {
            cout << "Ya no hay producto" << endl;
    return;

    }
            borrar(i);

            cantidadx = cantidadx - 1;
            insertar(Clavex,NombreProductox,Distribuidorx,Tipox,Contenidox,cantidadx,Preciox);
            escribirEnArchivo();
            return;
        }
    }

}
/// Funciones del usuario
void DatosCompradas(int i)
{
    int Clavex = listaProductos[i].almacen.Clave;
    string NombreProductox = listaProductos[i].NombreProducto;
    string Distribuidorx =listaProductos[i].Distribuidor;
    string Tipox = listaProductos[i].Tipo;
    string Contenidox = listaProductos[i].Contenido;
    double cantidadx = listaProductos[i].almacen.cantidad;
    double Preciox = listaProductos[i].almacen.Precio;

    insertarC(Clavex,NombreProductox,Distribuidorx,Tipox,Contenidox,cantidadx,Preciox);
}


void insertarC(int Clavex,string NombreProductox,string Distribuidorx,string Tipox,string Contenidox,int cantidadx, double Preciox)
{
    int lugarVacio = buscarLugarVacioComp();
    if (lugarVacio == -1)
    {
        cout << "Ya no hay lugar" << endl;
        return;
    }
    listaCompradas[lugarVacio].almacen.Clave = Clavex;
    listaCompradas[lugarVacio].NombreProducto= NombreProductox;
    listaCompradas[lugarVacio].Distribuidor= Distribuidorx;
    listaCompradas[lugarVacio].Tipo= Tipox;
    listaCompradas[lugarVacio].Contenido = Contenidox;
    listaCompradas[lugarVacio].almacen.cantidad= cantidadx;
    listaCompradas[lugarVacio].almacen.Precio = Preciox;
}

void mostrarDatosC()
{
    cout << "PRODUCTOS COMPRADOS"<< endl;
     cout << endl;
    cout << setw(6) << "Clave"
         << setw(30) << "Nombre del producto"
         << setw(25) << "Distribuidor"
         << setw(15) << "Contenido"
         << setw(14) << "Tipo"
         //<< setw(15) << "Cantidad"
         << setw(15) << "Precio" << endl;
    for(int i=0; i< NUM; i++)
    {
        if (listaCompradas[i].almacen.Clave !=0)
        {
            cout << setw(6) << listaCompradas[i].almacen.Clave
                 << setw(28) << listaCompradas[i].NombreProducto
                 << setw(25) << listaCompradas[i].Distribuidor
                 << setw(14) << listaCompradas[i].Contenido
                 << setw(14)  << listaCompradas[i].Tipo
                 //<< setw(14)  << listaCompradas[i].cantidad
                 << setw(15) << listaCompradas[i].almacen.Precio  << "$"<< endl;
        }
    }
}

void escribirEnArchivoComp()
{
    ofstream salidaArchivo("productosComp.txt", ios::out);
    if (!salidaArchivo)
    {
        cerr << "No se pudo abrir el archivo";
        exit(1);
    }
    for(int i=0; i<NUM; i++)
    {
        if (listaCompradas[i].almacen.Clave != 0)
        {
            salidaArchivo << listaCompradas[i].almacen.Clave << ' '
                          << reemplazarEspacios(listaCompradas[i].NombreProducto) << ' '
                          << reemplazarEspacios(listaCompradas[i].Distribuidor) << ' '
                          << reemplazarEspacios(listaCompradas[i].Contenido) << ' '
                          << reemplazarEspacios(listaCompradas[i].Tipo) << ' '
                          << listaCompradas[i].almacen.cantidad << ' '
                          << listaCompradas[i].almacen.Precio << ' ' << endl;

        }
    }
}

void recuperarDeArchivoComp()
{
    ifstream lecturaArchivo("productosComp.txt", ios::in);
    if (!lecturaArchivo)
    {
        cerr << "No se pudo abrir el archivo" << endl;
        exit(1);
    }
     int Clavex;
    string NombreProductox;
    string Distribuidorx ;
    string Tipox ;
    string Contenidox;
    int cantidadx;
    double Preciox;
    while(lecturaArchivo >> Clavex >> NombreProductox >> Distribuidorx >> Tipox >> Contenidox >> cantidadx >>Preciox)
    {
        insertarC(Clavex, reemplazarSharp(NombreProductox), reemplazarSharp(Distribuidorx), reemplazarSharp(Tipox),reemplazarSharp(Contenidox), cantidadx,Preciox);
    }

}

void inicializarComp()
{
    for (int i=0; i<NUM; i++)
    {
    listaCompradas[i].almacen.Clave = 0;
    listaCompradas[i].NombreProducto= "";
    listaCompradas[i].Distribuidor= "";
    listaCompradas[i].Tipo= "";
    listaCompradas[i].Contenido = "";
    listaCompradas[i].almacen.cantidad= 0;
    listaCompradas[i].almacen.Precio = 0;
    }
}

void inicializar()
{
    for (int i=0; i<NUM; i++)
    {
    listaProductos[i].almacen.Clave = 0;
    listaProductos[i].NombreProducto= "";
    listaProductos[i].Distribuidor= "";
    listaProductos[i].Tipo= "";
    listaProductos[i].Contenido = "";
    listaProductos[i].almacen.cantidad= 0;
    listaProductos[i].almacen.Precio = 0;
    }
}

void borrar(int i){
listaProductos[i].almacen.Clave = 0;
    listaProductos[i].NombreProducto= "";
    listaProductos[i].Distribuidor= "";
    listaProductos[i].Tipo= "";
    listaProductos[i].Contenido = "";
    listaProductos[i].almacen.cantidad= 0;
    listaProductos[i].almacen.Precio = 0;


}
int buscarLugarVacioComp()
{
    for (int i=0; i<NUM; i++)
    {
        if (listaCompradas[i].almacen.Clave==0)
        {
            return i;
        }
    }
    return -1;
}


///Funciones del Administrador


void pedirDatos()
{
    int Clavex;
    string NombreProductox;
    string Distribuidorx;
    string Tipox;
    string Contenidox;
    int cantidadx;
    double Preciox;
    cout << "Escribe datos de los prodcutos " << endl;
    cout << "Dame clave: ";
    cin >> Clavex;
      fflush(stdin);
    int arreglo[20];
    for(int i = 0; i< NUM-1; i++)
    {
        arreglo[i]=listaProductos[i].almacen.Clave;
    }

    for(int i = 0; i< NUM-1; i++)
    {
        if(arreglo[i] == Clavex || arreglo[i] == Clavex )
        {
            cout << endl;
            cout << "Se repitio la clave: " << arreglo[i] << " que pertenece al producto: " << listaProductos[i].NombreProducto << endl;
            cout << "Reingresar clave del nuevo producto"<< endl;
            cout << "Nueva clave: ";
            Clavex = 0;
            cin >> Clavex;
        }
    }

    cout << "Dame nombre del producto: ";
    getline(cin, NombreProductox);
    fflush(stdin);
    cout << "Dame distribuidor: ";
    getline(cin, Distribuidorx);
    fflush(stdin);
    cout << "Dame tipo: ";
    getline(cin, Tipox);
    fflush(stdin);
    cout << "Dame Contenido: ";
    getline(cin, Contenidox);
    fflush(stdin);
    cout << "Dame cantidad en almacen: ";
    cin >> cantidadx;

    cout << "Dame el precio: ";
    cin >> Preciox;
    insertar(Clavex,NombreProductox,Distribuidorx,Tipox,Contenidox,cantidadx,Preciox);
}



string reemplazarEspacios(string texto)
{
    for (int i=0; i<(int)texto.length(); ++i)
    {
        if (texto[i] == ' ')
        {
            texto.replace(i,1,"#");
        }

    }
    return texto;
}

string reemplazarSharp(string texto)
{
    for (int i = 0; i < (int) texto.length(); ++i)
    {
        if (texto[i] == '#')
        {
            texto.replace(i, 1, " ");
        }
    }
    return texto;
}


void insertar(int Clavex,string NombreProductox,string Distribuidorx,string Tipox,string Contenidox,int cantidadx, double Preciox)
{
    int lugarVacio = buscarLugarVacio();
    if (lugarVacio == -1)
    {
        cout << "Ya no hay lugar" << endl;
        return;
    }
    listaProductos[lugarVacio].almacen.Clave = Clavex;
    listaProductos[lugarVacio].NombreProducto= NombreProductox;
    listaProductos[lugarVacio].Distribuidor= Distribuidorx;
    listaProductos[lugarVacio].Tipo= Tipox;
    listaProductos[lugarVacio].Contenido = Contenidox;
    listaProductos[lugarVacio].almacen.cantidad= cantidadx;
    listaProductos[lugarVacio].almacen.Precio = Preciox;
}

void mostrarDatos()
{
    cout << endl;
    cout << setw(6) << "Clave"
         << setw(30) << "Nombre del producto"
         << setw(25) << "Distribuidor"
         << setw(15) << "Contenido"
         << setw(14) << "Tipo"
         << setw(15) << "Cantidad"
         << setw(15) << "Precio" << endl;
    for(int i=0; i< NUM; i++)
    {
        if (listaProductos[i].almacen.Clave !=0)
        {
            cout << setw(6) << listaProductos[i].almacen.Clave
                 << setw(28) << listaProductos[i].NombreProducto
                 << setw(25) << listaProductos[i].Distribuidor
                 << setw(14) << listaProductos[i].Contenido
                 << setw(14)  << listaProductos[i].Tipo
                 << setw(14)  << listaProductos[i].almacen.cantidad
                 << setw(15) << listaProductos[i].almacen.Precio  << "$"<< endl;
        }
    }
}


void recuperarDeArchivo()
{
    ifstream lecturaArchivo("productos.txt", ios::in);
    if (!lecturaArchivo)
    {
        cerr << "No se pudo abrir el archivo" << endl;
        exit(1);
    }
    int Clavex;
    string NombreProductox;
    string Distribuidorx ;
    string Tipox ;
    string Contenidox;
    int cantidadx;
    double Preciox;
    while(lecturaArchivo >> Clavex >> NombreProductox >> Distribuidorx >> Tipox >> Contenidox >> cantidadx >>Preciox)
    {
        insertar(Clavex, reemplazarSharp(NombreProductox), reemplazarSharp(Distribuidorx), reemplazarSharp(Tipox),reemplazarSharp(Contenidox), cantidadx,Preciox);
    }

}


void escribirEnArchivo()
{
    ofstream salidaArchivo("productos.txt", ios::out);
    if (!salidaArchivo)
    {
        cerr << "No se pudo abrir el archivo";
        exit(1);
    }
    for(int i=0; i<NUM; i++)
    {
        if (listaProductos[i].almacen.Clave != 0)
        {
            salidaArchivo << listaProductos[i].almacen.Clave << ' '
                          << reemplazarEspacios(listaProductos[i].NombreProducto) << ' '
                          << reemplazarEspacios(listaProductos[i].Distribuidor) << ' '
                          << reemplazarEspacios(listaProductos[i].Contenido) << ' '
                          << reemplazarEspacios(listaProductos[i].Tipo) << ' '
                          << listaProductos[i].almacen.cantidad << ' '
                          << listaProductos[i].almacen.Precio << ' ' << endl;

        }
    }
}


int buscarLugarVacio()
{
    for (int i=0; i<NUM; i++)
    {
        if (listaProductos[i].almacen.Clave==0)
        {
            return i;
        }
    }
    return -1;
}



Productos aux;

void ordenacionBurbujaPorNombre()
{
    for (int i=0; i<NUM-1; i++)
    {
        for (int j=0; j<NUM-1; j++)
        {
            if(listaProductos[j].NombreProducto> listaProductos[j+1].NombreProducto)
            {
                //intercambio
                aux=listaProductos[j];
                listaProductos[j]=listaProductos[j+1];
                listaProductos[j+1]=aux;
            }
        }
    }
}

void ordenacionBurbujaPorClave()
{
    for (int i=0; i < NUM-1; i++)
    {
        for (int j=0; j < NUM-1; j++)
        {
            if (listaProductos[j].almacen.Clave > listaProductos[j+1].almacen.Clave)
            {
                //intercambio
                aux = listaProductos[j];
                listaProductos[j] = listaProductos[j+1];
                listaProductos[j+1] = aux;
            }
        }
    }
}

void ordenacionBurbujaPorPrecio()
{
    for (int i=0; i<NUM-1; i++)
    {
        for (int j=0; j<NUM-1; j++)
        {
            if(listaProductos[i].almacen.Precio > listaProductos[i].almacen.Precio)
            {
                //intercambio
                aux=listaProductos[j];
                listaProductos[j]=listaProductos[j+1];
                listaProductos[j+1]=aux;
            }
        }
    }
}

int busquedaSecuencial(int b)
{
    for (int i=0; i< NUM; i++)
    {
        if (listaProductos[i].almacen.Clave == b)
        {
            return i;
        }
    }
    return -1;
}

int busquedaBinaria(int b)
{
    int bajo, alto, central;
    bajo = 0;
    alto = NUM- 1;
    while (bajo <= alto)
    {
        central = (bajo+alto)/2;
        if (b == listaProductos[central].almacen.Clave)
        {
            return central;
        }
        else if (b < listaProductos[central].almacen.Clave)
        {
            alto = central -1;
        }
        else
        {
            bajo = central + 1;
        }

    }
    return -1;
}

///Funciones del saldo
void abonarSaldo()
{

    int nuevo;
    cout << "Abonar Saldo en pesos: ";
    cin >> nuevo;
    insertarS(nuevo);
    cout << "Saldo abonado correctamente: ";




}

void restarsaldo(int buscar)
{

    ordenacionBurbujaPorClave();
    int resultado = busquedaBinaria(buscar);
    if (resultado == -1)
    {
        cout << "No encontrado" << endl;
    }

    if (listaProductos[resultado].almacen.Precio > compras[0].saldo)
    {
        cout << "Saldo insuficiente, favor de abonar" << endl;
    }
    else
    {

        cout << "Producto comprada, se ha agregado a tu carrito" << endl;
        compras[0].saldo=compras[0].saldo-listaProductos[resultado].almacen.Precio;
        escribirEnArchivoS();
    }




}

void obtenersaldo()
{

    cout << compras[0].saldo;

}



void escribirEnArchivoS()
{
    ofstream Archivo("saldo.txt", ios::out);
    if (!Archivo)
    {
        cerr << "No se pudo abrir el archivo";
        exit(1);
    }
    Archivo << compras[0].saldo;

}

void recuperarDeArchivoS()
{
    ifstream lecturaArchivo("saldo.txt", ios::in);
    if (!lecturaArchivo)
    {
        cerr << "No se pudo abrir el archivo" << endl;
        exit(1);
    }
    int saldox;
    while(lecturaArchivo >> saldox)
    {
        insertarS(saldox);
    }
}

void insertarS(int nuevo)
{

    compras[0].saldo = nuevo + compras[0].saldo;

}

void inicializarS()
{
    compras[0].saldo = 0;
}

