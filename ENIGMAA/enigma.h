#ifndef ENIGMA_H
#define ENIGMA_H

#include "rotor.h"
#include <string>

class Enigma {
private:
    Rotor rotor1, rotor2, rotor3;

public:
    bool carregarRotors();
    bool configurarPosicions(const std::string& finestres);
    std::string preProcessarText(const std::string& input);
    std::string xifrar(const std::string& text);
    std::string desxifrar(const std::string& text);
    void editarRotor(int n);
};

#endif