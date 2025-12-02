#ifndef DAY_HPP
#define DAY_HPP

#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <cstdlib> // for exit()

class Day {
public:
    Day(const std::string& filename);
    
    virtual ~Day();

    void solve();

protected:
    std::vector<std::string> _lines;


    virtual int part1() = 0;
    virtual int part2() = 0;
};

#endif