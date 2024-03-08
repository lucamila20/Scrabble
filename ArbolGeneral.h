#ifndef ARBOLGENERAL_H
#define ARBOLGENERAL_H

template <class T>
class NodoGeneral {
public:
    T valor;
    NodoGeneral<T>* primerHijo;
    NodoGeneral<T>* siguienteHermano;

    NodoGeneral(T val);
    NodoGeneral();
};

template <class T>
class ArbolGeneral {
protected:
    NodoGeneral<T>* raiz;

    NodoGeneral<T>* buscarNodo(T& valor, NodoGeneral<T>* nodo) const;

public:
    ArbolGeneral();
    ArbolGeneral(T& val);
    ~ArbolGeneral();

    bool esVacio() const;
    NodoGeneral<T>* obtenerRaiz() const;
    void fijarRaiz(NodoGeneral<T>* nraiz);

    bool insertarNodo(T& padre, T& n);
};

#include "ArbolGeneral.cpp"

#endif
