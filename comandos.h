class dictionarys;

#ifndef UNTITLED_COMANDOS_H
#define UNTITLED_COMANDOS_H

#include <string>
#include <vector>
#include <fstream>
#include <iterator>
#include <list>
#include <stack>
#include <iostream>

using std::string;
using std::list;

//Añadir estructuras
struct Expr {
    std::string word;
    int puntaje;

    Expr(string exp, int n) : word(exp), puntaje(n) {}
    Expr(std::string exp) : word(exp) {}
    Expr(char c) : word(std::string(1, c)), puntaje(0) {}

    void getPoints() {
        // Recorre cada caracter de la palabra
        for (char c : word) {
            switch (std::toupper(c)) {
                case 'E':
                case 'A':
                case 'I':
                case 'O':
                case 'N':
                case 'R':
                case 'T':
                case 'L':
                case 'S':
                case 'U':
                    puntaje += 1;
                    break;
                case 'D':
                case 'G':
                    puntaje += 2;
                    break;
                case 'B':
                case 'C':
                case 'M':
                case 'P':
                    puntaje += 3;
                    break;
                case 'F':
                case 'H':
                case 'V':
                case 'W':
                case 'Y':
                    puntaje += 4;
                    break;
                case 'K':
                    puntaje += 5;
                    break;
                case 'J':
                case 'X':
                    puntaje += 8;
                    break;
                case 'Q':
                case 'Z':
                    puntaje += 10;
                    break;
            }
        }
    }
};

// Estructura de clave y valor
template <typename K, typename V> struct keyValue {
    K key;
    V value;

    keyValue(K key, V value) : key(key), value(value) {}
};

// Partes del diccionario para variables temporales o declaraciones
using keyTemp =keyValue<char, std::list<Expr>>; // declarar una clave y su lista de subclaves
using dct = std::list<keyTemp>; // un diccionario, que es una lista de claves y lista
// Iteradores del diccionario por partes
using keyIterator = dct::iterator; // Iterador de claves
using wordIterator = std::list<Expr>::iterator; // Iterador de palabras

// Clase diccionario para manejo de palabras - POSIBLE TADs
class dictionarys {
public:
    dct dictio;
    dct dictio_reverso;
    keyIterator keyIt;
    wordIterator wordIt;

    dictionarys() {
        for (char letter = 'a'; letter <= 'z'; letter++) {
            dictio.push_front(keyTemp(letter,{}));
            dictio_reverso.push_front(keyTemp(letter, {}));
        }
        for (char letter = 'A'; letter <= 'Z'; letter++) {
            dictio.push_front(keyTemp(letter,  {}));
            dictio_reverso.push_front(keyTemp(letter, {}));
        }
    }
    void inicializar(string file_name);
    void inicializar_reverso(string file_name);
    void puntaje(string ww);
    void imprimir();

    void addWord(string expression, dct &d);
    bool verifyWord(string expression);
    string reverseWord(string expression);
};

struct comandos_struct{
    std::string nombre;
    std::string descripcion;
    int n;
};

//Funciones Configuracion de juego
void inicializar(std::string parametro);
void iniciar_inverso(std::string parametro);
void puntaje(std::string parametro);

//Funciones Busqueda de palabras
void iniciar_arbol();
void iniciar_arbol_inverso();
void palabras_por_prefijo();
void palabras_por_sufijo();

//Funciones Combinaciones de letras
void grafo_de_palabras();
void posibles_palabras();

//Funciones_generales
void elegirFuncion(int n, std::string parametro);
bool verificarParametro(const std::string &entrada);
void seleccionarComandos(const std::string entrada, std::vector<comandos_struct> cmds, std::string parametro);
void ayudaCompleta(const std::string entrada, std::vector<comandos_struct> cmds);

#endif