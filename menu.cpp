#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include "comandos.h"

using namespace std;
dictionarys diccionarios;

void elegirFuncion(int n, string parametro){

    switch(n) {
        //Configuración
        case 1:
            diccionarios.inicializar(parametro);
            //diccionarios.imprimir();
            break;
        case 2:
            diccionarios.inicializar_reverso(parametro);
            break;
            //Búsqueda
        case 3:
            diccionarios.puntaje(parametro);
            break;
        case 4:
            iniciar_arbol();
            break;
        case 5:
            iniciar_arbol_inverso();
            break;
        case 6:
            palabras_por_prefijo();
            break;
        case 7:
            palabras_por_sufijo();
            break;
        case 8:
            grafo_de_palabras();
            break;
        case 9:
            posibles_palabras();
            break;
    }

}


bool verificarParametro(const string& entrada) {

    istringstream stream(entrada);
    string palabra1, palabra2;

    // Intentar extraer dos palabras del flujo
    if (stream >> palabra1 && stream >> palabra2 && stream.eof()) {
        //cout<<"Correcto Formato \n";
        return true;
    }else {
        cout<<"\nError en la entrada. El comando esta mal escrito y/o le hace falta un parametro.\n";
        return false;
    }
}


void seleccionarComandos(const string entrada, vector<comandos_struct> cmds, string parametro){

    if(entrada == "grafo_de_palabras"){
        elegirFuncion(8, parametro);
        return;
    }
    if(entrada.find("ayuda")!=string::npos){
        elegirFuncion(0, parametro);
        return;
    }

    size_t posicionEspacio = entrada.find(' ');

    if(verificarParametro(entrada)){
        std::string comando = entrada.substr(0 , posicionEspacio);
        int i = 1;
        bool aux=false;
        for(comandos_struct &v : cmds){
            if (v.nombre == comando){
                elegirFuncion(i, parametro);
                aux=true;
                return;
            }
            i++;
        }
        if(!aux){
            cout<<"\nError en la entrada. El comando esta mal escrito y/o le hace falta un parametro.\n";
        }

    }


}

void ayudaCompleta(const string entrada, const vector<comandos_struct> cmds) {

    if(entrada == "ayuda") {
        cout<<"\nLos comandos disponibles dentro del programa son:\n\n";
        for(size_t i = 0; i < cmds.size(); ++i) {
            cout << i+1 << ". " << cmds[i].nombre << "\n";
        }
        cout<<"\n";
    } else {
        string comandoBuscado = entrada.substr(6);
        bool encontrado = false;
        for(const comandos_struct& o : cmds) {
            if(o.nombre == comandoBuscado) {
                cout << o.descripcion << endl;
                encontrado = true;
                break;
            }
        }
        if(!encontrado) {
            cout<< "\nNo se encontro el comando especificado\n";
        }
    }
}