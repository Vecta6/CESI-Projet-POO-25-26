#include "GridSerializer.h"
#include <sstream>

std::vector<std::vector<int>> GridSerializer::load(const std::string &lines, int &rows, int &cols) {
    rows = 0;
    cols = 0;

    std::stringstream ss(lines);
    if (!(ss >> rows >> cols) || rows <= 0 || cols <= 0) {
        rows = 0;
        cols = 0;
        return {};
    }

    std::vector<std::vector<int>> grid(rows, std::vector<int>(cols, 0));
    for (int r = 0; r < rows; r++) {
        for (int c = 0; c < cols; c++) {
            int value;
            if (!(ss >> value)) {
                // Invalid or incomplete payload; signal failure with empty grid.
                rows = 0;
                cols = 0;
                return {};
            }
            grid[r][c] = value;
        }
    }

    return grid;
}



std::string GridSerializer::dump(const std::vector<std::vector<int>> &lines, int &rows, int &cols) {
    rows = static_cast<int>(lines.size());
    cols = rows > 0 ? static_cast<int>(lines[0].size()) : 0;

    std::stringstream ss;
    ss << rows << " " << cols;

    for (const auto &row : lines) {
        ss << "\n";
        for (std::size_t c = 0; c < row.size(); ++c) {
            if (c > 0) ss << " ";
            ss << row[c];
        }
    }

    return ss.str();
}
