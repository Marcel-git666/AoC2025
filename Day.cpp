#include "Day.hpp"

Day::Day(const std::string& filename) {
    std::ifstream in(filename.c_str());
    if (!in.is_open()) {
        std::cerr << "Error: Could not open file " << filename << std::endl;
        exit(1); 
    }

    std::string line;
    while (std::getline(in, line)) {
        _lines.push_back(line);
    }
}

Day::~Day() {
}

void Day::solve() {
    std::cout << "--- Part 1 ---" << std::endl;
    int p1 = this->part1();
    std::cout << "Result: " << p1 << std::endl;

    std::cout << "--- Part 2 ---" << std::endl;
    int p2 = this->part2();
    std::cout << "Result: " << p2 << std::endl;
}