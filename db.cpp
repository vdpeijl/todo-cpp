#include <iostream>
#include <map>
#include <fstream>
#include "db.hpp"

Database::Database(const std::string name, const std::vector<std::string> fields, const std::string delimiter) {
  m_field_names = fields;
  m_file_name = name;
  m_delimiter = delimiter;
  read_file();
}

std::vector<std::string> Database::read_file_line(std::string line) {
  std::vector<std::string> columns;

  for (size_t i = 0; i < m_field_names.size(); i++) {
    size_t next_pos = line.find(m_delimiter);
    std::string column = line.substr(0, next_pos);
    columns.push_back(column);

    if (line.length()) {
      line.erase(0, next_pos + m_delimiter.length());
    }
  }

  return columns;
}

void Database::read_file() {
  std::ifstream file(m_file_name);
  std::string line;

  if (!file.is_open()) {
    std::cerr << "Could not open the file!" << std::endl;
  }

  while (getline(file, line)) {
    std::vector<std::string> columns = read_file_line(line);
    m_rows.push_back(columns);
  }

  file.close();
}

void Database::write_lines(const std::vector<std::string>& lines) {
  std::ofstream file(m_file_name);

  if (!file.is_open()) {
    std::cerr << "Could not open the file!" << std::endl;
  }

  for (std::string line : lines) {
    file << line << std::endl;
  }

  file.close();
}

void Database::log() {
  for (size_t row = 0; row < m_rows.size(); row++) {
    for (size_t col = 0; col < m_rows[row].size(); col++) {
      std::cout << "Column name: " << m_field_names[col] << ", value: " << m_rows[row][col] << std::endl;
    }
  }
}

std::vector<std::vector<std::string>> Database::get_rows() {
  return m_rows;
}

std::vector<std::string> Database::get_field_names() {
  return m_field_names;
}