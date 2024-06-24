#include <iostream>
#include <map>
#include <fstream>
#include "csv.hpp"
using namespace std;

CSVParser::CSVParser(string name, vector<string> fields, string delim) {
  fieldNames = fields;
  fileName = name;
  delimiter = delim;
  parse();
}

vector<string> CSVParser::parseLine(string line) {
  int currentPos = 0;
  vector<string> columns;

  for (int i = 0; i < fieldNames.size(); i++) {
    int nextPos = line.find(delimiter);
    string column = line.substr(currentPos, nextPos);
    columns.push_back(column);
    currentPos = nextPos + 1;
  }

  return columns;
}

void CSVParser::parse() {
  ifstream file(fileName);
  string line;

  if (!file.is_open()) {
    cerr << "Could not open the file!" << endl;
  }

  int lineNumber = 0;
  while (getline(file, line)) {
    if (lineNumber == 0) {
      // do nothing
    } else {
      vector<string> columns = parseLine(line);
      rows.push_back(columns);
    }
    lineNumber++;
  }

  file.close();
}

void CSVParser::log() {
  for (int row = 0; row < rows.size(); row++) {
    //row
    for (int col = 0; col < rows[row].size(); col++) {
      // column
      cout << "Column name: " << fieldNames[col] << ", value: " << rows[row][col] << endl;
    }
  }
}