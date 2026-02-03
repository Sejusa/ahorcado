#include <vector>
#include <string>
#include "datos.h"
#include <iostream>

std::vector <std::string> palabras = { "hola", "bombero", "auxiliar", "planta", "peso", "robo", "albacete", "segunda", "copa", "rey" };

short aleatorio() {
	short numero = rand() % palabras.size(); //Dará un numero aleatorio del 0 al tamaño del vector palabras.

	return numero;
}

bool palabraRepetida(short numero) {
	if (palabras[numero] == valorRepetido) { //Si la palabra se encuentra repetida (ya que hay el valor valorRepetido en vez de una palabra).
		return true;
	}

	else {
		return false;
	}
}

std::string transformarAOculta(std::string palabra) {
	for (short i = valorInicial; i < palabra.size(); i++) {
		palabra[i] = valorOculto; //valorOculto debe de ser un char ya que estamos transformando un char de palabra a valorOculto.
	}

	return palabra;
}

bool acierto(char input, short numero, std::string &palabraOculta, short &palabasRestantes) {
	bool encontrado = false;

	for (short i = valorInicial; i < palabras[numero].size(); i++) { //Recorremos cada carácter de la palabra que toca.
		if (input == palabras[numero][i]) { //Si encontramos al menos una letra que coincida con el input.
			palabraOculta[i] = input; //Cambio el char actual por el del input.
			palabasRestantes--; //Cada vez que encuentre una palabra restante le restará uno.
			encontrado = true;
		}
	}

	if (encontrado == true) {
		return true;
	}

	else {
		return false;
	}
}

bool usada(char input, std::string &palabraOculta) {
	bool encontrado = false;

	for (short i = valorInicial; i < palabraOculta.size(); i++) { //Si encontramos una letra en vez de el símbolo valorOculto.
		if (input == palabraOculta[i]) {
			encontrado = true;
		}
	}

	if (encontrado == true) {
		return true;
	}

	else {
		return false;
	}
}

bool gestionRonda() {
	bool repetida = true; //Supondremos que está repetida para ejecutar el bucle while al menos una vez.
	short numero = valorInicial; //La inicializamos para que no dé problemas.

	while (repetida == true) {
		numero = aleatorio();
		repetida = palabraRepetida(numero);
	}

	std::string palabraOculta = transformarAOculta(palabras[numero]);

	std::cout << palabraOculta << std::endl;
	std::cout << palabras[numero] << std::endl; //Se muestra a modo de debug.

	short vida = vidaJugador;
	short palabrasRestantes = palabras[numero].size();

	while (vida > valorInicial && palabrasRestantes > valorInicial) {
		char input;

		std::cout << "\nEscriba UNA letra: ";
		std::cin >> input;

		input = tolower(input); //Transformamos a minúsculas.

		bool repetida = usada(input, palabraOculta);
		bool correcta = acierto(input, numero, palabraOculta, palabrasRestantes);

		std::cout << palabraOculta << std::endl;

		if (correcta == true && repetida == false) { //Si acierta y no se ha dicho ya.
			std::cout << "Letra acertada! Vidas: " << vida << ". Letras restantes: " << palabrasRestantes << std::endl;
		}

		else if (correcta == true && repetida == true) { //Si acierta pero ya se ha dicho.
			std::cout << "Ya has dicho esta letra. Vidas: " << vida << ". Letras restantes: " << palabrasRestantes << std::endl;
		}

		else { //Si falla.
			vida--;
			std::cout << "Has fallado! Vidas: " << vida << ". Letras restantes: " << palabrasRestantes << std::endl;
		}
	}

	palabras[numero] = valorRepetido; //Le asignamos este valor para que el algoritmo sepa que ya se ha usado.

	if (vida > valorInicial && palabrasRestantes == valorInicial) { //Si no has perdido todas las vidas y has acertado todas las palabras.
		return true;
	}

	else {
		return false;
	}
}