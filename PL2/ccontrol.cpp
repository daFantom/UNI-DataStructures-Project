#include "ccontrol.h"
#include <string>
#include <iomanip>

using namespace std;

// ================= METODOS LISTAS SIMPLEMENTE ENLAZADAS =================

// ------------- DESTRUCTOR -------------
Lista::~Lista()
{
    pNodoLista aux;
    while(cabeza)
    {
        aux = cabeza;
        cabeza = cabeza->siguiente;
        delete aux;
    }
    actual = NULL;
}

// ------------- INSERTAR UN NODO EN UNA LISTA -------------
void Lista::insertarNodo(Pedido ped) {//lo que he cambiado->int v
    pNodoLista aux;

    if (listaVacia())
    {
        cabeza = new NodoLista(ped, NULL);
        final=cabeza;
    }
    else
    {
        aux= new NodoLista(ped,NULL);
        final->siguiente=aux;
        final=aux;
    }
}
// -------------  BORRAR UN NODO DE UNA LISTA -------------
void Lista::borrarNodo(Pedido ped) {
    pNodoLista anterior;

    actual = cabeza;

    while (actual->pedido.id_pedido!=ped.id_pedido && (actual->siguiente)!=NULL)
    {
        anterior=actual;
        actual=actual->siguiente;
    }

    if (actual->pedido.id_pedido == ped.id_pedido){ //comprobacion de que esta v en la lista
        if(actual==cabeza)
            cabeza = actual->siguiente;
        else
        {
            anterior->siguiente = actual->siguiente;
            if (actual==final)
            {
                final=anterior;
            }
        }
        actual->siguiente=NULL;
        delete actual;
    }
}

// ------------- COMPROBAR SI UNA LISTA ESTA VACIA -------------
bool Lista::listaVacia(){
    return cabeza == NULL;
}

// ------------- PONER EL PUNTERO "ACTUAL" A LA CABEZA DE LA LISTA -------------
void Lista::esCabeza()
{
    actual = cabeza;
}

// ------------- PONER EL PUNTERO "ACTUAL" AL FINAL DE LA LISTA -------------
void Lista::esFinal()
{
    esCabeza();
    if(!listaVacia())
        while(actual->siguiente)
            esSiguiente();
}

// ------------- PONER EL PUNTERO "ACTUAL" A LA SIGUIENTE POSICION DE LA LISTA -------------
void Lista::esSiguiente()
{
    if(actual) actual = actual->siguiente;
}

// ------------- COMPRUEBA SI EL PUNTERO "ACTUAL" ES NULO O NO??? -------------
bool Lista::esActual()
{
    return actual != NULL;
}

// ------------- VER EL VALOR DEL PUNTERO "ACTUAL" -------------
Pedido Lista::valorActual()
{
    return actual->pedido;
}

// ------------- RECORRER UNA LISTA ENTERA -------------
void Lista::recorrerLista()
{
    pNodoLista aux;
    aux = cabeza;

    while(aux)
    {
        cout << aux->pedido.id_pedido << "-> ";
        aux = aux->siguiente;
    }
    cout << endl;
}

// ||||||||||||||||||||| FIN METODOS LISTAS SIMPLEMENTE ENLAZADAS |||||||||||||||||||||

// ================= METODOS ARBOLES DE BUSQUEDA =================

// ------------- DESTRUCTOR -------------
ArbolABB::~ArbolABB()
        {
            Podar(raiz);
        }

// ------------- ARBOL VACIO -------------
bool ArbolABB::Vacio(pNodoArbol r)
        {
            return r==NULL;
        }

// ------------- NODO ES HOJA? -------------
bool ArbolABB::EsHoja(pNodoArbol r)
        {
            return !r->derecho && !r->izquierdo;
        }

// ------------- COLOCAR PUNTERO "ACTUAL" A LA RAIZ DEL ARBOL -------------
void ArbolABB::Raiz()
        {
            actual = raiz;
        }

