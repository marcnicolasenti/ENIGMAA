#ifndef ROTOR_H
#define ROTOR_H

#include <string>

class Rotor {
private:
    std::string wiring;
    std::string reverseWiring;
    char notch;
    int offset;

    void calcularReverse();

public:
    Rotor();
    bool carregarDesDeFitxer(const std::string& nomFitxer);
    bool guardarAFitxer(const std::string& nomFitxer);
    bool wiringValid() const;
    void inicialitzarOffset(char lletra);
    char xifrarEndavant(char lletra);
    char xifrarEnrere(char lletra);
    bool avanzar();
};

#endif