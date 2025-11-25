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
  Libreria lib_aux;
  ArbolABB ab;//Declaracion del arbol
  Lista listaux;//Declaracion de lista generica
  string id_busqueda, id_aux, localidad_aux;
  string localidades [20] = {"Mostoles", "Alcala", "Leganes", "Fuenlabrada", "Getafe", "Alcorcon",
     "Torrejon", "Parla", "Alcobendas", "Coslada", "Pozuelo", "Rivas", "Valdemoro", "Majadahonda",
     "Aranjuez", "Arganda", "Boadilla", "Pinto", "Colmenar", "Tres Cantos"};

  srand(time(NULL));

  cout<< "Creado el ABB con "<< N_LIBRERIAS << " nodos"<<endl;
  cout<< "Arbol vacio creado: "<<endl;

  //Para usar los ID de librerias en los pedidos y para convertir librerias en nodos de un arbol:
  string id_libs[N_LIBRERIAS] = {};
  for(int i = 0; i< N_LIBRERIAS; i++){
    Libreria lib = genLibreria();
    id_libs[i] = lib.id_libreria;
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
    Pedido ped = genPedido(id_libs[aleat]);
    mostrarPedidos(ped);
    listaux.insertarNodo(ped);//insertar cada pedido en una lista generica para su posterior distribucion

    Libreria lib = ab.encontrar(ped.id_libreria);
    lib.listaPedidos->insertarNodo(ped);
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
       cout << "6) Llevar un pedido concreto de una libreria a otra" << endl;
       cout << "7) Mostrar una estadistica de unas librerias" << endl;
       cout << "8) Continuar con la distribucion de pedidos" << endl;
       cout << "0) Salir" << endl;
       cout << "Opcion: "; cin >> opcion;
       cout << endl;
       switch(opcion){
          case 1:
            cout << "Inserte una ID para tu libreria [0 - 999]" << endl;
            cin >> id_aux; cout << endl;
            cout << "Inserte una Localidad de las siguientes: "<<endl<<endl;
            for(int i = 0; i<20; i++){
              if(i <= 18){
                cout<<localidades[i]<<", ";
              }
              else{
                cout<<localidades[i]<<endl<<endl;
              }
            }

            cin >> localidad_aux;

            lib_aux = {id_aux, localidad_aux, new Lista()};

            ab.Insertar(lib_aux);
            mostrarDatosLib(ab, lib_aux.id_libreria);

            break;
          case 2:
            cout << "Por favor eliga una libreria de las existentes para eliminar: "<<endl;

            for(int i = 0; i<N_LIBRERIAS; i++){
              if(i <= N_LIBRERIAS-2){
                cout<<id_libs[i]<<", ";
              }
              else{
                cout<<id_libs[i]<<endl<<endl;
              }
            }

            cin >> id_aux;

            lib_aux = ab.encontrar(id_aux);

            if(lib_aux.id_libreria != " "){
              ab.Borrar(lib_aux);
              cout<<"Se ha borrado la libreria cuyo identificador es: "<<id_aux<<endl;
            }
            else{
              cout<<"Error, no se ha encontrado la libreria deseada."<<endl;
            }

            break;
          case 3:
            cout << "ID de la libreria?: ";
            cin >> id_busqueda;
            cout << endl;
            mostrarDatosLib(ab, id_busqueda);
            break;
          case 4:
            cout << "Funciona OP_4" << endl;
            break;
          case 5:
            cout << "Funciona OP_5" << endl;
            break;
          case 6:
            cout << "Funciona OP_6" << endl;
            break;
          case 7:
            cout << "Funciona OP_7" << endl;
            break;
          case 8:
            cout << "Funciona OP_8" << endl;
            break;
       }


  }while(opcion!=0);

  return 0;
};
