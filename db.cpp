#include <iostream>
#include <map>
#include <fstream>
#include "db.hpp"
using namespace std;

Database::Database(const string name, const vector<string> fields, const string delim) {
  fieldNames = fields;
  fileName = name;
  delimiter = delim;
  read();
}

vector<string> Database::readLine(string line) {
  int currentPos = 0;
  vector<string> columns;

  for (const string& fieldName : fieldNames) {
    int nextPos = line.find(delimiter);
    string column = line.substr(currentPos, nextPos);
    columns.push_back(column);

    if (line.length()) {
      line.erase(currentPos, nextPos + delimiter.length());
    }
  }

  return columns;
}

void Database::read() {
  ifstream file(fileName);
  string line;

  if (!file.is_open()) {
    cerr << "Could not open the file!" << endl;
  }

  while (getline(file, line)) {
    vector<string> columns = readLine(line);
    rows.push_back(columns);
  }

  file.close();
}

void Database::log() {
  for (int row = 0; row < rows.size(); row++) {
    //row
    for (int col = 0; col < rows[row].size(); col++) {
      // column
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