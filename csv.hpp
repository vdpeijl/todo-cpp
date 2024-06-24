#include <fstream>
#include <iostream>
using namespace std;

class CSVParser {
  private:
    string fileName;
    vector<string> fieldNames;
    string delimiter;
    vector<vector<string>> rows;
    void parse();
    vector<string> parseLine(string line);

  public:
    CSVParser(string name, vector<string> fields, string delim = ",");
    void log();
};