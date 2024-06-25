#include <iostream>
#include "todo.hpp"
#include "db.hpp"
using namespace std;

int main() {
  vector<Todo> todos;
  Database db("todos.db", {"id", "name", "completed"});
  
  for (const auto& row : db.getRows()) {
    Todo todo(row[0], row[1], row[2] == "true");
    todo.display();
    todos.push_back(todo);
  }
}