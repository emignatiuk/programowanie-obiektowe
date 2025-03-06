
#include <iostream>
#include <string>
#include <unordered_map>

class ProteinTranslation {
private:
    std::string rna;
    std::unordered_map<std::string, char> kodony;

public:
    ProteinTranslation(const std::string& sekwencja_RNA) : rna(sekwencja_RNA) {
        initializeKodony();
    }

    void initializeKodony() {
        kodony = {
                {"AUG", 'M'}, {"UUU", 'F'}, {"UUC", 'F'}, {"UUA", 'L'}, {"UUG", 'L'},
                {"UCU", 'S'}, {"UCC", 'S'}, {"UCA", 'S'}, {"UCG", 'S'},
                {"UAU", 'Y'}, {"UAC", 'Y'}, {"UAA", '*'}, {"UAG", '*'},
                {"UGU", 'C'}, {"UGC", 'C'}, {"UGA", '*'}, {"UGG", 'W'},
                {"CUU", 'L'}, {"CUC", 'L'}, {"CUA", 'L'}, {"CUG", 'L'},
                {"CCU", 'P'}, {"CCC", 'P'}, {"CCA", 'P'}, {"CCG", 'P'},
                {"CAU", 'H'}, {"CAC", 'H'}, {"CAA", 'Q'}, {"CAG", 'Q'},
                {"CGU", 'R'}, {"CGC", 'R'}, {"CGA", 'R'}, {"CGG", 'R'},
                {"AUU", 'I'}, {"AUC", 'I'}, {"AUA", 'I'}, {"AAG", 'K'}, {"AAA", 'K'},
                {"ACU", 'T'}, {"ACC", 'T'}, {"ACA", 'T'}, {"ACG", 'T'},
                {"AGU", 'S'}, {"AGC", 'S'}, {"AGA", 'R'}, {"AGG", 'R'},
                {"GUU", 'V'}, {"GUC", 'V'}, {"GUA", 'V'}, {"GUG", 'V'},
                {"GCU", 'A'}, {"GCC", 'A'}, {"GCA", 'A'}, {"GCG", 'A'},
                {"GAU", 'D'}, {"GAC", 'D'}, {"GAA", 'E'}, {"GAG", 'E'},
                {"GGU", 'G'}, {"GGC", 'G'}, {"GGA", 'G'}, {"GGG", 'G'}
        };
    }

    std::string translate() {
        std::string białko;
        for (size_t i = 0; i < rna.length(); i += 3) {
            std::string codon = rna.substr(i, 3);
            if (kodony[codon] == '*') break;
            białko += kodony[codon];
        }
        return białko;
    }
};

int main() {
    std::string rna;
    std::cin >> rna;
    ProteinTranslation translator(rna);
    std::cout << translator.translate() << std::endl;
    return 0;
}