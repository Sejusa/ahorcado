#pragma once
#include <string>

short aleatorio();
bool gestionRonda();
bool palabraRepetida(short numero);
std::string transformarAOculta(std::string palabra);
bool acierto(char input, short numero, std::string &palabraOculta, short &palabasRestantes);
bool usada(char input, std::string &palabraOculta);