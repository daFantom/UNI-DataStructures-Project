// Librerias y ficheros de cabecera
# include <iostream>
# include <ctime>
# include <iomanip>
# include "ccontrol.h"
// Fin inclusiones

/*  Mensaje de cabecera del programa principal, aqui se explicara por medio del uso de un comentario de varias lineas como funciona el codigo por encima */

// Programa principal
using namespace std;

int main(){

  srand(time(NULL)); // Semilla para la pseudoaleatoriedad

  Libreria lib_aux;
  ArbolABB ab;//Declaracion del arbol

  ListaPedidos listaux; //Declaracion de lista generica

  ListaIdentificadores id_libs; // Declaracion de una lista de Identificadores dinamica.

  string id_busqueda, id_aux, localidad_aux, id_ped_aux;

  string localidades [20] = {"Mostoles", "Alcala", "Leganes", "Fuenlabrada", "Getafe", "Alcorcon",
    "Torrejon", "Parla", "Alcobendas", "Coslada", "Pozuelo", "Rivas", "Valdemoro", "Majadahonda",
    "Aranjuez", "Arganda", "Boadilla", "Pinto", "Colmenar", "Tres Cantos"};


  cout<< "Creado el ABB con "<< N_LIBRERIAS << " nodos"<<endl;
  cout<< "Arbol vacio creado: "<<endl;

  //Para usar los ID de librerias en los pedidos y para convertir librerias en nodos de un arbol:
  init_ccontrol(id_libs, ab, 0);

  //Menu principal
  int opcion;
  do{
    showMenu();
    cin >> opcion;
    cout << endl;

    switch(opcion){
      case 1:
        cout << "Inserte una ID para tu libreria [0 - 999]: ";

        cin >> id_aux; cout << endl;

        cout << "Inserte una Localidad de las siguientes: "<<endl;

        for(int i = 0; i<20; i++){
          if(i <= 18){
            cout<<localidades[i]<<", ";
          }
          else{
            cout<<localidades[i]<<"."<<endl<<endl;
          }
        }

        cin >> localidad_aux;

        cout<< "Creando libreria..."<<endl;
        lib_aux = {id_aux, localidad_aux, new ListaPedidos()};

        cout<<"Insertando..."<<endl;
        ab.Insertar(lib_aux);

        if(!id_libs.estaID(lib_aux.id_libreria)){
          id_libs.insertarNodo(lib_aux.id_libreria);

          mostrarDatosLib(ab, lib_aux.id_libreria);
          id_libs.recorrerListaID(); // Prueba
        }

        break;
      case 2:
        cout << "Por favor elija una libreria de las existentes para eliminar: "<<endl;

        id_libs.recorrerListaID();

        cin >> id_aux;

        cout<<"Buscando..."<<endl;
        lib_aux = ab.encontrarLib(id_aux);

        if(lib_aux.id_libreria != " "){

          ab.Borrar(lib_aux);

          id_libs.borrarNodo(lib_aux.id_libreria);

          cout<<"Se ha borrado la libreria cuyo identificador es: "<<id_aux<<endl;

        }
        else{
          cout<<"Error, no se ha encontrado la libreria deseada."<<endl;
        }

        break;
      case 3:
        cout << "Por favor, seleccione una de las siguientes librerias disponibles: "<<endl;

        id_libs.recorrerListaID();
        cin >> id_busqueda;
        cout << endl;

        mostrarDatosLib(ab, id_busqueda);
        break;
      case 4:
        cout << "Por favor, inserte el codigo del pedido a buscar respetando el formato establecido [P000A00]: "<<endl;
        cin >> id_ped_aux;
        cout << "Si no se muestra nada, no se ha encontrado el pedido."<<endl<<endl;
        cout<<"----------------------------------------------------------"<<endl;
        cout<<setw(7)<<"ID Lib"<<"|"<<setw(10)<<"ID_Pedido"<<"|"<<setw(8)<<"Codigo"<<"|"<<setw(12)<<"Materia"<<"|"<<setw(4)<<"U"<<"|"<<setw(11)<<"Fecha"<<"|"<<endl;
        cout<<"----------------------------------------------------------"<<endl;

        ab.InOrdenPedidos(encontrarPedido, id_ped_aux);

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
        init_ccontrol(id_libs, ab, 1);
        break;
    }

  }while(opcion!=0);

  return 0;
};
