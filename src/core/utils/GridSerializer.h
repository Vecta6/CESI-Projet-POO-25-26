#pragma once
#include <string>

class GridSerializer {
public:
    static bool load(const std::string &path, int &rows, int &cols);
    static std::string dump(const std::string &path, int &rows, int &cols);

};
