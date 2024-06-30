#include <iostream>
#include <map>
#include <fstream>
#include "db.hpp"

Database::Database(const std::string name, const std::vector<std::string> fields, const std::string delimiter) {
  field_names_ = fields;
  file_name_ = name;
  delimiter_ = delimiter;
  ReadFile();
}

std::vector<std::string> Database::ReadFileLine(std::string line) {
  std::vector<std::string> columns;

  for (size_t i = 0; i < field_names_.size(); i++) {
    size_t next_pos = line.find(delimiter_);
    std::string column = line.substr(0, next_pos);
    columns.push_back(column);

    if (line.length()) {
      line.erase(0, next_pos + delimiter_.length());
    }
  }

  return columns;
}

void Database::ReadFile() {
  std::ifstream file(file_name_);
  std::string line;

  if (!file.is_open()) {
    std::cerr << "Could not open the file!" << std::endl;
  }

  while (getline(file, line)) {
    std::vector<std::string> columns = ReadFileLine(line);
    rows_.push_back(columns);
  }

  file.close();
}

void Database::WriteLines(const std::vector<std::string>& lines) {
  std::ofstream file(file_name_);

  if (!file.is_open()) {
    std::cerr << "Could not open the file!" << std::endl;
  }

  for (std::string line : lines) {
    file << line << std::endl;
  }

  file.close();
}

void Database::Log() {
  for (size_t row = 0; row < rows_.size(); row++) {
    for (size_t col = 0; col < rows_[row].size(); col++) {
      std::cout << "Column name: " << field_names_[col] << ", value: " << rows_[row][col] << std::endl;
    }
  }
}

std::vector<std::vector<std::string>> Database::GetRows() {
  return rows_;
}

std::vector<std::string> Database::GetFieldNames() {
  return field_names_;
}