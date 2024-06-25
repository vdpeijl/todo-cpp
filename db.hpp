#include <fstream>
#include <iostream>
using namespace std;

class Database {
  private:
    string fileName;
    vector<string> fieldNames;
    string delimiter;
    vector<vector<string>> rows;
    void read();
    vector<string> readLine(string line);

  public:
    Database(const string name, const vector<string> fields, const string delim = ",");
    void log();
    vector<vector<string>> getRows();
    vector<string> getFieldNames();
};