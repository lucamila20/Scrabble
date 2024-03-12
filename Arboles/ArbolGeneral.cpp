#include <iostream>

template <class T>
NodoGeneral<T>::NodoGeneral(T val) : valor(val), primerHijo(nullptr), siguienteHermano(nullptr) {}

template <class T>
NodoGeneral<T>::NodoGeneral() {
    delete primerHijo;
    delete siguienteHermano;
}

template <class T>
NodoGeneral<T>* ArbolGeneral<T>::buscarNodo(T& valor, NodoGeneral<T>* nodo) const {
    if (nodo == nullptr) return nullptr;
    if (nodo->valor == valor) return nodo;

    NodoGeneral<T>* resultado = buscarNodo(valor, nodo->primerHijo);
    if (resultado) return resultado;

    return buscarNodo(valor, nodo->siguienteHermano);
}

template <class T>
ArbolGeneral<T>::ArbolGeneral() : raiz(nullptr) {}

template <class T>
ArbolGeneral<T>::ArbolGeneral(T& val) : raiz(new NodoGeneral<T>(val)) {}

template <class T>
ArbolGeneral<T>::ArbolGeneral() {
    delete raiz;
}

template <class T>
bool ArbolGeneral<T>::esVacio() const {
    return raiz == nullptr;
}

template <class T>
NodoGeneral<T>* ArbolGeneral<T>::obtenerRaiz() const {
    return raiz;
}

template <class T>
void ArbolGeneral<T>::fijarRaiz(NodoGeneral<T>* nraiz) {
    if (raiz != nraiz) {
        delete raiz;
        raiz = nraiz;
    }
}

template <class T>
bool ArbolGeneral<T>::insertarNodo(T& padre, T& n) {
    if (raiz == nullptr) {
        if (padre == n) {
            raiz = new NodoGeneral<T>(n);
            return true;
        }
        return false;
    }

    NodoGeneral<T>* nodoPadre = buscarNodo(padre, raiz);
    if (!nodoPadre) return false;

    NodoGeneral<T>* nuevoNodo = new NodoGeneral<T>(n);
    if (!nodoPadre->primerHijo) {
        nodoPadre->primerHijo = nuevoNodo;
    } else {
        NodoGeneral<T>* actual = nodoPadre->primerHijo;
        while (actual->siguienteHermano) {
            actual = actual->siguienteHermano;
        }
        actual->siguienteHermano = nuevoNodo;
    }

    return true;
}

 ArbolGeneral<int>;
 ArbolGeneral<std::string>;
