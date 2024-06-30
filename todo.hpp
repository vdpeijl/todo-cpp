#include <iostream>

namespace tlib {
  struct todo {
    bool completed;
    std::string name;
    std::string id;
  };

  tlib::todo* set_status(tlib::todo* todo, const bool completed);
  tlib::todo* find_by_id(std::vector<tlib::todo>& todos, const std::string id);
  void print_todos(const std::vector<tlib::todo> todos);
  std::vector<std::string> create_todo_lines(const std::vector<tlib::todo> todos);
}