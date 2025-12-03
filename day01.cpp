#include "Day01.hpp"
#include "utils.hpp"
#include <iostream>

Day01::Day01() : Day("day01.input")
{
}

int Day01::getRotationAmount(const std::string &line)
{
    int value = 0;
    // Předpokládám, že parse funkce ignoruje počáteční písmena a hledá první číslici
    if (!parse_numeric_suffix_strtol(line, value))
    {
        std::cerr << "Warning: no numeric value found in line: " << line << std::endl;
    }
    return value;
}

int Day01::part1()
{
    int result = 0;
    int currentDial = 50;

    for (size_t i = 0; i < lines_.size(); ++i)
    {
        const std::string &line = lines_[i];

        if (line.empty())
            continue;
        int dialNumber = getRotationAmount(line);
        if (line[0] == 'R')
        {
            currentDial += dialNumber;
            currentDial %= 100;
            if (currentDial == 0)
            {
                result++;
            }
        }
        else
        {
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
    return result;
}

int Day01::part2()
{
    int result = 0;
    int currentDial = 50;

    for (size_t i = 0; i < lines_.size(); ++i)
    {
        const std::string &line = lines_[i];

        if (line.empty())
            continue;

        if (line[0] == 'R')
        {
            int amount = getRotationAmount(line);
            if (currentDial + amount >= 100)
            {
                result += ((currentDial + amount) / 100);
            }

            currentDial = (currentDial + amount) % 100;
        }
        else
        {
            int amount = getRotationAmount(line);
            int distanceToFirstZero = (currentDial == 0) ? 100 : currentDial;

            if (amount >= distanceToFirstZero)
            {
                result++;

                int remainingAmount = amount - distanceToFirstZero;
                result += (remainingAmount / 100);
            }

            currentDial = (currentDial - amount) % 100;
            if (currentDial < 0)
            {
                currentDial += 100;
            }
        }
    }
    return result;
}