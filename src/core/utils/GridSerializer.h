#pragma once
#include <string>
#include <vector>

class GridSerializer {
public:
    static std::vector<std::vector<int>> load(const std::string &lines, int &rows, int &cols);
    static std::string dump(const std::vector<std::vector<int>> &grid, int &rows, int &cols);

};
