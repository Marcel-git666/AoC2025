#ifndef DAY01_HPP
#define DAY01_HPP

#include "Day.hpp"

class Day01 : public Day {
public:
    Day01(); 
    virtual ~Day01();

protected:
    virtual int part1();
    virtual int part2();

private:
    int processRLine(const std::string &line);
    int processLLine(const std::string &line);
};

#endif