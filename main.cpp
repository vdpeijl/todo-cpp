#include <iostream>
#include "todo.hpp"
#include "db.hpp"
#include <string>
#include <time.h>

int main() {
  std::vector<tlib::todo> todos;
  Database db("todos.db", {"id", "name", "completed"});
  
  for (const std::vector<std::string>& row : db.GetRows()) {
    tlib::todo todo = {
      .id = row[0],
      .name = row[1],
      .completed = row[2] == "true"
    };
    todos.push_back(todo);
  }

  std::string input;

  while (true) {
    std::cout << "##################################" << std::endl;
    tlib::print_todos(todos);
    std::cout << "##################################" << std::endl;
    std::cout << "Enter command (h or help for all commands): " << std::endl;
    getline(std::cin, input);

    if (input == "exit" || input == "e") {
      std::cout << "Exiting the program." << std::endl;
      break;
    }

    if (input == "help" || input == "h") {
      std::cout << "Available commands: " << std::endl;
      std::cout << "[e, exit]  : Exit the program" << std::endl;
      std::cout << "[a, add]   : Add a new to-do item" << std::endl;
      std::cout << "[d, delete]: Delete a to-do item by ID" << std::endl;
      std::cout << "[t, toggle]: Toggle a to-do item by ID" << std::endl;
      std::cout << "[h, help]:   Show available commands" << std::endl;
    }

    if (input == "add" || input == "a") {
      std::string name;
      std::cout << "Enter the name of your todo:" << std::endl;
      getline(std::cin, name);
      tlib::todo prev = todos.back();
      int prevIndex = stoi(prev.id);

      tlib::todo todo = {
        .id = std::to_string(prevIndex + 1),
        .name = name,
        .completed = false
      };

      todos.push_back(todo);
      std::vector<std::string> lines = tlib::create_todo_lines(todos);
      db.WriteLines(lines);
    }

    if (input == "toggle" || input == "t") {
      std::string id;
      std::cout << "Toggle item by id: " << std::endl;
      getline(std::cin, id);
      tlib::todo* found = tlib::find_by_id(todos, id);

      if (found) {
        tlib::set_status(found, !found->completed);
        std::vector<std::string> lines = tlib::create_todo_lines(todos);
        db.WriteLines(lines);
      } else {
        std::cout << "Invalid todo id." << std::endl;
      }
    }

    if (input == "delete" || input == "d") {
      std::string id;
      std::cout << "Delete item by id: " << std::endl;
      getline(std::cin, id);

      tlib::todo* found = tlib::find_by_id(todos, id);

      if (found) {
        auto it = std::find_if(todos.begin(), todos.end(), [found](const tlib::todo& todo) {
          return &todo == found;
        });

        if (it != todos.end()) {
          todos.erase(it);
        }
        
        std::vector<std::string> lines = tlib::create_todo_lines(todos);
        db.WriteLines(lines);
      }
    }
  }
}