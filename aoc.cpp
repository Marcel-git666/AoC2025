#include <iostream>
#include "Day01.hpp"
#include "Day02.hpp"
#include "Day03.hpp"

int main() {
    std::cout << "=== ADVENT OF CODE 2025 ===" << std::endl;

    // --- DAY 01 ---
    std::cout << "\n[Day 01]" << std::endl;
    Day01 day01;   
    day01.solve(); 

    
    std::cout << "\n[Day 02]" << std::endl;
    Day02 day02;
    day02.solve();

    std::cout << "\n[Day 03]" << std::endl;
    Day03 day03;
    day03.solve();

    return 0;
}