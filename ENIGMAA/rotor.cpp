#include "rotor.h"
#include <fstream>
#include <algorithm>
#include <iostream>

Rotor::Rotor() : notch('Z'), offset(0) {}

bool Rotor::carregarDesDeFitxer(const std::string& nomFitxer) {
    std::ifstream file(nomFitxer);
    if (!file.is_open()) {
        std::cerr << "[ERROR] No es pot obrir " << nomFitxer << "\n";
        return false;
    }

    std::getline(file, wiring);
    std::string notchLine;
    std::getline(file, notchLine);

    if (wiring.length() != 26 || !wiringValid()) {
        std::cerr << "[ERROR] " << nomFitxer << ": permutació incorrecta — calen 26 lletres úniques A–Z\n";
        return false;
    }

    notch = notchLine.empty() ? 'Z' : notchLine[0];
    calcularReverse();
    return true;
}

bool Rotor::guardarAFitxer(const std::string& nomFitxer) {
    std::ofstream file(nomFitxer);
    if (!file.is_open()) return false;
    file << wiring << "\n" << notch << "\n";
    return true;
}

bool Rotor::wiringValid() const {
    std::string temp = wiring;
    std::sort(temp.begin(), temp.end());
    return std::unique(temp.begin(), temp.end()) == temp.end();
}

void Rotor::calcularReverse() {
    reverseWiring = std::string(26, 'A');
    for (int i = 0; i < 26; ++i) {
        reverseWiring[wiring[i] - 'A'] = 'A' + i;
    }
}

void Rotor::inicialitzarOffset(char lletra) {
    offset = lletra - 'A';
}

bool Rotor::avanzar() {
    offset = (offset + 1) % 26;
    return ('A' + offset) == notch;
}

char Rotor::xifrarEndavant(char lletra) {
    int pos = (lletra - 'A' + offset) % 26;
    char substitut = wiring[pos];
    return (substitut - offset + 26) % 26 + 'A';
}

char Rotor::xifrarEnrere(char lletra) {
    int pos = (lletra - 'A' + offset + 26) % 26;
    char substitut = reverseWiring[pos];
    return (substitut - offset + 26) % 26 + 'A';
}