// ------------- auxiliar -> PODAR: BORRA TODOS LOS NODOS A PARTIR DE UNO DADO -------------
void ArbolABB::Podar(NodoArbol* &nodo)
{
   // Algoritmo recursivo, recorrido en postorden
   if(nodo) {
      Podar(nodo->izquierdo); // Podar izquierdo
      Podar(nodo->derecho);   // Podar derecho
      delete nodo;            // Eliminar nodo
      nodo = NULL;
   }
}

// ------------- INSERTAR UNA LIBRERIA EN UN ABB -------------
void ArbolABB::Insertar(const Libreria lib)//const int dat-> lo que he cambiado
{
   pNodoArbol padre = NULL;

   actual = raiz;
   // Buscar el int en el arbol, manteniendo un puntero al nodo padre
   while(!Vacio(actual) && lib.id_libreria != actual->libreria.id_libreria) {
      padre = actual;
      if(lib.id_libreria > actual->libreria.id_libreria) actual = actual->derecho;
      else if(lib.id_libreria < actual->libreria.id_libreria) actual = actual->izquierdo;
   }

   // Si se ha encontrado el elemento, regresar sin insertar
   if(!Vacio(actual)) return;

   // Si padre es NULL, entonces el arbol estaba vacio, el nuevo nodo sera el nodo raiz
   if(Vacio(padre)) raiz = new NodoArbol(lib);

   // Si el int es menor que el que contiene el nodo padre, lo insertamos en la rama izquierda
   else if(lib.id_libreria < padre->libreria.id_libreria) padre->izquierdo = new NodoArbol(lib);

   // Si el int es mayor que el que contiene el nodo padre, lo insertamos en la rama derecha
   else if(lib.id_libreria > padre->libreria.id_libreria) padre->derecho = new NodoArbol(lib);
}

// ------------- ELIMINAR UNA LIBRERIA EN UN ABB -------------
void ArbolABB::Borrar(const Libreria lib)//int dat->lo que he cambiado
{
   pNodoArbol padre = NULL;
   pNodoArbol nodo;
   Libreria aux;

   actual = raiz;
   // Mientras sea posible que el valor esta en el arbol
   while(!Vacio(actual)) {
      if(lib.id_libreria == actual->libreria.id_libreria) { // Si el valor esta en el nodo actual
         if(EsHoja(actual)) { // Y si ademas es un nodo hoja: lo borramos
            if(padre){ // Si tiene padre (no es el nodo raiz)
               // Anulamos el puntero que le hace referencia
               if(padre->derecho == actual) padre->derecho = NULL;
               else if(padre->izquierdo == actual) padre->izquierdo = NULL;
            }
            else raiz=NULL;

            delete actual; // Borrar el nodo
            actual = NULL;
            return;
         }
         else { // Si el valor esta en el nodo actual, pero no es hoja
            // Buscar nodo
            padre = actual;
            // Buscar nodo mas izquierdo de rama derecha
            if(actual->derecho) {
               nodo = actual->derecho;
               while(nodo->izquierdo) {
                  padre = nodo;
                  nodo = nodo->izquierdo;
               }
            }
            // O buscar nodo mas derecho de rama izquierda
            else {
               nodo = actual->izquierdo;
               while(nodo->derecho) {
                  padre = nodo;
                  nodo = nodo->derecho;
               }
            }
            // Intercambiar valores de no a borrar u nodo encontrado
            // y continuar, cerrando el bucle. El nodo encontrado no tiene
            // por que ser un nodo hoja, cerrando el bucle nos aseguramos
            // de que solo se eliminan nodos hoja.
            aux = actual->libreria;
            actual->libreria = nodo->libreria;
            nodo->libreria = aux;
            actual = nodo;
         }
      }
      else { // Todavia no hemos encontrado el valor, seguir buscandolo
         padre = actual;
         if(lib.id_libreria > actual->libreria.id_libreria) actual = actual->derecho;
         else if(lib.id_libreria < actual->libreria.id_libreria) actual = actual->izquierdo;
      }
   }
}

//  ------------- RECCORRIDO DEL ARBOL EN IN-ORDEN (aplicamos la funcion func, que tiene el prototipo): -------------

