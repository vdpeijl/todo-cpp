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

int main() {
  vector<Todo> todos;
  Database db("todos.db", {"id", "name", "completed"});
  
  for (const vector<string>& row : db.getRows()) {
    Todo todo(row[0], row[1], row[2] == "true");
    todos.push_back(todo);
  }

  Todo* found = findTodoById(todos, "1");
  found->toggleStatus();

  cout << "Name: " << found->getName() << endl;
}