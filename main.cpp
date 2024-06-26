#include <iostream>
#include "todo.hpp"
#include "db.hpp"
using namespace std;

Todo* findTodoById(vector<Todo>& todos, const string id) {
  for (Todo& todo : todos) {
    if (todo.getId() == id) {
      return &todo;
    }
  }
  return nullptr;
}

void printTodos(const vector<Todo> todos) {
  for (const Todo& todo : todos) {
    string check = todo.getStatus() ? "x" : " ";
    cout << "[" << check << "] " << todo.getId() << ". " << todo.getName() << endl;
  }
}

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
      cin >> id;
      Todo* found = findTodoById(todos, id);

      if (found) {
        found->toggleStatus();
      } else {
        cout << "Invalid todo id." << endl;
      }
    }
  }
}