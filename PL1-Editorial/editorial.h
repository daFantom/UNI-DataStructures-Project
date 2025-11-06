#ifndef EDITORIAL_H_INCLUDED
#define EDITORIAL_H_INCLUDED

#include <iostream>
using namespace std;


// CONSTANTES
#define MAX_TITULOS 10
#define N_PEDIDOS_PASO 12
#define TAM_LOTE 10
#define LIBRERIAS 6
#define CAP_CAJA 5
// FIN CONSTANTES
using namespace std;

struct Pedido{
    int id_editorial;
    string id_pedido;
    string cod_libro;
    string materia;
    int cantidad;
    string estado;
};

struct pedido_stock{
    string codigo_libro;
    string materia;
    int unidades;
};

// CLASE NODO

class Nodo
{
private:
    Pedido valor;
    Nodo *siguiente;
    friend class Pila;
    friend class Cola;
public:
    Nodo(Pedido v, Nodo *sig = NULL)
    {
        valor = v;
        siguiente = sig;
    }
};
typedef Nodo *pNodo;

// LA CLASE COLA
class Cola
{
public:
    Cola() : frente(NULL), final(NULL) {}
    ~Cola();
    void encolar(Pedido v);
    Pedido desencolar();
    bool esVacia();
    int getLength();
    Pedido getFront();
private:
    pNodo frente, final;
};

// LA CLASE PILA
class Pila
{
private:
    pNodo cima;
public:
    Pila() : cima(NULL) {} //Constructor de la Pila
    ~Pila();
    void apilar(Pedido v);
    Pedido desapilar();
    bool esVacia();
    int getLength();
    string getTopCode();
};

Pedido genPedido(string,string);
void printQueue(Cola&);
void cambiarEstado(Pedido&,Cola&,Pila&);
void printQueue(Cola &c);
void printPile(Pila &p);
pedido_stock genStock(void);
int findInStock(Pedido, pedido_stock[]);
void mvItemsQueue(Cola &qIni, Cola &qAlma, Cola &qImpre, Cola &qListo, Pila cajas[], pedido_stock stock[]);
void printStock(pedido_stock arr[MAX_TITULOS]);
#endif // EDITORIAL_H_INCLUDED
