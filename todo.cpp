#include <iostream>
#include <fstream>
#include "todo.hpp"
#include "db.hpp"
using namespace std;

Todo::Todo(const string todoId, const string todoName, const bool isCompleted) {
  id = todoId;
  name = todoName;
  completed = isCompleted;
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

void Todo::display() {
  cout << "ID: " << id << endl;
  cout << "Name: " << name << endl;
  cout << "Completed: " << completed << endl;
}