#include <iostream>
#include "todo.hpp"
#include "db.hpp"
using namespace std;

int main() {
  vector<Todo> todos;
  Database db("todos.db", {"id", "name", "completed"});
  
  for (const vector<string>& row : db.getRows()) {
    Todo todo(row[0], row[1], row[2] == "true");
    todos.push_back(todo);
  }

  string input;

  while (true) {
    cout << "##################################" << endl;
    printTodos(todos);
    cout << "##################################" << endl;
    cout << "Enter command (or 'exit' to quit): " << endl;
    getline(cin, input);

    // Check if the user wants to exit
    if (input == "exit" || input == "e") {
      cout << "Exiting the program." << endl;
      break;
    }

    if (input == "toggle" || input == "t") {
      string id;
      cout << "Toggle item by id: " << endl;
      getline(cin, id);
      Todo* found = findTodoById(todos, id);

      if (found) {
        found->toggleStatus();
        vector<string> lines = createTodoLines(todos);
        db.writeLines(lines);
      } else {
        cout << "Invalid todo id." << endl;
      }
    }
  }
}