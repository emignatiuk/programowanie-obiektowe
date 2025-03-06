#include <iostream>
#include <string>

class string_RNA {
private:
    std::string sekwencja;

public:
    string_RNA(const std::string& dna) {
        sekwencja = dna;
        for (char& nukleotyd : sekwencja) {
            if (nukleotyd == 'T') {
                nukleotyd = 'U'; // Zamiana tyminy (T) na uracyl (U)
            }
        }
    }

    void printRNA() const {
        std::cout << sekwencja << std::endl;
    }
};

int main() {
    std::string dna = "";
    string_RNA rnastring(dna);
    rnastring.printRNA();
    return 0;
}
