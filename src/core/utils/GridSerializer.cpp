#include "GridSerializer.h"
#include <sstream>
#include <string>
#include <iostream>

std::vector<std::vector<int>> GridSerializer::load(const std::string &lines, int &rows, int &cols) {
    rows = 0;
    cols = 0;

    std::stringstream header(lines);
    if (!(header >> rows >> cols) || rows <= 0 || cols <= 0) {
        rows = 0;
        cols = 0;
        return {};
    }

    std::vector<std::vector<int>> grid(rows, std::vector<int>(cols, 0));
    bool incomplete = false;

    // Reparse ligne par ligne pour éviter de "déborder" d'une ligne sur l'autre.
    std::stringstream content(lines);
    std::string line;

    // Saut de la première ligne (header déjà lu)
    std::getline(content, line);

    for (int r = 0; r < rows; r++) {
        if (!std::getline(content, line)) {
            incomplete = true;
            continue;
        }

        std::istringstream rowStream(line);
        for (int c = 0; c < cols; c++) {
            int value;
            if (rowStream >> value) {
                grid[r][c] = value;
            } else {
                // Manque des valeurs sur la ligne : compléter par 0 et signaler.
                incomplete = true;
                grid[r][c] = 0;
            }
        }
    }

    (void)incomplete; // on ignore l'avertissement pour éviter le bruit console

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
