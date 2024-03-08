#ifndef NODOGENERAL_H
#define NODOGENERAL_H

#include <list>

template <class T>
class NodoGeneral {
protected:
    T dato;
    std::list<NodoGeneral<T>*> desc;

public:
    NodoGeneral();
    ~NodoGeneral();
    T& obtenerDato();
    void fijarDato(T& val);
    void limpiarLista();
    void adicionarDesc(T& nval);
    void eliminarDesc(T& val);
};

#include "NodoGeneral.cpp"

#endif
