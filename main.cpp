#include <iostream>
#include "menu.h"

int main(){
    int opcion_menu = 0;
    while (opcion_menu!=4) {
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