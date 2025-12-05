#include "Day03.hpp"
#include "utils.hpp"
#include <iostream>
#include <sstream>

Day03::Day03() : Day("day03.input")
{
}

int getJolts(const std::string &line)
{
    int maxJoltage = 0;
    for (unsigned int i = 0; i < line.size(); i++) {
        for (unsigned int j = i + 1; j < line.size(); j++) {
            int joltage = 10 * (line[i] - '0');
            joltage += (line[j] - '0');
            if (joltage > maxJoltage) {
                maxJoltage = joltage;
            }
        }
    }
    
    return maxJoltage;
}

int Day03::part1()
{
    int jolts = 0;
    for (unsigned long i = 0; i < lines_.size(); ++i)
    {
        jolts += getJolts(lines_[i]);
    }
    return jolts;
}

std::string getHugeJolts(const std::string &line)
{
    std::string bankJoltage = "";
    int startIndex = 0;
    int lineLength = static_cast<int>(line.size());
    for (int k = 12; k > 0; k--) {
        char candidate = line[startIndex];
        for (int i = startIndex; i <= lineLength - k; i++) {
            if (line[i] > candidate) {
                candidate = line[i];
                startIndex = i;
            }
        }
        startIndex++;
        bankJoltage += candidate;
    }
    std::cout << bankJoltage << std::endl;
    return bankJoltage;
}

int Day03::part2()
{
    long long jolts = 0;
    for (unsigned long i = 0; i < lines_.size(); ++i)
    {
        jolts += strtoll(getHugeJolts(lines_[i]).c_str(), nullptr, 10);
    }
    std::cout << jolts << std::endl;
    return 0;
}