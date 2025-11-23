#ifndef CCONTROL_H
#define CCONTROL_H

#include <iostream>
#include <string>

using namespace std;

// ===== CONSTANTES =====

#define N_LIBRERIAS 10
#define N_PEDIDOS 30

// |||| FIN CONSTANTES ||||

// ================= CLASE NODO PARA LOS ARBOLES DE BUSQUEDA BINARIA =================

class NodoArbol
{
    private:
        // Atributos:
        int dato; // Dato que queremos guardar, en nuestro caso sera un puntero a una lista.
        NodoArbol *izquierdo;    // Puntero al nodo / hijo izquierdo.
        NodoArbol *derecho;  // Puntero al nodo / hijo derecho.
        friend class ArbolABB; // Para que la clase ArbolABB pueda acceder a los atributos privados de la clase NodoArbol.

    public:
        // Constructor:
        NodoArbol(const int dat, NodoArbol *izq=NULL, NodoArbol *der=NULL) :
            dato(dat), izquierdo(izq), derecho(der) {} // Crea un nodo cuyo valor del dato no se puede cambiar (const) y pone al principio los punteros de los hijos a nulo.

};

typedef NodoArbol *pNodoArbol; // Para no tener que poner NodoArbol *var

// ||||||||||||||||||||| FIN CLASE NODO PARA LOS ARBOLES DE BUSQUEDA BINARIA |||||||||||||||||||||


// ================= CLASE NODO PARA LA LISTAS =================

class NodoLista
{
private:
    int valor;
    NodoLista *siguiente;
    friend class Lista;

public:
    NodoLista(int v, NodoLista *sig = NULL)
    {
        valor = v;
        siguiente = sig;
    }
};

typedef NodoLista *pNodoLista; // Para no tener que poner NodoLista *var

// ||||||||||||||||||||| FIN CLASE NODO PARA LA LISTAS |||||||||||||||||||||


// ================= CLASE LISTA SIMPLEMENTE ENLAZADA =================

class Lista
{
private:
    pNodoLista cabeza, actual, final;

public:
    Lista()
    {
        cabeza = actual = final= NULL;
    }
    ~Lista();

    void insertarNodo(int v);
    void borrarNodo(int v);
    bool listaVacia();
    void esCabeza();
    void esFinal();
    void esSiguiente();
    bool esActual();
    int valorActual();
    void recorrerLista();

};

// ||||||||||||||||||||| FIN CLASE LISTA SIMPLEMENTE ENLAZADA |||||||||||||||||||||


// ================= CLASE ARBOL DE BUSQUEDA BINARIA =================

class ArbolABB
{
    private:
        // Punteros de la lista, para cabeza y nodo actual:
        pNodoArbol raiz; // Puntero a la raiz
        pNodoArbol actual; // Puntero al nodo actual del arbol, inicialmente
        int contador;   // Contador para la altura??
        int altura; // Valor de la altura del arbol

    public:
        // Constructor y destructor basicos:
        ArbolABB() : raiz(NULL), actual(NULL) {} // Crea una arbol cuyos punteros, raiz y actual, se ponen a nulos al principio.
        ~ArbolABB(); // Destructor del arbol, me imagino que libera cada nodo del arbol.

         // Insertar en arbol ordenado:
        void Insertar(const int dat);

        // Borrar un elemento del arbol:
        void Borrar(const int dat);

        // Funcion de busqueda:
        bool Buscar(const int dat);

        // Comprobar si el arbol esta vacio:
        bool Vacio(pNodoArbol r);

        // Comprobar si es un nodo hoja:
        bool EsHoja(pNodoArbol r);

        // Contar numero de nodos:
        const int NumeroNodos();
        const int AlturaArbol();

        // Calcular altura de un int:
        int Altura(const int dat);

        // Moverse al nodo raiz:
        void Raiz();

        // Aplicar una funcion a cada elemento del arbol:
        void InOrden(void (*func)(int), pNodoArbol nodo=NULL, bool r=true);
        void PreOrden(void (*func)(int), pNodoArbol nodo=NULL, bool r=true);
        void PostOrden(void (*func)(int), pNodoArbol nodo=NULL, bool r=true);

    private:
        // Funciones auxiliares
        void Podar(NodoArbol* &);
        void auxContador(NodoArbol*);
        void auxAltura(NodoArbol*, int);
};

// ||||||||||||||||||||| FIN CLASE ARBOLES DE BUSQUEDA |||||||||||||||||||||

// ================= STRUCTS =================

// ------ PEDIDO ------
struct Pedido{
    string id_libreria;
    string id_pedido;
    string cod_libro;
    string materia;
    string cantidad;
    string fecha_envio;
};

// ------ LIBRERIA ------
struct Libreria{
    string id_libreria;
    string localidad;
    //Lista *listaPedidos = new Lista();  solo de momento
};

// ||||||||||||||||||||| FIN STRUCTS |||||||||||||||||||||


//DECLARACION DE FUNCIONES//
void mostrarLibrerias(Libreria lib);
void mostrarPedidos(Pedido ped);
Libreria genLibreria();
Pedido genPedido (string id_libreria);


#endif

