#pragma once
#include "studentas.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <list>
#include <iomanip>
#include <cstddef>
bool palygintiVardus(const studentas &a, const studentas &b);
bool palygintiPavardes(const studentas &a, const studentas &b);
bool palygintiGalutinius(const studentas &a, const studentas &b);
void atsitiktinis_sarasas(const std::string &failo_pavadinimas, int studentu_skaicius);
void skaiciuotiGalutini(studentas& A);
template <typename T>
bool skaitytiFaila (const std::string &failo_pavadinimas, T &grupe) {
    std::ifstream fd(failo_pavadinimas);
        if (!fd.is_open()) {
            std::cout << "Nepavyko atidaryti failo!" << std::endl;
            return false;
        }
        std::string eilute;
        std::getline(fd, eilute);
        std::stringstream ss;
        while(std::getline(fd,eilute)) {
            ss.clear();
            ss.str(eilute);
            studentas A;
            ss >> A.vardas >> A.pavarde;
            int pazymys;
            while (ss >> pazymys) {
                A.pazymiai.push_back(pazymys);
            }
                if(A.pazymiai.size() < 2){
                    continue;
                }
                A.exam = A.pazymiai.back();
                A.pazymiai.pop_back();
                skaiciuotiGalutini(A);
                grupe.push_back(A);
               
        }
         return true;
    }
    template <typename T>
bool skaitytiFailaKlase(const std::string& failo_pavadinimas, T& grupe) {
    std::ifstream fd(failo_pavadinimas);

    if (!fd.is_open()) {
        std::cout << "Nepavyko atidaryti failo!\n";
        return false;
    }

    std::string eilute;
    std::getline(fd, eilute);

    while (std::getline(fd, eilute)) {
        std::stringstream ss(eilute);

        Studentas A(ss);

        if (A.getVardas().empty() ||
            A.getPavarde().empty() ||
            A.getPazymiai().empty()) {
            continue;
        }

        grupe.push_back(A);
    }

    return true;
}
template <typename T>
void skirstytiStudentus(const T&grupe, T&vargsiukai, T&kietiakai, int vertinimo_pasirinkimas){
        for (const Studentas& A : grupe) {
            if (vertinimo_pasirinkimas == 1) {
                if (A.getGalutinisMediana() < 5) {
                    vargsiukai.push_back(A);
                } else {
                    kietiakai.push_back(A);
                }
            } else if (vertinimo_pasirinkimas == 2) {
                if (A.getGalutinis() < 5) {
                    vargsiukai.push_back(A);
                } else {
                    kietiakai.push_back(A);
                }
            } else {
                std::cout << "Neteisingas pasirinkimas!\n";
                return;
            }
        }
    }
template <typename T>
void skirstytiStudentus2(T&grupe, T&vargsiukai, int vertinimo_pasirinkimas){
    auto it = grupe.begin();
        while(it != grupe.end()) {
            bool arVargsiukas;
            if (vertinimo_pasirinkimas == 1) {
                arVargsiukas = (it->getGalutinisMediana() < 5);
            } else if (vertinimo_pasirinkimas == 2) {
                arVargsiukas = (it->getGalutinis() < 5);
            } else {
                std::cout << "Neteisingas pasirinkimas!\n";
                return;
            }
            if (arVargsiukas) {
                vargsiukai.push_back(*it);
                it = grupe.erase(it);
            } else {
                ++it;
            }
        }
}
void skirstytiStudentus3(std::vector<studentas>& grupe,std::vector<studentas>& vargsiukai,int vertinimo_pasirinkimas);
void skirstytiStudentus3(std::list<studentas>& grupe,std::list<studentas>& vargsiukai,int vertinimo_pasirinkimas);
void skirstytiStudentus3(
    std::vector<Studentas>& grupe,
    std::vector<Studentas>& vargsiukai,
    int vertinimo_pasirinkimas
);

