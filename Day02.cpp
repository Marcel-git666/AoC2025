#include "Day02.hpp"
#include "utils.hpp"
#include <iostream>
#include <sstream>

Day02::Day02() : Day("day02.input")
{
}

int Day02::part1()
{
    long long result = 0;
    std::stringstream ss(lines_[0]);
    std::string segment;
    while (std::getline(ss, segment, ','))
    {
        size_t dashPos = segment.find('-');

        if (dashPos != std::string::npos)
        {
            std::string startStr = segment.substr(0, dashPos);
            std::string endStr = segment.substr(dashPos + 1);
            long long start = std::stoll(startStr);
            long long end = std::stoll(endStr);

            for (long long i = start; i <= end; ++i)
            {
                std::string s = std::to_string(i);
                if (s.length() % 2 != 0)
                    continue;
                int halfLen = s.length() / 2;
                std::string firstHalf = s.substr(0, halfLen);
                std::string secondHalf = s.substr(halfLen);
                if (firstHalf == secondHalf)
                {
                    // std::cout << "Found invalid ID: " << s << std::endl;
                    result += i;
                }
            }
        }
    }
    std::cout << result << std::endl;
    return 0;
}

int Day02::part2()
{
    long long result = 0;
    std::stringstream ss(lines_[0]);
    std::string segment;
    while (std::getline(ss, segment, ','))
    {
        size_t dashPos = segment.find('-');

        if (dashPos != std::string::npos)
        {
            std::string startStr = segment.substr(0, dashPos);
            std::string endStr = segment.substr(dashPos + 1);
            long long start = std::stoll(startStr);
            long long end = std::stoll(endStr);

            for (long long i = start; i <= end; ++i)
            {
                std::string s = std::to_string(i);
                int l = s.length();
                int patternLen = 1;
                while (patternLen <= l / 2)
                {
                    if (l % patternLen == 0)
                    {
                        std::string pattern = s.substr(0, patternLen);
                        bool allMatch = true;
                        for (int pos = patternLen; pos < l; pos += patternLen)
                        {
                            if (s.substr(pos, patternLen) != pattern)
                            {
                                allMatch = false;
                                break;
                            }
                        }
                        if (allMatch)
                        {
                            // std::cout << "Found invalid ID: " << s << std::endl;
                            result += i;
                            break;
                        }
                    }
                    patternLen++;
                }
            }
        }
    }
    std::cout << result << std::endl;
    return 0;
}