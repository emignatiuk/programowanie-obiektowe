#include <iostream>
#include <vector>
#include <unordered_map>
#include <cmath>
#include <iomanip>

class ProteinProcessor {
private:
    std::unordered_map<char, double> massTable;

public:
    ProteinProcessor() {
        initializeMassTable();
    }

    void initializeMassTable() {
        massTable = {
                {'A', 71.03711}, {'C', 103.00919}, {'D', 115.02694}, {'E', 129.04259},
                {'F', 147.06841}, {'G', 57.02146}, {'H', 137.05891}, {'I', 113.08406},
                {'K', 128.09496}, {'L', 113.08406}, {'M', 131.04049}, {'N', 114.04293},
                {'P', 97.05276},  {'Q', 128.05858}, {'R', 156.10111}, {'S', 87.03203},
                {'T', 101.04768}, {'V', 99.06841},  {'W', 186.07931}, {'Y', 163.06333}
        };
    }

    double calculateWeight(const std::string& białko) {
        double totalWeight = 0.0;
        for (char aminokwas : białko) {
            totalWeight += massTable[aminokwas];
        }
        return totalWeight;
    }
};

int main() {
    ProteinProcessor processor;
    std::string białko;
    std::cin >> białko;
    std::cout << std::fixed << std::setprecision(3) << processor.calculateWeight(białko) << std::endl;
    return 0;
}
