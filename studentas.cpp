#include "studentas.h"
#include <algorithm>

Studentas::Studentas()
    : egzaminas_(0),
      galutinis_(0.0),
      galutinis_mediana_(0.0) {
}

Studentas::~Studentas() {
}

Studentas::Studentas(std::istream& is) : Studentas() {
    if (!(is >> vardas_ >> pavarde_)) {
        return;
    }

    int pazymys;

    while (is >> pazymys) {
        pazymiai_.push_back(pazymys);
    }

    if (!pazymiai_.empty()) {
        egzaminas_ = pazymiai_.back();
        pazymiai_.pop_back();
    }
}
const std::string& Studentas::getVardas() const {
    return vardas_;
}
const std::string& Studentas::getPavarde() const {
    return pavarde_;
}
const std::vector<int>& Studentas::getPazymiai() const {
    return pazymiai_;
}
int Studentas::getEgzaminas() const {
    return egzaminas_;
}
double Studentas::getGalutinis() const {
    return galutinis_;
}
double Studentas::getGalutinisMediana() const {
    return galutinis_mediana_;
}
void Studentas::setVardas(const std::string& vardas) {
    vardas_ = vardas;
}
void Studentas::setPavarde(const std::string& pavarde) {
    pavarde_ = pavarde;
}
void Studentas::setPazymiai(const std::vector<int>& pazymiai) {
    pazymiai_ = pazymiai;
}
void Studentas::setEgzaminas(int egzaminas) {
    egzaminas_ = egzaminas;
}
void Studentas::skaiciuotiGalutini() {
    if (pazymiai_.empty()) {
        galutinis_ = 0;
        galutinis_mediana_ = 0;
        return;
    }

    double suma = 0;

    for (int pazymys : pazymiai_) {
        suma += pazymys;
    }

    double vidurkis = suma / pazymiai_.size();

    std::sort(pazymiai_.begin(), pazymiai_.end());

    double mediana;
    int n = pazymiai_.size();

    if (n % 2 == 0) {
        mediana = (pazymiai_[n / 2 - 1] +
                   pazymiai_[n / 2]) / 2.0;
    } else {
        mediana = pazymiai_[n / 2];
    }

    galutinis_ = 0.4 * vidurkis + 0.6 * egzaminas_;
    galutinis_mediana_ = 0.4 * mediana + 0.6 * egzaminas_;
}