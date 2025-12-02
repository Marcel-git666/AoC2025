#ifndef DAY01_HPP
#define DAY01_HPP

#include "Day.hpp"

// Dědíme z Day
class Day01 : public Day {
public:
    Day01(); // Konstruktor bez parametrů (název souboru dáme dovnitř)
    virtual ~Day01();

protected:
    // Implementace povinných metod
    virtual int part1();
    virtual int part2();

private:
    // Pomocné metody mohou být privátní metody třídy
    int processRLine(const std::string &line);
    int processLLine(const std::string &line);
};

#endif