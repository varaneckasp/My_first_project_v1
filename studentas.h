#pragma once
#include <string>
#include <vector>
struct studentas{
    std::string vardas, pavarde;
    std::vector<int> pazymiai;
    int exam;
    double galutinis;
    double galutinis_mediana;
    };
class Studentas {
private:
    std::string vardas_;
    std::string pavarde_;
    std::vector<int> pazymiai_;
    int egzaminas_ = 0;
    double galutinis_ = 0.0;
    double galutinis_mediana_ = 0.0;

public:
    Studentas();
    ~Studentas();
};