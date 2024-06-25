#include <iostream>
#include "todo.hpp"
#include "db.hpp"
using namespace std;

int main() {
  Database todos("todos.db", {"id", "name", "completed"});
  // todos.log();
}