#include <iostream>
#include <map>
#include <fstream>
#include "db.hpp"
using namespace std;

Database::Database(const string name, const vector<string> fields, const string delim) {
  fieldNames = fields;
  fileName = name;
  delimiter = delim;
  readFile();
}

vector<string> Database::readFileLine(string line) {
  vector<string> columns;

  for (size_t i = 0; i < fieldNames.size(); i++) {
    size_t nextPos = line.find(delimiter);
    string column = line.substr(0, nextPos);
    columns.push_back(column);

    if (line.length()) {
      line.erase(0, nextPos + delimiter.length());
    }
  }

  return columns;
}

void Database::readFile() {
  ifstream file(fileName);
  string line;

  if (!file.is_open()) {
    cerr << "Could not open the file!" << endl;
  }

  while (getline(file, line)) {
    vector<string> columns = readFileLine(line);
    rows.push_back(columns);
  }

  file.close();
}

void Database::writeLines(const vector<string>& lines) {
  ofstream file(fileName);

  if (!file.is_open()) {
    cerr << "Could not open the file!" << endl;
  }

  for (string line : lines) {
    file << line << endl;
  }

  file.close();
}

void Database::log() {
  for (size_t row = 0; row < rows.size(); row++) {
    for (size_t col = 0; col < rows[row].size(); col++) {
      cout << "Column name: " << fieldNames[col] << ", value: " << rows[row][col] << endl;
    }
  }
}

vector<vector<string>> Database::getRows() {
  return rows;
}

vector<string> Database::getFieldNames() {
  return fieldNames;
}