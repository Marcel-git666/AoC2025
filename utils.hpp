#ifndef UTILS_HPP
#define UTILS_HPP

#include <string>

bool parse_numeric_suffix_stoi(const std::string &s, int &out);
bool parse_numeric_suffix_strtol(const std::string &s, int &out);

#endif