#include <iostream>
#include <fstream>
#include "todo.hpp"
#include "db.hpp"
using namespace std;

Todo::Todo(string todoName) {
  srand (time(NULL));
  name = todoName;
  id = rand()%10000;
  completed = false;
}

bool Todo::getStatus() {
  return completed;
}

void Todo::toggleStatus() {
  completed = !completed;
}

string Todo::getName() {
  return name;
}