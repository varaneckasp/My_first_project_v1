#include "funkcijos.h"
#include <algorithm>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <iomanip>
#include <cstdlib>

bool palygintiVardusKlase(const Studentas& a, const Studentas& b);
bool palygintiPavardesKlase(const Studentas& a, const Studentas& b);
bool palygintiGalutiniusKlase(const Studentas& a, const Studentas& b);
void atsitiktinis_sarasas(const std::string &failo_pavadinimas, int studentu_skaicius) {
    std::ofstream fd(failo_pavadinimas);
    if (!fd.is_open()) {
        std::cout << "Nepavyko sukurti failo!" << std::endl;
        return;
    }
    fd<< std::left << std::setw(20) << "Vardas" << std::setw(20) << "Pavarde";
    for (int i = 1; i <= 15; i++) {
        fd << std::setw(10) << ("ND" + std::to_string(i));
    }
    fd << std::setw(10) << "Egz." << std::endl;
    for (int i = 0; i < studentu_skaicius; i++) {
        std::string vardas = "Vardas" + std::to_string(i + 1);
        std::string pavarde = "Pavarde" + std::to_string(i + 1);
        fd << std::left << std::setw(20) << vardas << std::setw(20) << pavarde;
        for (int j = 0; j < 15; j++) {
            int pazymys = rand() % 10 + 1;
            fd << std::setw(10) << pazymys;
        }
        int egzaminas = rand() % 10 + 1;
        fd << std::setw(10) << egzaminas << '\n';
    }
    fd.close();
}
void skirstytiStudentus3(std::vector<Studentas>& grupe,std::vector<Studentas>& vargsiukai,int vertinimo_pasirinkimas) {
    auto riba = std::partition(
        grupe.begin(), grupe.end(),
        [vertinimo_pasirinkimas](const Studentas& A) {
            if (vertinimo_pasirinkimas == 1) {
                return A.getGalutinisMediana() >= 5;
            } else {
                return A.getGalutinis() >= 5;
            }
        }
    );

    vargsiukai.insert(vargsiukai.end(), riba, grupe.end());
    grupe.erase(riba, grupe.end());
}
void skirstytiStudentus3(std::list<Studentas>& grupe,std::list<Studentas>& vargsiukai,int vertinimo_pasirinkimas) {
    auto it = grupe.begin();
        while(it != grupe.end()) {
        bool arVargsiukas;
            if (vertinimo_pasirinkimas == 1) {
                arVargsiukas = (it->getGalutinisMediana() < 5);
            }
            else {
                arVargsiukas = (it->getGalutinis() < 5);
            }
            if (arVargsiukas) {
                auto dabartinis = it++;
                vargsiukai.splice(vargsiukai.end(), grupe, dabartinis);
            } 
            else {
                ++it;
            }
    }
}
void rusiuotiStudentus(std::vector<Studentas>& grupe, int rusiuoti_pasirinkimas) {
    if (rusiuoti_pasirinkimas == 1) {
        std::sort(grupe.begin(), grupe.end(), palygintiVardusKlase);
    }
    else if (rusiuoti_pasirinkimas == 2) {
        std::sort(grupe.begin(), grupe.end(), palygintiPavardesKlase);
    }
    else if (rusiuoti_pasirinkimas == 3) {
        std::sort(grupe.begin(), grupe.end(), palygintiGalutiniusKlase);
    }
    else {
        std::cout << "Neteisingas pasirinkimas!\n";
    }
}
void rusiuotiStudentus(std::list<Studentas>& grupe, int rusiuoti_pasirinkimas) {
    if (rusiuoti_pasirinkimas == 1) {
        grupe.sort(palygintiVardusKlase);
    }
    else if (rusiuoti_pasirinkimas == 2) {
        grupe.sort(palygintiPavardesKlase);
    }
    else if (rusiuoti_pasirinkimas == 3) {
        grupe.sort(palygintiGalutiniusKlase);
    }
    else {
        std::cout << "Neteisingas pasirinkimas!\n";
    }
}
bool palygintiVardusKlase(const Studentas &a, const Studentas &b) {
    return a.getVardas() < b.getVardas();
}
bool palygintiPavardesKlase(const Studentas &a, const Studentas &b) {
    return a.getPavarde() < b.getPavarde();
}
bool palygintiGalutiniusKlase(const Studentas &a, const Studentas &b) {
    return a.getGalutinis() < b.getGalutinis();
}