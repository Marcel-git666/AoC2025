#include "Day02.hpp"
#include "utils.hpp"
#include <iostream>

Day02::Day02() : Day("day02.input") {
}

Day02::~Day02() {
}



int Day01::part1() {
    int result = 0;
    int currentDial = 50;

    for (size_t i = 0; i < _lines.size(); ++i) {
        const std::string& line = _lines[i];

        if (line.empty()) continue; 

        if (line[0] == 'R') {
            int dialNumber = processRLine(line);
            currentDial += dialNumber;
            currentDial %= 100;
            if (currentDial == 0) {
                result++;
            }
        } else {
            int dialNumber = processLLine(line);
            while (currentDial - dialNumber < 0) {
                currentDial += 100;
            }
            currentDial -= dialNumber;
            if (currentDial == 0) {
                result++;
            }
        }
    }
    return result;
}

int Day01::part2() {
    int result = 0;
    int currentDial = 50;

    for (size_t i = 0; i < _lines.size(); ++i) {
        const std::string& line = _lines[i];

        if (line.empty()) continue;

        if (line[0] == 'R') {
            int amount = processRLine(line);
            if (currentDial + amount >= 100) {
                result += ((currentDial + amount) / 100);
            }
            
            currentDial = (currentDial + amount) % 100;

        } else {
            int amount = processLLine(line);        
            int distanceToFirstZero = (currentDial == 0) ? 100 : currentDial;

            if (amount >= distanceToFirstZero) {
                result++; 
                
                int remainingAmount = amount - distanceToFirstZero;
                result += (remainingAmount / 100);
            }

            currentDial = (currentDial - amount) % 100;
            if (currentDial < 0) {
                currentDial += 100;
            }
        }
    }
    return result;
}