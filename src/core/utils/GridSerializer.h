#pragma once
#include <string>
#include <vector>

class GridSerializer {
public:
    // Parse a grid from a string buffer; returns rows/cols by reference.
    static std::vector<std::vector<int>> load(const std::string &lines, int &rows, int &cols);
    // Serialize a grid into the text format expected by the project.
    static std::string dump(const std::vector<std::vector<int>> &grid, int &rows, int &cols);

};
