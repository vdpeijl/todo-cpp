#include <iostream>
#include "todo.hpp"
#include "db.hpp"
#include <string>
#include <time.h>

int main() {
  std::vector<Todo> todos;
  Database db("todos.db", {"id", "name", "completed"});
  
  for (const std::vector<std::string>& row : db.GetRows()) {
    Todo todo(row[0], row[1], row[2] == "true");
    todos.push_back(todo);
  }

  std::string input;

  while (true) {
    std::cout << "##################################" << std::endl;
    PrintTodos(todos);
    std::cout << "##################################" << std::endl;
    std::cout << "Enter command (h or help for all commands): " << std::endl;
    getline(std::cin, input);

    // Check if the user wants to exit
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
      Todo prev = todos.back();
      int prevIndex = stoi(prev.GetId());
      Todo todo(std::to_string(prevIndex + 1), name, false);
      todos.push_back(todo);
      std::vector<std::string> lines = CreateTodoLines(todos);
      db.WriteLines(lines);
    }

    if (input == "toggle" || input == "t") {
      std::string id;
      std::cout << "Toggle item by id: " << std::endl;
      getline(std::cin, id);
      Todo* found = FindTodoById(todos, id);

      if (found) {
        found->ToggleStatus();
        std::vector<std::string> lines = CreateTodoLines(todos);
        db.WriteLines(lines);
      } else {
        std::cout << "Invalid todo id." << std::endl;
      }
    }

    if (input == "delete" || input == "d") {
      std::string id;
      std::cout << "Delete item by id: " << std::endl;
      getline(std::cin, id);

      Todo* found = FindTodoById(todos, id);

      if (found) {
        auto it = std::find_if(todos.begin(), todos.end(), [found](const Todo& todo) {
          return &todo == found;
        });

        if (it != todos.end()) {
          todos.erase(it);
        }
        
        std::vector<std::string> lines = CreateTodoLines(todos);
        db.WriteLines(lines);
      }
    }
  }
}