#include <iostream>
#include <string>
#include <algorithm>

class ReverseComplementDNA {
private:
    std::string sekwencja;

public:
    ReverseComplementDNA(const std::string& dna) {
        sekwencja = dna;
        std::reverse(sekwencja.begin(), sekwencja.end());
        for (char& nukleotyd : sekwencja) {
            switch (nukleotyd) {
                case 'A': nukleotyd = 'T'; break;
                case 'T': nukleotyd = 'A'; break;
                case 'C': nukleotyd = 'G'; break;
                case 'G': nukleotyd = 'C'; break;
            }
        }
    }

    void printReverseComplement() const {
        std::cout << sekwencja << std::endl;
    }
};

int main() {
    std::string dna;
    std::cin >> dna;
    ReverseComplementDNA reverseComplement(dna);
    reverseComplement.printReverseComplement();
    return 0;
}
