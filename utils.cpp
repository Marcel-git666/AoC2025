#include "aoc.hpp"

// Try to find the first digit in the string and return the substring from there
static size_t find_first_digit(const std::string &s) {
    for (size_t i = 0; i < s.size(); ++i) {
        if (std::isdigit(static_cast<unsigned char>(s[i]))) return i;
    }
    return std::string::npos;
}

// Variant using std::stoi (throws exceptions on error)
// Returns true on success and writes the parsed value into `out`.
bool parse_numeric_suffix_stoi(const std::string &s, int &out) {
    size_t pos = find_first_digit(s);
    if (pos == std::string::npos) return false;
    std::string num = s.substr(pos);
    try {
        long value = std::stol(num);
        out = static_cast<int>(value);
        return true;
    } catch (const std::invalid_argument &) {
        return false;
    } catch (const std::out_of_range &) {
        return false;
    }
}

// Lightweight parser using C function strtol (widely available)
// Returns true on success and writes the parsed value into `out`.
bool parse_numeric_suffix_strtol(const std::string &s, int &out) {
    size_t pos = find_first_digit(s);
    if (pos == std::string::npos) return false;
    const char *begin = s.c_str() + pos;
    char *endptr = nullptr;
    errno = 0;
    long value = std::strtol(begin, &endptr, 10);
    if (begin == endptr) return false; // no conversion performed
    if (errno == ERANGE) return false; // out of range
    out = static_cast<int>(value);
    return true;
}

