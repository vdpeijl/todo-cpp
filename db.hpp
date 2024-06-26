#include <fstream>
#include <iostream>
using namespace std;

class Database {
  private:
    string fileName;
    vector<string> fieldNames;
    string delimiter;
    vector<vector<string>> rows;
    void readFile();
    vector<string> readFileLine(string line);

  public:
    Database(const string name, const vector<string> fields, const string delim = ",");
    void writeLines(const vector<string>& lines);
    void log();
    vector<vector<string>> getRows();
    vector<string> getFieldNames();
};