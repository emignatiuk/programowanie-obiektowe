#include <iostream>
#include <string>
#include <map>

class string_DNA {
private:
    std::string sekwencja;
    std::map<char, int> licznik_nt;

public:
    string_DNA(const std::string& seq) : sekwencja(seq) {
        licznik_nt['A'] = 0;
        licznik_nt['C'] = 0;
        licznik_nt['G'] = 0;
        licznik_nt['T'] = 0;
        countNukleotydy();
    }

    void countNukleotydy() {
        for (char nukleotyd : sekwencja) {
            if (licznik_nt.find(nukleotyd) != licznik_nt.end()) {
                licznik_nt[nukleotyd]++;
            }
        }
    }

    void printLiczniki() const {
        std::cout << licznik_nt.at('A') << " "
                  << licznik_nt.at('C') << " "
                  << licznik_nt.at('G') << " "
                  << licznik_nt.at('T') << std::endl;
    }
};

int main() {
    std::string dna = "";
    string_DNA dnastring(dna);
    dnastring.printLiczniki();
    return 0;
}
