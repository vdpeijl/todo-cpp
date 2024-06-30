#include <fstream>
#include <iostream>

class Database {
  private:
    std::string m_file_name;
    std::vector<std::string> m_field_names;
    std::string m_delimiter;
    std::vector<std::vector<std::string>> m_rows;
    std::vector<std::string> read_file_line(std::string line);
    void read_file();

  public:
    Database(const std::string name, const std::vector<std::string> fields, const std::string delimiter = ",");
    void write_lines(const std::vector<std::string>& lines);
    void log();
    std::vector<std::vector<std::string>> get_rows();
    std::vector<std::string> get_field_names();
};