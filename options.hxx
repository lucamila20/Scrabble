#include <iostream>
#ifndef ENTREGA0ES_OPTIONS_HXX
#define ENTREGA0ES_OPTIONS_HXX

void configuracion_juego(){
    std:: string comando, aux;
    do {
        std::cout << "$";
        std::cin >> comando ;
        if(comando == "inicializar"){
            std:: cin >> aux;
            std:: cout << "Diccionario ya inicializado: El diccionario ya ha sido inicializado. "<< std::endl;
            std:: cout << "Archivo no existe: El archivo " << aux << " no existe o no puede ser leido. "<< std::endl;
            std:: cout << "Resultado exitoso: El diccionario se ha inicializado correctamente. "<< std::endl;
        }
        else if(comando == "iniciar_inverso"){
            std:: cin >> aux;
            std:: cout << "Diccionario ya inicializado: El diccionario inverso ya ha sido inicializado" << std:: endl;
            std:: cout << "Archivo no existe: El archivo " << aux << " no existe o no puede ser leído." << std:: endl;
            std:: cout << "Resultado exitoso: El diccionario inverso se ha inicializado correctamente." << std:: endl;
        }
        else if(comando == "puntaje") {
            std::cout << "Palabra no existe: La palabra no existe en el diccionario." << std::endl;
            std::cout << "Letras inválidas: La palabra contiene símbolos inválidos." << std::endl;
            std::cout << "Resultado exitoso: La palabra tiene un puntaje de puntaje " << std::endl;
        }else if (comando == "salir"){
            std::cout << "Saliendo..."<< std::endl;
        } else if(comando == "ayuda"){
            std:: cout << "inicializar" << std::endl;
            std:: cout << "iniciar_inverso" << std::endl;
            std:: cout << "puntaje" << std::endl;
        }else if(comando == "ayuda_comando"){
            std:: cout << "inicializar 'diccionario.txt'" << std::endl;
            std:: cout << "iniciar_inverso 'diccionario.txt'" << std::endl;
            std::cout << "puntaje 'palabra'" << std::endl;
        }
        else {
            std::cout << "Comando erroneo" << std::endl;
        }
    }while (comando != "salir");
}
void busqueda_palabras() {
    std:: string comando, aux;
    do {
        std::cout << "$";
        std::cin >> comando;

        if (comando == "iniciar_arbol") {
            std:: cin>> aux;
            std::cout << "Arbol ya inicializado: El arbol del diccionario ya ha sido inicializado."<< std::endl;
            std::cout << "Archivo no existe: El archivo " << aux << " no existe o no puede ser leido."<< std::endl;
            std::cout << "Resultado exitoso: El arbol del diccionario se ha inicializado correctamente."<< std::endl;
        }else if (comando == "iniciar_arbol_inverso") {
            std:: cin>> aux;
            std::cout << "Arbol ya inicializado: El arbol del diccionario inverso ya ha sido inicializado."<< std::endl;
            std::cout << "Archivo no existe: El archivo " << aux << " no existe o no puede ser leido."<< std::endl;
            std::cout << "Resultado exitoso: El arbol del diccionario inverso se ha inicializado correctamente."<< std::endl;
        }else if (comando == "palabras_por_prefijo") {
            std:: cin>> aux;
            std::cout << "Prefijo invalido: Prefijo " << aux << " no pudo encontrarse en el diccionario."<< std::endl;
            std::cout << "Resultado exitoso: Las palabras que inician con este prefijo son:"<< std::endl;
        }else if (comando == "palabras_por_sufijo") {
            std:: cin>> aux;
            std::cout << "Sufijo invalido: Sufijo " << aux << " no pudo encontrarse en el diccionario."<< std::endl;
            std::cout << "Resultado exitoso: Las palabras que terminan con este sufijo son:"<< std::endl;
        }else if (comando == "ayuda"){
            std::cout << "iniciar_arbol"<< std::endl;
            std::cout << "iniciar_arbol_inverso"<< std::endl;
            std::cout << "palabras_por_prefijo"<< std::endl;
            std::cout << "palabras_por_sufijo"<< std::endl;
            std::cout << "ayuda_comando";
        }else if (comando == "ayuda_comando"){
            std::cout << "iniciar_arbol 'diccionario.txt'"<< std::endl;
            std::cout << "iniciar_arbol_inverso 'diccionario.txt'"<< std::endl;
            std::cout << "palabras_por_prefijo 'prefijo'"<< std::endl;
            std::cout << "palabras_por_sufijo 'sufijo'"<< std::endl;
        }else if (comando == "salir"){
            std::cout << "Saliendo..."<< std::endl;
        }else {
            std::cout << "Comando erroneo" << std::endl;
        }
    }while (comando != "salir");
}
void combinaciones_letras() {

    std::string comando,aux;

    do {
        std::cout << "$";
        std::cin >> comando;

        if (comando == "grafo_de_palabras") {
            std::cout<<"Resultado exitoso: Grafo construido correctamente."<< std::endl;
        }else if (comando == "posibles_palabras"){
            std:: cin>> aux;
            std::cout << "Letras invalidas: La cadena " << aux << " contiene simbolos invalidos."<< std::endl;
            std::cout << "Resultado exitoso: Las posibles palabras a construir con las letras " << aux << " son"<< std::endl;
        }else if (comando == "ayuda") {
            std::cout << "grafo_de_palabras"<< std::endl;
            std::cout << "posibles_palabras"<< std::endl;
        }else if (comando == "ayuda_comando"){
            std::cout << "grafo_de_palabras" << std::endl;
            std::cout << "posibles_palabras 'letras'" << std::endl;
        }else if (comando == "salir"){
            std::cout << "Saliendo..."<< std::endl;
        }else{
            std::cout << "Comando erroneo"<< std::endl;
        }
    }while (comando != "salir");
}

#endif //ENTREGA0ES_OPTIONS_HXX
