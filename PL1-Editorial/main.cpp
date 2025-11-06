#include <iostream>
#include <string>
#include <iomanip>
#include <ctime>
#include "editorial.h"

using namespace std;

int main(){
    /*ATENCION: NO TOQUES EL CODIGO, NO LO ENTENDEMOS, PERO FUNCIONA.
        SI LO ENTIENDES, NO FUNCIONA
        SI NO LO ENTIENDES, FUNCIONA
        ASIQUE MEJOR DEJARLO TAL Y COMO ESTA
            besos,
            manu
    */
    srand(time(NULL));
    int opcion, amount,numLib;
    Cola QIniciado, QAlmacen, QImprenta, QListo;
    Pila cajas[LIBRERIAS];
    Pedido paux; // Variable de Pedido auxiliar para las pruebas en la opcion 2.
    pedido_stock stock[MAX_TITULOS] = {}; // Inicializacion del STOCK, un array vacio que tendra una precarga de pedidos.
    for  ( int i = 0; i < MAX_TITULOS; i++){
        pedido_stock pstock = genStock(); // Precarga de los MAX_TITULOS pedidos. (En este caso MAX_TITULOS = 10)
        stock[i] = pstock; // Se pone en la posicion i (0, 1, 2, ..., 9) un struct de tipo pedido_stock
    }
    cout << "Simulacion: Editorial"<< endl << endl;             // Menu inicial del usuario.
    do{
        cout << "===== MENU =====" << endl;
        cout << "1) Generar N pedidos" << endl;
        cout << "2) Paso (una FASE)" << endl;
        cout << "3) Mostrar estado sistema" << endl;
        cout << "4) Ver contenido de una caja" << endl;
        cout << "0) Salir del programa" << endl;
        cout << "Opcion: "; cin >> opcion;
        cout << endl;
        switch(opcion){
            case 0:
                cout << "Saliendo..." << endl;                                  // Si el usuario inserta la opcion '0', el programa DEBERIA cerrarse. De ahi que tenga un 'return 0;' donde el switch por si acaso...
                return 0;
                break;
            case 1:
               cout << "Cantidad de pedidos a generar: ";
               cin >> amount;
               cout << endl;
               cout << "Generando "<<amount<<" pedidos..."<<endl;
               cout << endl;
               for(int i=0; i<amount; i++)                                      // Creamos amount pedidos de forma pseudoaleatoria y los vamos encolando en la cola QIniciado.
                {
                    int premio = rand()%10;              // Se utiliza un valor del 0 al 9 por cada iteracion del bucle para elegir un elemento del stock y crear un pedido con sus datos. Me gustaria que sonase lo del PREMIOOO  de las ferias pero uno no puede conseguir todo lo que quiere :(
                    Pedido ped_aux = genPedido(stock[premio].codigo_libro, stock[premio].materia);   // Se genera un pedido utilizando los datos de un pedido precargado stock y se encola en la cola QIniciados.
                    QIniciado.encolar(ped_aux);
                }
                cout<< "QIniciados:"<<endl;        // Luego, mostramos lo que tiene dentro una vez generado los pedidos.
                printQueue(QIniciado);
                break;
            case 2:
                mvItemsQueue(QIniciado, QAlmacen, QImprenta, QListo, cajas, stock);
                break;
            case 3:
                //////////////////////////////////////////////// Se muestra la cola QIniciados
                cout<< "QIniciados:"<<endl;
                printQueue(QIniciado);
                //////////////////////////////////////////////// Se muestra la cola QAlmacen
                cout << "QAlmacen:"<<endl;
                printQueue(QAlmacen);
                //////////////////////////////////////////////// Se muestra la cola QImprenta
                cout << "QImprenta:"<<endl;
                printQueue(QImprenta);
                //////////////////////////////////////////////// Se muestra la cola QListo
                cout << "QListo:"<<endl;
                printQueue(QListo);
                //////////////////////////////////////////////// Fin mostrar colas.
                cout<<"=== CAJAS ===" << endl;
                cout << "Libreria 0 --> "<< "tam = " <<cajas[0].getLength() <<", codigo cima --> " << cajas[0].getTopCode() << endl;
                cout << "Libreria 1 --> "<< "tam = " <<cajas[1].getLength() <<", codigo cima --> " << cajas[1].getTopCode() << endl;
                cout << "Libreria 2 --> "<< "tam = " <<cajas[2].getLength() <<", codigo cima --> " << cajas[2].getTopCode() << endl;
                cout << "Libreria 3 --> "<< "tam = " <<cajas[3].getLength() <<", codigo cima --> " << cajas[3].getTopCode() << endl;
                cout << "Libreria 4 --> "<< "tam = " <<cajas[4].getLength() <<", codigo cima --> " << cajas[4].getTopCode() << endl;
                cout << "Libreria 5 --> "<< "tam = " <<cajas[5].getLength() <<", codigo cima --> " << cajas[5].getTopCode() << endl;
                cout<< endl;
                 //////////////////////////////////////////////// Mostrar Stock
                 printStock(stock);
                break;
            case 4:
                cout<<"Indique el numero de libreria: ";               // Esto es para ver los contenidos de una caja de una libreria. No implementado aun jiji. (Probar otro switch-case en main y en una funcion)
                cin >> numLib;
                cout << endl;
                switch(numLib){
                    case 0:
                        cout <<"==="<<" Caja de la libreria codigo 0 (de ultimo elemento a primero) "<<"==="<< endl << endl;
                        printPile(cajas[numLib]);
                        break;
                    case 1:
                        cout <<"==="<<" Caja de la libreria codigo 1 (de ultimo elemento a primero) "<<"==="<< endl << endl;
                        printPile(cajas[numLib]);
                        break;
                    case 2:
                        cout <<"==="<<" Caja de la libreria codigo 2 (de ultimo elemento a primero) "<<"==="<< endl << endl;
                        printPile(cajas[numLib]);
                        break;
                    case 3:
                        cout <<"==="<<" Caja de la libreria codigo 3 (de ultimo elemento a primero) "<<"==="<< endl << endl;
                        printPile(cajas[numLib]);
                        break;
                    case 4:
                        cout <<"==="<<" Caja de la libreria codigo 4 (de ultimo elemento a primero) "<<"==="<< endl << endl;
                        printPile(cajas[numLib]);
                        break;
                    case 5:
                        cout <<"==="<<" Caja de la libreria codigo 5 (de ultimo elemento a primero) "<<"==="<< endl << endl;
                        printPile(cajas[numLib]);
                        break;
                    }
        }
    }while(opcion!=0);
    return 0;
}
