#pragma once
#include <string>
#include <vector>
#include <istream>
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
    explicit Studentas(std::istream& is);
    const std::string& getVardas() const;
    const std::string& getPavarde() const;
    const std::vector<int>& getPazymiai() const;
    int getEgzaminas() const;
    double getGalutinis() const;
    double getGalutinisMediana() const;
    void setVardas(const std::string& vardas);
    void setPavarde(const std::string& pavarde);
    void setPazymiai(const std::vector<int>& pazymiai);
    void setEgzaminas(int egzaminas);
    void skaiciuotiGalutini();
};