void skirstytiStudentus3(
    std::list<Studentas>& grupe,
    std::list<Studentas>& vargsiukai,
    int vertinimo_pasirinkimas
);
void rusiuotiStudentus(std::vector<studentas> &grupe, int rusiuoti_pasirinkimas);
void rusiuotiStudentus(std::list<studentas> &grupe, int rusiuoti_pasirinkimas);
void rusiuotiStudentus(std::vector<Studentas>& grupe, int rusiuoti_pasirinkimas);
void rusiuotiStudentus(std::list<Studentas>& grupe, int rusiuoti_pasirinkimas);
template <typename T>
bool rasytiFailus(const T& vargsiukai, const T& kietiakai, int vertinimo_pasirinkimas) {
        std::ofstream failas_vargsiukai("vargsiukai.txt");
        std::ofstream failas_kietiakai("kietiakai.txt");
        if (!failas_vargsiukai.is_open() || !failas_kietiakai.is_open()) {
            std::cout << "Nepavyko sukurti failo!" << std::endl;
            return false;
        }

        failas_vargsiukai << std::left << std::setw(20) << "Vardas" << std::setw(20) << "Pavarde" << std::setw(20);
        failas_kietiakai << std::left << std::setw(20) << "Vardas" << std::setw(20) << "Pavarde" << std::setw(20);

        if (vertinimo_pasirinkimas == 1) {
            failas_vargsiukai << std::setw(20) << "Galutinis (med.)"<< '\n';
            failas_kietiakai << std::setw(20) << "Galutinis (med.)"<< '\n';
        } else {
            failas_vargsiukai << std::setw(20) << "Galutinis (vid.)"<< '\n';
            failas_kietiakai << std::setw(20) << "Galutinis (vid.)"<< '\n';
        }

        for (const studentas& A : vargsiukai) {
            failas_vargsiukai << std::left << std::setw(20) << A.vardas << std::setw(20) << A.pavarde;
            if (vertinimo_pasirinkimas == 1) {
                failas_vargsiukai << std::setw(20) <<std::fixed << std::setprecision(2) << A.galutinis_mediana << '\n';
            } else {
                failas_vargsiukai << std::setw(20) << std::fixed << std::setprecision(2) << A.galutinis << '\n';
            }
        }

        for (const studentas& A : kietiakai) {
            failas_kietiakai << std::left << std::setw(20) << A.vardas << std::setw(20) << A.pavarde;
            if (vertinimo_pasirinkimas == 1) {
                failas_kietiakai << std::setw(20) <<std::fixed << std::setprecision(2) << A.galutinis_mediana << '\n';
            } else {
                failas_kietiakai << std::setw(20) << std::fixed << std::setprecision(2) << A.galutinis << '\n';
            }
        }
        failas_vargsiukai.flush();
        failas_kietiakai.flush();
        return failas_vargsiukai.good() && failas_kietiakai.good();
    }
    template <typename T>
    bool rasytiFailusKlase(const T& vargsiukai,const T& kietiakai,int vertinimo_pasirinkimas) {
    std::ofstream fv("vargsiukai.txt");
    std::ofstream fk("kietiakai.txt");

    if (!fv || !fk) {
        std::cout << "Nepavyko atidaryti rezultatu failu!\n";
        return false;
    }

    auto irasytiGrupe = [vertinimo_pasirinkimas](
        std::ofstream& failas,
        const T& grupe
    ) {
        failas << std::left
               << std::setw(20) << "Vardas"
               << std::setw(20) << "Pavarde"
               << "Galutinis\n";

        for (const Studentas& A : grupe) {
            double balas = (vertinimo_pasirinkimas == 1)
                ? A.getGalutinisMediana()
                : A.getGalutinis();

            failas << std::left
                   << std::setw(20) << A.getVardas()
                   << std::setw(20) << A.getPavarde()
                   << std::fixed << std::setprecision(2)
                   << balas << '\n';
        }
    };

    irasytiGrupe(fv, vargsiukai);
    irasytiGrupe(fk, kietiakai);

    fv.flush();
    fk.flush();

    return fv.good() && fk.good();
}
    void rezervuotiVieta(std::vector<studentas>& grupe, size_t kiekis);
    void rezervuotiVieta(std::list<studentas>& grupe, size_t kiekis);
    inline void rezervuotiVieta(std::vector<Studentas>& grupe, size_t kiekis) {
    grupe.reserve(kiekis);
}

inline void rezervuotiVieta(std::list<Studentas>& grupe, size_t kiekis) {
}
