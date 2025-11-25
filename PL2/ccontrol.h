#ifndef CCONTROL_H
#define CCONTROL_H

#include <iostream>
#include <string>

using namespace std;

// ===== CONSTANTES =====

#define N_LIBRERIAS 10
#define N_PEDIDOS 30

// |||| FIN CONSTANTES ||||



// ------ STRUCT PEDIDO ------
struct Pedido{
    string id_libreria;
    string id_pedido;
    string cod_libro;
    string materia;
    string cantidad;
    string fecha_envio;
};



// ================= CLASE NODO PARA LA LISTAS DE PEDIDOS =================

class NodoListaPedidos
{
private:
    Pedido pedido;
    NodoListaPedidos *siguiente;
    friend class ListaPedidos;

public:
    NodoListaPedidos(Pedido ped, NodoListaPedidos *sig = NULL)
    {
        pedido = ped;
        siguiente = sig;
    }
};

typedef NodoListaPedidos *pNodoListaPedidos; // Para no tener que poner NodoLista *var

// ||||||||||||||||||||| FIN CLASE NODO PARA LA LISTAS DE PEDIDOS |||||||||||||||||||||



// ================= CLASE LISTA SIMPLEMENTE ENLAZADA PARA PEDIDOS =================

class ListaPedidos
{
private:
    pNodoListaPedidos cabeza, actual, final;

public:
    ListaPedidos()
    {
        cabeza = actual = final= NULL;
    }
    ~ListaPedidos();

    void insertarNodo(Pedido ped);
    void borrarNodo(Pedido ped);
    bool listaVacia();
    void esCabeza();
    void esFinal();
    void esSiguiente();
    bool esActual();
    Pedido valorActual();
    void recorrerLista();
    int contarPedidosLib();

};

// ||||||||||||||||||||| FIN CLASE LISTA SIMPLEMENTE ENLAZADA PEDIDOS ||||||||||||||||||||


// ------ LIBRERIA ------
struct Libreria{
    string id_libreria;
    string localidad;
    ListaPedidos *listaPedidos;
};

// ================= CLASE NODO PARA LA LISTAS DE IDENTIFICADORES =================

class NodoListaID
{
private:
    string identificador_lib;
    NodoListaID *siguiente;
    friend class ListaIdentificadores;

public:
    NodoListaID(string id_lib, NodoListaID *sig = NULL)
    {
        identificador_lib = id_lib;
        siguiente = sig;
    }
};

typedef NodoListaID *pNodoListaID; // Para no tener que poner NodoLista *var

// ||||||||||||||||||||| FIN CLASE NODO PARA LA LISTAS DE IDENTIFICADORES |||||||||||||||||||||

// ================= CLASE LISTA SIMPLEMENTE ENLAZADA PARA LOS IDENTIFICADORES DE LIBRERIAS =================
class ListaIdentificadores
{
private:
    pNodoListaID cabeza, actual, final;

public:
    ListaIdentificadores()
    {
        cabeza = actual = final= NULL;
    }
    ~ListaIdentificadores();
    void insertarNodo(string id_lib);
    void borrarNodo(string id_lib);
    bool listaVacia();
    void esCabeza();
    void esFinal();
    void esSiguiente();
    bool esActual();
    string valorActual();
    void recorrerListaID();
    int contarElementos();
    string conseguirNodoN(int n);
    bool esta(string id_lib);

};

// ||||||||||||||||||||| FIN CLASE LISTA SIMPLEMENTE ENLAZADA IDENTIFICADORES LIBRERIAS ||||||||||||||||||||


// ================= CLASE NODO PARA LOS ARBOLES DE BUSQUEDA BINARIA =================

class NodoArbol
{
    private:
        // Atributos:
        Libreria libreria;// Dato que queremos guardar, en nuestro caso sera un puntero a una lista.
        NodoArbol *izquierdo;    // Puntero al nodo / hijo izquierdo.
        NodoArbol *derecho;  // Puntero al nodo / hijo derecho.
        friend class ArbolABB; // Para que la clase ArbolABB pueda acceder a los atributos privados de la clase NodoArbol.

    public:
        // Constructor:
        NodoArbol(const Libreria& lib, NodoArbol *izq=NULL, NodoArbol *der=NULL) :
            libreria(lib), izquierdo(izq), derecho(der) {} // Crea un nodo cuyo valor del dato no se puede cambiar (const) y pone al principio los punteros de los hijos a nulo.

};

typedef NodoArbol *pNodoArbol; // Para no tener que poner NodoArbol *var

// ||||||||||||||||||||| FIN CLASE NODO PARA LOS ARBOLES DE BUSQUEDA BINARIA |||||||||||||||||||||


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
        void Insertar(const Libreria lib);

        // Borrar un elemento del arbol:
        void Borrar(const Libreria lib);

        // Funcion de busqueda:
        bool Buscar(const Libreria lib);

        // Comprobar si el arbol esta vacio:
        bool Vacio(pNodoArbol r);

        // Comprobar si es un nodo hoja:
        bool EsHoja(pNodoArbol r);

        // Contar numero de nodos:
        const int NumeroNodos();
        const int AlturaArbol();

        // Calcular altura de un int:
        int Altura(const Libreria lib);

        // Moverse al nodo raiz:
        void Raiz();

        // Aplicar una funcion a cada elemento del arbol:
        void InOrden(void (*func)(Libreria), pNodoArbol nodo=NULL, bool r=true);
        void PreOrden(void (*func)(Libreria), pNodoArbol nodo=NULL, bool r=true);
        void PostOrden(void (*func)(Libreria), pNodoArbol nodo=NULL, bool r=true);

        //Buscar libreria por su id
        Libreria encontrar(string id);

    private:
        // Funciones auxiliares
        void Podar(NodoArbol* &);
        void auxContador(NodoArbol*);
        void auxAltura(NodoArbol*, int);
};

// ||||||||||||||||||||| FIN CLASE ARBOLES DE BUSQUEDA |||||||||||||||||||||


//DECLARACION DE FUNCIONES//
void mostrarLibrerias(Libreria lib);
void mostrarPedidos(Pedido ped);
Libreria genLibreria();
Pedido genPedido (string id_libreria);
void mostrarDatosLib(ArbolABB &ab, string id);
NodoArbol* crearNodoLib(Libreria lib);




#endif

