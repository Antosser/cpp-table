#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <tuple>

class Table
{
    private:
    std::vector<std::vector<std::string>> m_Data;

    public:
    Table(): m_Data(std::vector<std::vector<std::string>>())
    {

    }

    std::vector<std::string> operator[](int index)
    {
        return m_Data[index];
    }

    std::string operator[](std::tuple<int, int> indexes)
    {
        return m_Data[std::get<0>(indexes)][std::get<1>(indexes)];
    }

    void addRow(std::vector<std::string> row)
    {
        m_Data.push_back(row);
    }

    bool isValid() {
        if (m_Data.size() == 0)
            return false;
        for (int i = 0; i < m_Data.size(); i++) {
            if (m_Data[i].size() != m_Data[0].size())
                return false;
        }
        return true;
    }

    void print_ASCII(bool eqalSize = false) {
        std::vector<int> widths;
        int maxWidth = 0;

        // Widths
        for (int i = 0; i < m_Data.size(); i++)
        {
            for (int j = 0; j < m_Data[i].size(); j++)
            {
                if (widths.size() <= j)
                {
                    widths.push_back(m_Data[i][j].size());
                    if (m_Data[i][j].size() > maxWidth)
                    {
                        maxWidth = m_Data[i][j].size();
                    }
                }
                else if (widths[j] < m_Data[i][j].size())
                {
                    widths[j] = m_Data[i][j].size();
                }
            }
        }

        // Rows
        for (int i = 0; i < m_Data.size(); i++)
        {   
            // Pluses
            for (int j = 0; j < m_Data[0].size(); j++)
            {
                std::cout << '+' << std::string((eqalSize ? maxWidth : widths[j]) + 2, '-');
            }
            std::cout << '+' << std::endl;

            // Cells
            for (int j = 0; j < m_Data[i].size(); j++)
            {
                std::cout << "| " << m_Data[i][j] << std::string((eqalSize ? maxWidth : widths[j]) - m_Data[i][j].size(), ' ') << ' ';
            }
            std::cout << '|' << std::endl;
        }

        // Pluses
        for (int j = 0; j < m_Data[0].size(); j++)
        {
            std::cout << '+' << std::string((eqalSize ? maxWidth : widths[j]) + 2, '-');
        }
        std::cout << '+' << std::endl;
    }
    std::string toCSV() const {
        std::string csv = "";
        for (int i = 0; i < m_Data.size(); i++) {
            for (int j = 0; j < m_Data[i].size(); j++) {
                csv += m_Data[i][j];
                if (j != m_Data[i].size() - 1)
                    csv += ",";
            }
            if (i != m_Data.size() - 1)
                csv += "\n";
        }
        return csv;
    }
    std::string toHTML() const {
        std::string html = "<table>\n";
        for (int i = 0; i < m_Data.size(); i++) {
            html += "<tr>\n";
            for (int j = 0; j < m_Data[i].size(); j++) {
                html += "<td>" + m_Data[i][j] + "</td>\n";
            }
            html += "</tr>\n";
        }
        html += "</table>\n";
        return html;
    }
    std::string toJSON() const {
        std::string json = "{\n";
        for (int i = 0; i < m_Data.size(); i++) {
            json += "\"" + m_Data[i][0] + "\": ";
            json += "\"" + m_Data[i][1] + "\"";
            if (i != m_Data.size() - 1)
                json += ",\n";
        }
        json += "\n}";
        return json;
    }
    void saveCSV(std::string path) const {
        std::ofstream file;
        file.open(path);
        file << toCSV();
        file.close();
    }
    void loadCSV(std::string path) {
        std::ifstream file(path);
        std::string line;
        while (std::getline(file, line)) {
            std::vector<std::string> row;
            std::stringstream lineStream(line);
            std::string cell;
            while (std::getline(lineStream, cell, ',')) {
                row.push_back(cell);
            }
            m_Data.push_back(row);
        }
        file.close();
    }
    void clear() {
        m_Data.clear();
    }
    void saveHTML(std::string path) const {
        std::ofstream file;
        file.open(path);
        file << toHTML();
        file.close();
    }
};

int main()
{
    Table t;
    t.addRow({"a", "b", "c"});
    t.addRow({"d", "e", "f"});
    t.addRow({"g", "h", "i"});
    t.print_ASCII();
}