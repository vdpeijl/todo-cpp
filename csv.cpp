#include <iostream>
#include <fstream>
#include "csv.hpp"
using namespace std;

CSVParser::CSVParser(string name, vector<string> fields) {
  fileName = name;
  fieldNames = fields;
}

vector<string> CSVParser::parse() {
  ifstream file(fileName);
  string line;
  while (getline(file, line)) {
    cout << line << endl;
  }
  file.close();

  return {};
}