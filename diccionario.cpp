#include <fstream>
#include <iostream>
#include <list>
#include <stack>
#include <string>

using std::list;
using std::string;

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
using keyTemp =keyValue<char, list<Expr>>; // declarar una clave y su lista de subclaves
using dct = list<keyTemp>; // un diccionario, que es una lista de claves y lista
// Iteradores del diccionario por partes
using keyIterator = dct::iterator; // Iterador de claves
using wordIterator = list<Expr>::iterator; // Iterador de palabras

// Clase diccionario para manejo de palabras - POSIBLE TAD
class dictionarys {
    // atributos
private:
    dct dictio;
    dct dictio_reverso;
    keyIterator keyIt;
    wordIterator wordIt;
    // Constructor
    dictionarys() {
        for (char letter = 'a'; letter <= 'z'; letter++) {
            dictio.push_front(keyTemp(letter, {"", {}}));
            dictio_reverso.push_front(keyTemp(letter, {"", {}}));
        }
        for (char letter = 'A'; letter <= 'Z'; letter++) {
            dictio.push_front(keyTemp(letter, {"", {}}));
            dictio_reverso.push_front(keyTemp(letter, {"", {}}));
        }
    }
    void addWord(string expression,dct d) { // Recibe el índice, la palabra y el diccionario
        keyIt = d.begin();  // Iterador apunta al inicio del diccionario
        for (; keyIt != d.end();
               keyIt++) { // Recorre diccionario hasta que encuentra el indicie
            if (expression[0] ==keyIt->key) { // Si la primera letra de la palabra coincide
                // con la la llave del iterador
                Expr w(expression,0); // Constructor de word, asigna la palabra y pone 0 al puntaje
                w.getPoints(); // Calcula el puntaje de la palabra y se lo asigna
                keyIt->value.push_back(w); // Añade la palabra a la lista de palabras de la keytemp
            }
        }
    }

    bool verifyWord(string expression) { // Recibe la palabra a verificar
        for (char c : expression) {        // Recorre cada caracter de la palabra
            if (!std::isalpha(c)) { // Si no es alfanumerico es decir que la palabra es mala
                return false;
            }
        }
        return true; // Si la palabra es válida se retorna true
    }

    string reverseWord(string expression) { // Recibe la palabra a invertir
        std::stack<char>rWord; // Crea una pila de caracteres para invertir la palabra
        for (char c : expression) // Recorre cada letra de la palabra
            rWord.push(c);          // Añade cada letra a la pila
        string reverse = "";      // String base para recibir la palabra
        while (!rWord.empty()) {  // Recorre la pila hasta que se acabe
            reverse += rWord.top(); // Al sacar las cosas de la pila invierte el orden
            // y lo guarda en reverse
            rWord.pop();            // Letra que guarda la saca
        }
        return reverse; // Retorna la palabra invertida
    }

    // Metodos/Comportamiento
public:
    void inicializar(
            string file_name) { // Inicializar, se le envía el nombre del archivo.txt
        std::ifstream input_file(file_name); // Entrada de archivos va a ser el canal input_file y se le
        // asigna archivo.txt
        string letters; // Crea una palabra
        string subKey;  // Crea una subLlave
        if (input_file.is_open()) { // Si el canal está abieto
            while (input_file >>letters) { // Mientras el archivo siga conteniendo palabras
                if (verifyWord(letters)) { // Verificar si la palabra es válida
                    addWord(letters,dictio); // Si la palabra es válida, añadir la palabra
                }
            }
            input_file.close(); // Cuando acaba de leer el archivo se cierra
        } else {
            std::cout << "no se pudo abrir el archivo\n"; // Si no se pudo abrir el
            // archivo muestra error
        }
    }

    void inicializar_reverso(string file_name) { // Mismo procedimiento anterior
        std::ifstream input_file(file_name);
        string exp;
        string subKey;
        if (input_file.is_open()) {
            while (input_file >> exp) {
                if (verifyWord(exp)) {
                    exp = reverseWord(exp); // Invierte la palabra antes de añadirla
                    addWord(exp, dictio_reverso);
                }
            }
            input_file.close();
        } else {
            std::cout << "no se pudo abrir el archivo\n";
        }
    }

    void puntaje(string ww) { // recibe la palabra para calcular puntaje

        if (!verifyWord(ww)) { // Verifica si la palabra no es válida
            std::cout << "Letras inválidas \n";
        }
        int n;             // Contador
        bool flag = false; // Bandera

        keyIt = dictio.begin(); // Apuntador comienza en el diccionario normal
        for (; keyIt != dictio.end();keyIt++) { // Si encuentra la palabra marca la bandera como positiva
            wordIt = keyIt->value.begin();
            for (; wordIt != keyIt->value.end(); wordIt++) {
                if (ww == wordIt->word) {
                    n = wordIt->puntaje;
                    flag = true;
                }
            }
        }
        keyIt = dictio_reverso.begin();
        for (; keyIt != dictio_reverso.end(); keyIt++) { // Lo mismo pero la inversa
            wordIt = keyIt->value.begin();
            for (; wordIt != keyIt->value.end(); wordIt++) {
                if (ww == wordIt->word) {
                    n = wordIt->puntaje;
                    flag = true;
                    break;
                }
            }
        }

        if (!flag) {
            std::cout << "Palabra no existe \n"; // Si no existe la palabra, avisa que
            // no se encuentra
        } else {
            std::cout << "\n puntaje: " << n << "\n"; // Imprime el puntaje de la palabra
            std::cout << "Resultado Exitoso \n";
        }
    }
};