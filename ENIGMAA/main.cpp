#include "enigma.h"
#include <iostream>
#include <fstream>

int main() {
    Enigma maquina;
    int opcio;

    while (true) {
        std::cout << "\nENIGMA:\n-------------------------------\n";
        std::cout << "1. Xifrar missatge\n2. Desxifrar missatge\n3. Editar rotors\n4. Sortir\nOpció: ";
        std::cin >> opcio;

        if (opcio == 1 || opcio == 2) {
            std::string finestres;
            std::cout << "Introdueix finestra inicial (ex. ABC): ";
            std::cin >> finestres;
            maquina.configurarPosicions(finestres);

            if (!maquina.carregarRotors()) continue;

            std::ifstream arxiuEntrada((opcio == 1) ? "Missatge.txt" : "xifrat.txt");
            std::ofstream arxiuSortida((opcio == 1) ? "xifrat.txt" : "desxifrat.txt");

            if (!arxiuEntrada.is_open() || !arxiuSortida.is_open()) {
                std::cout << "[ERROR] No es pot obrir el fitxer d'entrada o sortida.\n";
                continue;
            }

            std::string missatge((std::istreambuf_iterator<char>(arxiuEntrada)), std::istreambuf_iterator<char>());
            std::string resultat = (opcio == 1) ? maquina.xifrar(missatge) : maquina.desxifrar(missatge);

            arxiuSortida << resultat;
            std::cout << "[OK] Missatge " << ((opcio == 1) ? "xifrat" : "desxifrat") << " correctament.\n";
        } 
        else if (opcio == 3) {
            int rotorNum;
            std::cout << "Quin rotor vols editar? (1, 2 o 3): ";
            std::cin >> rotorNum;
            maquina.editarRotor(rotorNum);
        } 
        else if (opcio == 4) {
            break;
        } 
        else {
            std::cout << "Opció invàlida.\n";
        }
    }
    return 0;
}