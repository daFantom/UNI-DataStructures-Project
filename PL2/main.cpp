// Librerias y ficheros de cabecera
# include <iostream>
# include <ctime>
#include <iomanip>
#include "ccontrol.h"
// Fin inclusiones

/*  Mensaje de cabecera del programa principal, aqui se explicara por medio del uso de un comentario de varias lineas como funciona el codigo por encima */

// Programa principal
using namespace std;
int main(){
  ArbolABB ab;//Declaracion del arbol
  Lista listaux;//Declaracion de lista generica


  cout<< "Creado el ABB con "<< N_LIBRERIAS << " nodos"<<endl;
  cout<< "Arbol vacio creado: "<<endl;

  //Para usar los ID de librerias en los pedidos y para convertir librerias en nodos de un arbol:
  Libreria id[N_LIBRERIAS] = {};
  for(int i = 0; i< N_LIBRERIAS; i++){
    Libreria lib = genLibreria();
    id[i] = lib;
    ab.Insertar(lib);
    mostrarLibrerias(lib);
  }
  cout<<endl;


  cout<< "Creando los siguientes pedidos nuevos:"<<endl;
  cout<<"----------------------------------------------------------"<<endl;
  cout<<setw(7)<<"ID Lib"<<"|"<<setw(10)<<"ID_Pedido"<<"|"<<setw(8)<<"Codigo"<<"|"<<setw(12)<<"Materia"<<"|"<<setw(4)<<"U"<<"|"<<setw(11)<<"Fecha"<<"|"<<endl;
  cout<<"----------------------------------------------------------"<<endl;

  for (int i=0; i<N_PEDIDOS; i++){
    int aleat = rand()%10;
    Pedido ped = genPedido(id[aleat].id_libreria);
    //insertar cada pedido en una lista generica para su posterior distribucion
    mostrarPedidos(ped);
  }
  cout<<endl;


  //Menu principal
  int opcion;
  do{
       cout << "===== MENU =====" << endl;
       cout << "1) Insertar una libreria de forma manual" << endl;
       cout << "2) Borrar una libreria del arbol" << endl;
       cout << "3) Mostrar los datos de una libreria dada" << endl;
       cout << "4) Buscar un pedido concreto por su ID" << endl;
       cout << "5) Extraer un pedido concreto" << endl;
       cout << "5) Extraer un pedido concreto" << endl;
       cout << "6) Llevar un pedido concreto de una libreria a otra" << endl;
       cout << "7) Mostrar una estadistica de unas librerias" << endl;
       cout << "8) Continuar con la distribucion de pedidos" << endl;
       cout << "0) Salir" << endl;
       cout << "Opcion: "; cin >> opcion;
       cout << endl;


  }while(opcion!=0);

  return 0;
};
