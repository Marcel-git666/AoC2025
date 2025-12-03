#include "Day.hpp"

Day::Day(const std::string &filename)
{
    std::ifstream in(filename);
    if (!in.is_open())
    {
        std::cerr << "Error: Could not open file " << filename << std::endl;
        exit(1);
    }

    std::string line;
    while (std::getline(in, line))
    {
        lines_.push_back(line);
    }
}

void Day::solve()
{
    std::cout << "--- Part 1 ---" << std::endl;
    std::cout << "Result: " << part1() << std::endl;

    std::cout << "--- Part 2 ---" << std::endl;
    std::cout << "Result: " << part2() << std::endl;
}