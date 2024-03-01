#include <fstream>
#include <iterator>
#include <list>
#include <stack>
#include <iostream>
#include <string>
#include "comandos.h"

bool g_dicInit = false;
bool g_dicRevInit = false;


using std::list;
using std::string;
using namespace std;

  void dictionarys::addWord(string expression,dct &d) { // Recibe el índice, la palabra y el diccionario
    keyIt = d.begin();  // Iterador apunta al inicio del diccionario
    for (; keyIt != d.end();
         keyIt++) { // Recorre diccionario hasta que encuentra el indicie
      if (expression[0] == keyIt->key) { // Si la primera letra de la palabra coincide
                        // con la la llave del iterador
        Expr w(expression, 0); // Constructor de word, asigna la palabra y pone 0 al puntaje
        w.getPoints(); // Calcula el puntaje de la palabra y se lo asigna
        keyIt->value.push_back(w); // Añade la palabra a la lista de palabras de la keytemp
        ///std::cout <<"Palabra a agregar: " << w.word << std::endl;
      }
    }
  }

  bool dictionarys::verifyWord(string expression) { // Recibe la palabra a verificar
    for (char c : expression) {        // Recorre cada caracter de la palabra
      if (!std::isalpha(
              c)) { // Si no es alfanumerico decir que la palabra es mala
        return false;
      }
    }
    return true; // Si la palabra es válida se retorna true
  }

  string dictionarys::reverseWord(string expression) { // Recibe la palabra a invertir
    std::stack<char>
        rWord; // Crea una pila de caracteres para invertir la palabra
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

  void dictionarys::inicializar(string file_name) { // Inicializar, se le envía el nombre del archivo.txt
    //Verificar si ya hay uno inicializado
     if (g_dicInit) {
        std::cout << "\nEl diccionario ya ha sido inicializado.\n";
        return;
    }

    std::ifstream input_file( file_name); // Entrada de archivos va a ser el canal input_file y se le
                    // asigna archivo.txt
    string letters; // Crea una palabra
    string subKey;  // Crea una subLlave
    if (input_file.is_open()) { // Si el canal está abieto
      while (input_file >>
             letters) { // Mientras el archivo siga conteniendo palabras
        if (verifyWord(letters)) { // Verificar si la palabra es válida
          addWord(letters, dictio); // Si la palabra es válida, añadir la palabra
        }
      }
      input_file.close(); // Cuando acaba de leer el archivo se cierra
      std::cout<< "\nEl diccionario fue inicializado correctamente.\n";
      g_dicInit = true;
    } else {
      std::cout << "\nEl archivo "<<file_name<<" no existe o no puede ser leido.\n"; // Si no se pudo abrir el
                                                    // archivo muestra error
    }
  }

  void dictionarys::inicializar_reverso(string file_name) { // Mismo procedimiento anterior

    if (g_dicRevInit) {
        std::cout << "\nEl diccionario inverso ya ha sido inicializado.\n";
        return;
    }
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
    std::cout<< "\nEl diccionario inverso fue inicializado correctamente.\n";
    g_dicRevInit = true;

    } else {
    std::cout << "\nEl archivo "<<file_name<<" no existe o no puede ser leido.\n";
    }
  }

  void dictionarys::puntaje(string ww) { // recibe la palabra para calcular puntaje
    bool flag2 = false;
    if (!verifyWord(ww)) { // Verifica si la palabra no es válida
      std::cout << "\nLa palabra contiene simbolos invalidos \n";
      return;
    }
    int n;             // Contador
    bool flag = false; // Bandera

    keyIt = dictio.begin(); // Apuntador comienza en el diccionario normal
    for (; keyIt != dictio.end();
         keyIt++) { // Si encuentra la palabra marca la bandera como positiva
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
      std::cout << "\nLa palabra no existe en el diccionario. \n"; // Si no existe la palabra, avisa que
                                           // no se encuentra
    } else {
    std::cout << "\nLa palabra tiene un puntaje de: "<<n<<".\n";
    }
  }

  void dictionarys::imprimir(){
    keyIt = dictio.begin();
    for(; keyIt != dictio.end(); keyIt++){
        wordIt = keyIt->value.begin();
        for(; wordIt != keyIt->value.end(); wordIt++){
            std::cout << "key: " << keyIt->key << " , value: " << wordIt->word << ", puntaje:" <<wordIt->puntaje <<  std::endl;
        }
        std::cout << std::endl;
    }
  }

//Funciones
