#include "NodoGeneral.h"

template <class T>
NodoGeneral<T>::NodoGeneral() : dato() {}

template <class T>
NodoGeneral<T>::NodoGeneral() {
    limpiarLista();
}

template <class T>
T& NodoGeneral<T>::obtenerDato() {
    return dato;
}

template <class T>
void NodoGeneral<T>::fijarDato(T& val) {
    dato = val;
}

template <class T>
void NodoGeneral<T>::limpiarLista() {
    for (NodoGeneral<T>* nodo : desc) {
        delete nodo;
    }
    desc.clear();
}

template <class T>
void NodoGeneral<T>::adicionarDesc(T& nval) {
    desc.push_back(new NodoGeneral<T>(nval));
}

template <class T>
void NodoGeneral<T>::eliminarDesc(T& val) {
    for (auto it = desc.begin(); it != desc.end(); ++it) {
        if ((*it)->obtenerDato() == val) {
            delete *it;
            desc.erase(it);
            break;
        }
    }
}

NodoGeneral<int>;
NodoGeneral<std::string>;
