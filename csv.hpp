#include <fstream>
#include <iostream>
using namespace std;

class CSVParser {
  string fileName;
  vector<string> fieldNames;

  public:
    CSVParser(string name, vector<string> fields);
    vector<string> parse();
};