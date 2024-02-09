#include <iostream>
#include "menu.h"

int main(){
    int opcion_menu = 0;
    while (opcion_menu!=4) {
        std::cout << "*****MENU*****" << std::endl;
        std::cout << "1. Configuracion del juego" << std::endl;
        std::cout << "2. Busqueda de palabras" << std::endl;
        std::cout << "3. Combinaciones de letras" << std::endl;
        std::cin >> opcion_menu;
        switch (opcion_menu) {
            case 1:
                configuracion_juego();
                break;
            case 2:
                busqueda_palabras();
                break;
            case 3:
                combinaciones_letras();
                break;
            case 4:
                exit(-1);
            default:
                std::cout << "La opcion es invalida." << std::endl;
        }
    }
}