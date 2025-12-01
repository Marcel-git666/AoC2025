#include "aoc.hpp"

int processRLine(const std::string &line)
{
    // Placeholder for processing lines that start with 'R'
    int rValue = 0;
    if (parse_numeric_suffix_strtol(line, rValue))
    {
        // std::cout << "  extracted R value: " << rValue << std::endl;
    }
    else
    {
        std::cout << "  no numeric suffix found for R line" << std::endl;
    }
    return rValue;
}

int processLLine(const std::string &line)
{
    // Placeholder for processing lines that start with 'L'
    int lValue = 0;
    if (parse_numeric_suffix_strtol(line, lValue))
    {
    }
    else
    {
        std::cout << "  no numeric suffix found for L line" << std::endl;
    }
    return lValue;
}

int day01Part1()
{
    int result = 0;
    int currentDial = 50;
    const std::string filename = "input.task";
    std::ifstream in(filename);
    if (!in.is_open())
    {
        std::cerr << "Failed to open file: " << filename << std::endl;
        return 1;
    }

    std::string line;
    while (std::getline(in, line))
    {
        if (line[0] == 'R')
        {
            int dialNumber = processRLine(line);
            currentDial += dialNumber;
            currentDial %= 100;
            if (currentDial == 0)
            {
                result++;
            }
        }
        else
        {
            int dialNumber = processLLine(line);
            while (currentDial - dialNumber < 0)
            {
                currentDial += 100;
            }
            currentDial -= dialNumber;
            if (currentDial == 0)
            {
                result++;
            }
        }
    }
    if (in.bad())
    {
        std::cerr << "I/O error while reading file." << std::endl;
        return 2;
    }
    std::cout << "Day01 part 1: " << result << std::endl;
    return 0;
}

int day01Part2()
{
    int result = 0;
    int currentDial = 50;
    const std::string filename = "input.task";
    std::ifstream in(filename);
    if (!in.is_open())
    {
        std::cerr << "Failed to open file: " << filename << std::endl;
        return 1;
    }

    std::string line;
    while (std::getline(in, line))
    {
        if (line[0] == 'R')
        {
            int amount = processRLine(line);
            if (currentDial + amount >= 100)
            {
                result += ((currentDial + amount) / 100);
            }
            currentDial = (currentDial + amount) % 100;
        }
        else
        {
            int amount = processLLine(line);
            int distanceToFirstZero = (currentDial == 0) ? 100 : currentDial;
            if (amount >= distanceToFirstZero)
            {
                result++;
                int remainingAmount = amount - distanceToFirstZero;
                result += (remainingAmount / 100);
            }
            currentDial = (currentDial - amount) % 100;
            if (currentDial < 0)
                currentDial += 100;
        }
    }
    if (in.bad())
    {
        std::cerr << "I/O error while reading file." << std::endl;
        return 2;
    }
    std::cout << "Day01 part 2 result: " << result << std::endl;
    return 0;
}