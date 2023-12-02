#include <_types/_uint8_t.h>
#include "Aoc.hpp"

#include <cctype>
#include <fstream>

namespace rng = std::ranges;

inline bool isDigit(char c) { return std::isdigit(c); }

inline uint8_t readLineValue(const std::string& line)
{
    auto firstResult = rng::find_if(line, isDigit);
    auto lastResult = rng::find_if(rng::reverse_view(line), isDigit);
    // Just assume they were found (i.e. no error checking)
    // Also, two digits can never be greater than 99 -> uint8_t is plenty
    // fmt::print("{}{}\n", *firstResult, *lastResult);
    return std::stoi(std::string(1, *firstResult) + *lastResult);
}

int main(int argc, char* argv[])
{
    CLI::App app{"AOC2023 DAY 1"};
    std::string inputFilepath;
    app.add_option("-i,--input", inputFilepath, "Input text file for day 1");
    CLI11_PARSE(app, argc, argv);

    // Try to open the file
    std::ifstream inputFile;
    inputFile.open(inputFilepath, std::ios::in);

    if(!inputFile.is_open()) {
        fmt::print(COLOR_RED, "Failed to open input file: {}\n", inputFilepath);
        return 1;
    }

    // Read the file line by line keeping track of calibration value
    uint64_t calibrationValue{0};
    std::string line;
    while(std::getline(inputFile, line)) calibrationValue += readLineValue(line);

    fmt::print(COLOR_GREEN, "Calibration Value is: {}\n", calibrationValue);
}