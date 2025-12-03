#ifndef DAY_HPP
#define DAY_HPP

#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <cstdlib> // for exit()

class Day
{
public:
    explicit Day(const std::string &filename);

    virtual ~Day() = default;
    Day(const Day &) = delete;
    Day(Day &&) = delete;
    Day &operator=(const Day &) = delete;
    Day &operator=(Day &&) = delete;
    void solve();

protected:
    std::vector<std::string> lines_;

    virtual int part1() = 0;
    virtual int part2() = 0;
};

#endif