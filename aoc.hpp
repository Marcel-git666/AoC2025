#ifndef AOC_HPP
#define AOC_HPP
#include <iostream>
#include <string>
#include <fstream>
#include <cerrno>
#include <cstdlib>
bool parse_numeric_suffix_stoi(const std::string &s, int &out);
bool parse_numeric_suffix_strtol(const std::string &s, int &out);

int day01Part1();
int day01Part2();


#endif // AOC_HPP