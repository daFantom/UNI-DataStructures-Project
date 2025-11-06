#include <ctime>
#include <iostream>
#include <iomanip>
#include <string>
#include "editorial.h"

// ====================== METODOS COLA ======================

//Destructor Cola
Cola::~Cola(){
    while(frente) desencolar();
};

//Agregar elemento en la cola
void Cola::encolar(Pedido v)
{
    pNodo nuevo;
    nuevo = new Nodo(v); // Se crea un nodo nuevo
// Si la cola no es vacia, se agrega el nuevo a continuacion de ultimo
    if(final) final->siguiente = nuevo;
//El ultimo elemento de la cola es el nuevo nodo
    final= nuevo;
// Si frente es NULL, la cola esta vacia y el nuevo nodo pasa a ser el primero
    if(!frente) frente = nuevo;
}

//Leer elemento de la cola
Pedido Cola::desencolar()
{
    pNodo nodo; //Var aux para manipular nodo
    Pedido v; //Var aux para retorno del valor
// Nodo apunta al primer elemento de la pila
    nodo = frente;
    Pedido ped_vacio = {0,"","","",0,""};
    if(!nodo) return ped_vacio; // Si no hay nodos en la pila se devuelve 0
//Se asigna a frente la direccion del segundo nodo
    frente = nodo->siguiente;
//Se guarda el valor de retorno
    v = nodo->valor;
    delete nodo; // Se borra el nodo
// Si cola vacia, ultimo debe ser NULL tambien
    if(!frente) final = NULL;
    return v;
}

//METODO PARA SABER SI COLA VACIA (gracias Javier <3)
bool Cola::esVacia()
{
    if (!frente) return true;
    else return false;
}
// METODO PARA SABER LA LONGITUD DE UNA COLA (gracias javier x2)

int Cola::getLength(){
    pNodo point_aux;
    int len = 0;
     point_aux = frente;
     while(point_aux!=NULL){
        len++;
        point_aux = point_aux->siguiente;
     }
     return len;
}

Pedido Cola::getFront(){
    return frente->valor;
}
// ====================== METODOS PILA ======================

//Destructor de la Pila
Pila::~Pila()
{
    while(cima) desapilar();
}
//Meter elemento en la Pila
void Pila::apilar(Pedido v)
{
    pNodo nuevo; //Var aux para manipular el nuevo nodo
//Se crea un nodo nuevo
    nuevo = new Nodo(v, cima);
//El comienzo de la pila es el nuevo nodo
    cima = nuevo;
};

//Sacar elemento de la Pila
Pedido Pila::desapilar()
{
    pNodo nodo; //Var aux para manipular el nodo
    Pedido v; //Var aux para el retorno del valor del nodo
    Pedido ped_vacio = {0,"","","",0,""};
    if(!cima) return ped_vacio; // Si no hay nodos en la pila se devuelve un alumno vacio
// Nodo apunta al primer elemento de la pila
    nodo = cima;
//Se asigna a pila toda la pila menos el primer elemento
    cima= nodo->siguiente;
//Se guarda el retorno del valor del nodo
    v = nodo->valor;
//Se borra el nodo
    delete nodo;
    return v;
}
bool Pila::esVacia(){
    if(!cima){
        return true;
    }
    else{
        return false;
    }
}
int Pila::getLength(){
    pNodo point_aux;
    int len = 0;
     point_aux = cima;
     while(point_aux!=NULL){
        len++;
        point_aux = point_aux->siguiente;
     }
     return len;
}
string Pila::getTopCode(){
    if (!cima){
        return "(vacio)";
    }
    else{
        return cima->valor.id_pedido;
    }
}
// FUNCIONES Y PROCEDIMIENTOS
//  ========================= FUNCION PARA GENERAR PEDIDOS ALEATORIOS =========================
Pedido genPedido(string codebook, string materia){
    int unidades;
    unidades = rand()%20 + 1;
    string id_pedido = "P"+to_string(rand()%99999); // el rand() representa la parte numerica del codigo.
    Pedido ped = {(rand()%6),id_pedido,codebook,materia,unidades,"Iniciado"}; // Cuando se crea un pedido, siempre empieza en iniciado :D
    return ped;
}

