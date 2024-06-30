#include <fstream>
#include <iostream>

class Database {
  private:
    std::string file_name_;
    std::vector<std::string> field_names_;
    std::string delimiter_;
    std::vector<std::vector<std::string>> rows_;
    void ReadFile();
    std::vector<std::string> ReadFileLine(std::string line);

  public:
    Database(const std::string name, const std::vector<std::string> fields, const std::string delimiter = ",");
    void WriteLines(const std::vector<std::string>& lines);
    void Log();
    std::vector<std::vector<std::string>> GetRows();
    std::vector<std::string> GetFieldNames();
};