#include <iostream>
#include "todo.hpp"
#include "db.hpp"

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
    std::cout << "Enter command (or 'exit' to quit): " << std::endl;
    getline(std::cin, input);

    // Check if the user wants to exit
    if (input == "exit" || input == "e") {
      std::cout << "Exiting the program." << std::endl;
      break;
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
  }
}