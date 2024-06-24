#include <iostream>
#include "todo.hpp"
using namespace std;

int main() {
  Todo newTodo("Thing");

  cout << newTodo.getName() << "\n";
  cout << "Completed: " << newTodo.getStatus() << "\n";

  newTodo.toggleStatus();

  cout << "After toggle: " << newTodo.getStatus() << "\n";

  newTodo.saveTodo();
}