// void func(int&);
void ArbolABB::InOrden(void (*func)(Libreria) , pNodoArbol nodo, bool r)
{
  if (raiz==NULL) {cout<<"Arbol vacio"<<endl; return;}
   if(r) nodo = raiz;
   if(nodo->izquierdo) InOrden(func, nodo->izquierdo, false);
   func(nodo->libreria);
   if(nodo->derecho) InOrden(func, nodo->derecho, false);
}

// ------------- RECORRIDO DEL ARBOL EN PRE-ORDEN (aplicamos la funcion func, que tiene el prototipo): -------------

// void func(int&);
void ArbolABB::PreOrden(void (*func)(Libreria), pNodoArbol nodo, bool r)
{
      if (raiz==NULL) {cout<<"Arbol vacio"<<endl; return;}
   if(r) nodo = raiz;
   func(nodo->libreria);
   if(nodo->izquierdo) PreOrden(func, nodo->izquierdo, false);
   if(nodo->derecho) PreOrden(func, nodo->derecho, false);
}

// ------------- RECORRIDO DEL ARBOL EN POST-ORDEN (aplicamos la funcion func, que tiene el prototipo): -------------

// void func(int&);
void ArbolABB::PostOrden(void (*func)(Libreria), pNodoArbol nodo, bool r)
{
      if (raiz==NULL) {cout<<"Arbol vacio"<<endl; return;}
   if(r) nodo = raiz;
   if(nodo->izquierdo) PostOrden(func, nodo->izquierdo, false);
   if(nodo->derecho) PostOrden(func, nodo->derecho, false);
   func(nodo->libreria);
}

// ------------- BUSCAR UNA LIBRERIA EN EL ARBOL -------------
bool ArbolABB::Buscar(const Libreria lib)
{
   actual = raiz;

   // Todavia puede aparecer, ya que quedan nodos por mirar
   while(!Vacio(actual)) {
      if(lib.id_libreria == actual->libreria.id_libreria) return true; // int encontrado
      else if(lib.id_libreria > actual->libreria.id_libreria) actual = actual->derecho; // Seguir
      else if(lib.id_libreria < actual->libreria.id_libreria) actual = actual->izquierdo;
   }
   return false; // No esta en arbol
}

// ------------- CALCULAR LA ALTURA DEL NODO QUE CONTIENE LA LIBRERIA INDICADA -------------
int ArbolABB::Altura(const Libreria lib)
{
   int altura = 0;
   actual = raiz;

   // Todavia puede aparecer, ya que quedan nodos por mirar
   while(!Vacio(actual)) {
      if(lib.id_libreria == actual->libreria.id_libreria) return altura; // int encontrado
      else {
         altura++; // Incrementamos la altura, seguimos buscando
         if(lib.id_libreria > actual->libreria.id_libreria) actual = actual->derecho;
         else if(lib.id_libreria < actual->libreria.id_libreria) actual = actual->izquierdo;
      }
   }
   return -1; // No esta en arbol
}

// ------------- CONTAR EL NUMERO DE NODOS -------------
const int ArbolABB::NumeroNodos()
{
   contador = 0;

   auxContador(raiz); // Funcion auxiliar
   return contador;
}

// ------------- Funcion auxiliar para contar nodos. Funcion recursiva de recorrido en preorden, el proceso es aumentar el contador -------------
void ArbolABB::auxContador(pNodoArbol nodo)
{
   contador++;  // Otro nodo
   // Continuar recorrido
   if(nodo->izquierdo) auxContador(nodo->izquierdo);
   if(nodo->derecho)   auxContador(nodo->derecho);
}

// ------------- CALCULAR LA ALTURA DEL ARBOL (el nodo mayor de dicho arbol) -------------
const int ArbolABB::AlturaArbol()
{
   altura = 0;

   auxAltura(raiz, 0); // Funcion auxiliar
   return altura;
}

// Funcion auxiliar para calcular altura. Funcion recursiva de recorrido en postorden, el proceso es actualizar la altura solo en nodos hojas de mayor altura de la maxima actual
void ArbolABB::auxAltura(pNodoArbol nodo, int a)
{
   // Recorrido postorden
   if(nodo->izquierdo) auxAltura(nodo->izquierdo, a+1);
   if(nodo->derecho)   auxAltura(nodo->derecho, a+1);

   // Proceso, si es un nodo hoja, y su altura es mayor que la actual del arbol, actualizamos la altura actual del arbol
   if(EsHoja(nodo) && a > altura) altura = a;
}

