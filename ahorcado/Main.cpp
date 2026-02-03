#include "Ronda.h"
#include <ctime> //Para time().
#include "datos.h"
#include <iostream>

int main() {
	bool fin = false;
	short rondasGanadas = valorInicial;
	short ronda = rondaInicial;

	srand(time(NULL)); //Generamos una semilla aleatoria.

	while (fin == false) {
		bool victoria = gestionRonda();

		if (victoria == true) { //Si ha ganado dos rondas.
			rondasGanadas++;
		}

		if (rondasGanadas == victoriasMinimas) { 
			std::cout << "Has ganado!" << std::endl;
			fin = true;
		}

		else if (rondasGanadas == valorInicial && ronda == victoriasMinimas) { //Si pierde las dos primeras rondas de forma consecutiva. 
			std::cout << "Has perdido las dos primeras rondas consecutivas, ya no puedes ganar!" << std::endl;
			fin = true;
		}

		else if (rondasGanadas < victoriasMinimas && ronda == rondaFinal) { //Si llega a la tercera ronda y no ha ganado el mínimo de victorias necesarias.
			std::cout << "Has llegado a la tercera ronda y no has conseguido el mínimo de victorias. Has perdido!" << std::endl;
			fin = true;
		}

		else {
			ronda++;
		}
	}

	return 0;
}