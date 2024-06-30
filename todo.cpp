#include <iostream>
#include <fstream>
#include "todo.hpp"
#include "db.hpp"

namespace tlib {
  tlib::todo* set_status(tlib::todo* todo, const bool completed) {
    todo->completed = completed;
    return todo;
  }

  tlib::todo* find_by_id(std::vector<tlib::todo>& todos, const std::string id) {
    for (tlib::todo& todo : todos) {
      if (todo.id == id) {
        return &todo;
      }
    }
    return nullptr;
  }

  void print_todos(const std::vector<tlib::todo> todos) {
    for (const tlib::todo& todo : todos) {
      std::string check = todo.completed ? "x" : " ";
      std::cout << "[" << check << "] " << todo.id << ". " << todo.name << std::endl;
    }
  }

  std::vector<std::string> create_todo_lines(const std::vector<tlib::todo> todos) {
    std::vector<std::string> lines;
    for (const tlib::todo& todo : todos) {
      std::string status = todo.completed ? "true" : "false";
      std::string line = todo.id + "," + todo.name + "," + status;
      lines.push_back(line);
    }
    return lines;
  }
}