// -------------  FUNCION DE PRUEBA PARA RECORRRIDOS DE UN ARBOL -------------
void Mostrar(int d)
{
   cout << d << ",";
}
// ||||||||||||||||||||| FIN METODOS ARBOLES DE BUSQUEDA |||||||||||||||||||||



// =========================  FUNCION PARA ESCRITURA DE LAS LIBRERIAS EN EL MENU =========================
void mostrarLibrerias(Libreria lib){

    cout<<setw(2)<<"ID_LIB: "<<lib.id_libreria<<setw(2)<<" - Localidad: "<<lib.localidad <<setw(12)<<" - Num Pedidos: "<<lib.listaPedidos->contarPedidosLib()<<endl;

}
// =========================  FUNCION PARA ESCRITURA DE LAS LIBRERIAS EN EL MENU =========================
void mostrarPedidos(Pedido ped){


    cout<<setw(7)<<ped.id_libreria<<'|'<<setw(10)<<ped.id_pedido<<'|'<<setw(8)<<ped.cod_libro<<'|'<<setw(12)<<ped.materia<<'|'<<setw(4)<<ped.cantidad<<"|"<<setw(11)<<ped.fecha_envio<<endl;

}

// =========================  FUNCION PARA LA CREACION DE LAS LIBRERIAS =========================
Libreria genLibreria(){
    string id_libreria = to_string(rand()%999);
    string localidad;
    string librerias [20] = {"Mostoles", "Alcala", "Leganes", "Fuenlabrada", "Getafe", "Alcorcon",
     "Torrejon", "Parla", "Alcobendas", "Coslada", "Pozuelo", "Rivas", "Valdemoro", "Majadahonda",
     "Aranjuez", "Arganda", "Boadilla", "Pinto", "Colmenar", "Tres Cantos"};
    localidad = librerias[rand()%(sizeof(librerias)/sizeof(librerias[0]))];



    Libreria libreria = {id_libreria,localidad, new Lista()};
    return libreria;

}
// =========================  FUNCION PARA LA CREACION DE PEDIDOS =========================
Pedido genPedido (string id_libreria){
    char abecedario[26] = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
    int numaleat1,numaleat2;
    char letraAleat;
    letraAleat = abecedario[rand()%(sizeof(abecedario)/sizeof(abecedario[0]))];
    numaleat1=rand()%999; // Se coge un numero de entre 0 y 998 de forma pseudoaleatoria.
    numaleat2=rand()%99;
    string cod_libro = to_string(numaleat1)+letraAleat+to_string(numaleat2);

    string cantidad = to_string(rand()%21);

    string fecha_envio = to_string(rand()%32)+"-"+to_string(rand()%13)+"-2025";

    string materias[6] ={"Matematicas","Fisica","Tecnologia","Musica","Historia", "Lengua"};
    string materia = materias[rand()%(sizeof(materias)/sizeof(materias[0]))];

    string id_pedido = "P"+to_string(rand()%99999);

    Pedido ped = {id_libreria,id_pedido,cod_libro,materia,cantidad,fecha_envio};
    return ped;
}
// =========================  FUNCION PARA CONTAR PEDIDOS EN UNA LISTA DE UNA LIBRERIA =========================

int Lista::contarPedidosLib(){
   pNodoLista aux;
   aux = cabeza;

   int contador = 0;

   while(aux!= NULL){
       contador++;
       aux = aux->siguiente;

   }
   return contador;

}
// =========================  INSERTAR EN UNA LIBRERIA(CORRESPONDIENTE A OPCION 1) =========================

void insertarEnListaLib(Pedido ped){

}
// =========================  CONVERTIR LIBRERIA EN UN NODO DE UN ARBOL =========================

//en estos momentos no se esta utilizando esta funcion
NodoArbol* crearNodoLib(Libreria lib){
    return new NodoArbol(lib);
}

