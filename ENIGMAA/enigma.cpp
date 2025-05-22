#include "enigma.h"
#include <iostream>
#include <fstream>
#include <cctype>
#include <algorithm>
#include <set>

bool Enigma::carregarRotors() {
    return rotor1.carregarDesDeFitxer("Rotor1.txt") &&
           rotor2.carregarDesDeFitxer("Rotor2.txt") &&
           rotor3.carregarDesDeFitxer("Rotor3.txt");
}

bool Enigma::configurarPosicions(const std::string& finestres) {
    if (finestres.size() != 3) {
        std::cout << "[ERROR] Calen 3 lletres per configurar les finestres\n";
        return false;
    }
    rotor1.inicialitzarOffset(finestres[0]);
    rotor2.inicialitzarOffset(finestres[1]);
    rotor3.inicialitzarOffset(finestres[2]);
    return true;
}

std::string Enigma::preProcessarText(const std::string& input) {
    std::string net;
    for (char c : input) {
        if (std::isalpha(c)) net += std::toupper(c);
    }
    return net;
}

std::string Enigma::xifrar(const std::string& text) {
    std::string net = preProcessarText(text);
    std::string resultat;
    int comptador = 0;

    for (char c : net) {
        bool salt2 = rotor1.avanzar();
        bool salt3 = false;
        if (salt2) salt3 = rotor2.avanzar();
        if (salt3) rotor3.avanzar();

        char x = rotor1.xifrarEndavant(c);
        x = rotor2.xifrarEndavant(x);
        x = rotor3.xifrarEndavant(x);
        resultat += x;

        comptador++;
        if (comptador % 5 == 0) resultat += ' ';
    }

    return resultat;
}

std::string Enigma::desxifrar(const std::string& text) {
    std::string net = preProcessarText(text);
    std::string resultat;

    for (char c : net) {
        bool salt2 = rotor1.avanzar();
        bool salt3 = false;
        if (salt2) salt3 = rotor2.avanzar();
        if (salt3) rotor3.avanzar();

        char x = rotor3.xifrarEnrere(c);
        x = rotor2.xifrarEnrere(x);
        x = rotor1.xifrarEnrere(x);
        resultat += x;
    }

    return resultat;
}

void Enigma::editarRotor(int n) {
    std::cin.ignore();
    std::string wiringNou;
    char notchNou;

    std::cout << "Introdueix una nova permutació de 26 lletres (A-Z):\n";
    std::getline(std::cin, wiringNou);
    std::cout << "Lletra notch (enter per defecte Z): ";
    std::string notchInput;
    std::getline(std::cin, notchInput);
    notchNou = notchInput.empty() ? 'Z' : std::toupper(notchInput[0]);

    if (wiringNou.size() != 26) {
        std::cout << "[ERROR] La permutació ha de tenir 26 lletres.\n";
        return;
    }
    std::set<char> lletres(wiringNou.begin(), wiringNou.end());
    if (lletres.size() != 26 || !std::all_of(wiringNou.begin(), wiringNou.end(), ::isupper)) {
        std::cout << "[ERROR] La permutació ha de tenir 26 lletres úniques en majúscules.\n";
        return;
    }

    std::ofstream file;
    std::string nomFitxer = "Rotor" + std::to_string(n) + ".txt";
    file.open(nomFitxer);
    if (!file.is_open()) {
        std::cout << "[ERROR] No es pot escriure al fitxer " << nomFitxer << "\n";
        return;
    }
    file << wiringNou << "\n" << notchNou << "\n";
    file.close();
    std::cout << "[OK] Rotor actualitzat correctament a " << nomFitxer << "\n";
}