// =========================  FUNCION PARA LA PRECARGA DE PEDIDOS EN EL STOCK =========================
pedido_stock genStock(){
    string materias[6] ={"Matematicas","Fisica","Tecnologia","Musica","Historia", "Lengua"};
    char abecedario[26] = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'}; // Todo el abecedario para elegir una letra de forma aleatoria.
     int numaleat1,numaleat2;
     char letraAleat;
     letraAleat = abecedario[rand()%(sizeof(abecedario)/sizeof(abecedario[0]))]; // Se recoge una letra del Array 'abecedario' de manera randomizada.
     numaleat1=rand()%999; // Se coge un numero de entre 0 y 998 de forma pseudoaleatoria.
     numaleat2=rand()%99; // Se coge un numero de entre 0 y 98 de forma pseualeatoria.
    string materia = materias[rand()%(sizeof(materias)/sizeof(materias[0]))];
    string cod_libro = to_string(numaleat1)+letraAleat+to_string(numaleat2);
    pedido_stock pstock = {cod_libro,materia,TAM_LOTE};
    return pstock;
}


// ========================= PROCEDIMIENTO PARA IMPRIMIR LOS DATOS DE UNA COLA =========================
void printQueue(Cola &c){
    int tam = c.getLength(); // POR SI ACASO, AUNQUE SE PODRIA UTILIZAR LA FUNCION c.getLength(); YA QUE SE VA ENCOLANDO Y EL TAMANIO NO CAMBIA.
    Pedido p_aux; // Variable auxiliar Pedido para poder mostrar sus elementos por pantalla
    cout<<"-----------------------------------------------------"<<endl;
    cout<<setw(4)<<"Lib"<<"|"<<setw(10)<<"ID_Pedido"<<"|"<<setw(8)<<"Codigo"<<"|"<<setw(12)<<"Materia"<<"|"<<setw(4)<<"U"<<"|"<<setw(10)<<"Estado"<<"|"<<endl;
    cout<<"-----------------------------------------------------"<<endl;
    if(c.esVacia()){
        cout<<"(vacio)"<<endl; // Si la cola esta vacia de antes, lo mostramos por medio de este cout.
    }
    else{
            for(int i = 0; i<tam;i++){
                p_aux = c.desencolar(); // Si no esta vacia, pues vamos desencolando y mostrando los atributos de cada pedido hasta que se vacie.
                cout<<setw(4)<<p_aux.id_editorial<<"|"<<setw(10)<<p_aux.id_pedido<<"|"<<setw(8)<<p_aux.cod_libro<<"|"<<setw(12)<<p_aux.materia<<"|"<<setw(4)<<p_aux.cantidad<<"|"<<setw(10)<<p_aux.estado<<"|"<<endl;
                c.encolar(p_aux); // Lo volvemos a encolar, pues sabiendo la longitud de la cola, cada elemento volvera a su puesto original una vez terminado el bucle.
            }
        }
    cout << endl;
}
// ========================= PROCEDIMIENTO PARA MOSTRAR LOS ELEMENTOS DE UNA PILA / CAJA =========================
void printPile(Pila &p){
    Pila aux_pile;                              // Creamos una pila auxiliar que esta vacia.
    Pedido p_aux;                            // La misma funcion que la variable del procedimiento anterior.
    int sizep = p.getLength();         // Utilizamos la longitud de la pila principal para desapilar los pedidos y mostrarlos.
    cout<<"-----------------------------------------------------"<<endl;
    cout<<setw(4)<<"Lib"<<"|"<<setw(10)<<"ID_Pedido"<<"|"<<setw(8)<<"Codigo"<<"|"<<setw(12)<<"Materia"<<"|"<<setw(4)<<"U"<<"|"<<setw(10)<<"Estado"<<"|"<<endl;
    cout<<"-----------------------------------------------------"<<endl;
    if(p.esVacia()){
        cout<<"(vacia)"<<endl;        // Si la pila esta vacia de antes, mostramos este mensaje y no imprimimos nada mas.
    }
    else{
        for(int i = 0;i<sizep;i++){
                p_aux = p.desapilar();  // Si no esta vacia,  vamos desapilando hasta que se quede vacia.
                cout<<setw(4)<<p_aux.id_editorial<<"|"<<setw(10)<<p_aux.id_pedido<<"|"<<setw(8)<<p_aux.cod_libro<<"|"<<setw(12)<<p_aux.materia<<"|"<<setw(4)<<p_aux.cantidad<<"|"<<setw(10)<<p_aux.estado<<"|"<<endl;
                aux_pile.apilar(p_aux); // Los apilamos la pila auxiliar para tener la inversa.
        }
   }

   sizep = aux_pile.getLength(); // Le asignamos la longitud de la pila auxiliar para restaurar la pila original.

    for(int j = 0; j<sizep;j++){
            p_aux = aux_pile.desapilar();
            p.apilar(p_aux);
    }

    cout<<endl;
}

