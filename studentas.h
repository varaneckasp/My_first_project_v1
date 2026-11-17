#pragma once
#include <string>
#include <vector>
#include <istream>
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
    Studentas(const Studentas&) = default;
    Studentas& operator=(const Studentas&) = default;
    Studentas(Studentas&&)  noexcept= default;
    Studentas& operator=(Studentas&&) noexcept = default;
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