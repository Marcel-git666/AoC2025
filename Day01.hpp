#ifndef DAY01_HPP
#define DAY01_HPP

#include "Day.hpp"

class Day01 : public Day {
public:
    Day01(); 
    
protected:
    int part1() override;
    int part2() override;

private:
    int getRotationAmount(const std::string &line);
};

#endif