// ========================= ENCONTRAR UN PEDIDO EN EL STOCK =========================
int findInStock(Pedido p, pedido_stock arr[]){
    int index = 0;
    for(int i =0;i<MAX_TITULOS;i++){
        if (arr[i].codigo_libro == p.cod_libro){
            return index;
            break;
        }
        index++;
    }
    return 0;
}

// ========================= GENERAR PASO W.I.P =========================

/* ~~~~~~~~~~~~~~~~~~~ PROBLEMAS ~~~~~~~~~~~~~~~~~~~
    - Lo que conseguimos o al utilizar findInStock es un objeto de tipo pedido_stock del Stock, sin embargo no lo estamos modificando como tal, solo una copia suya
    luego habria que conseguir su posicion en el array y modificarlo. EUREKA DSLFILGSDFLKJLS
*/


void mvItemsQueue(Cola &qIni, Cola &qAlma, Cola &qImpre, Cola &qListo, Pila cajas[], pedido_stock stock[]){
    Pedido aux;
    int pos_stock;
    ////////////////////////////////////////////// Probamos el paso en la cola de Listos para llevar pedidos a una caja en concreto.
    if(!qListo.esVacia()){
        for(int i=0;(i<N_PEDIDOS_PASO)&&(!qListo.esVacia());i++){
                aux = qListo.desencolar();
                int lib = aux.id_editorial;
                if((cajas[lib].getLength())==5){
                    cout << "Caja "<<lib<<", vaciando..."<<endl;
                    cajas[lib].~Pila();
                    cout<<"Insertando pedido "<<aux.id_pedido<<"..."<<endl;
                    aux.estado="Caja";
                    cajas[lib].apilar(aux);
                }
                else{
                    aux.estado="Caja";
                    cajas[lib].apilar(aux);
                }
        }
    }
    ////////////////////////////////////////////// Probamos el paso en la cola de 'Imprenta' para llevar pedidos a la cola de 'Listo' o devolverlos a 'Imprenta' si da el caso.
    if(!qImpre.esVacia()){
        for(int i=0;(i<N_PEDIDOS_PASO)&&(!qImpre.esVacia());i++){
            aux = qImpre.desencolar();
            pos_stock = findInStock(aux,stock); // Encontramos el codigo del libro del que se ha generado el pedido y lo guardamos en aux_stock.

            // Si la cantidad en stock de este tipo de libros es mayor que la que se pide, entonces restamos y encolamos.
            if(stock[pos_stock].unidades>aux.cantidad){
                stock[pos_stock].unidades -= aux.cantidad;
                aux.estado = "Listo";
                qListo.encolar(aux);
            }
            // Si no, lo volvemos a encolar en 'Imprenta' y agregamos 10 (o TAM_LOTE) a la cantidad que se encuentra en stock.
            else{
                qImpre.encolar(aux);
                stock[pos_stock].unidades += TAM_LOTE;
            }
        }
    }
    if(!qAlma.esVacia()){
        for(int i=0;(i<N_PEDIDOS_PASO)&&(!qAlma.esVacia());i++){
            aux = qAlma.desencolar();
            pos_stock = findInStock(aux,stock);
            if(stock[pos_stock].unidades>aux.cantidad){
                stock[pos_stock].unidades-=aux.cantidad;
                aux.estado="Listo";
                qListo.encolar(aux);
            }
            else{
                stock[pos_stock].unidades+=TAM_LOTE;
                aux.estado="Imprenta";
                qImpre.encolar(aux);
            }
        }
    }
    if(!qIni.esVacia()){
        for(int i=0;(i<N_PEDIDOS_PASO)&&(!qIni.esVacia());i++){
            aux = qIni.desencolar();
            aux.estado="Almacen";
            qAlma.encolar(aux);
        }
    }
}

// ========== IMPRIMIR STOCK ==========
void printStock(pedido_stock arr[MAX_TITULOS]){
    cout << "== STOCK ==" << endl;
    cout<<setw(8)<<"Codigo"<<"|"<<setw(12)<<"Materia"<<"|"<<setw(10)<<"Unidades"<<endl;
    cout<<"----------------------------------"<<endl;
    for (int i=0;i<MAX_TITULOS;i++){
        cout<<setw(8)<<arr[i].codigo_libro<<"|"<<setw(12)<<arr[i].materia<<"|"<<setw(8)<<arr[i].unidades<<endl;
    }
    cout << endl;
}
