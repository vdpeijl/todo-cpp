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

bool Todo::getStatus() const {
  return completed;
}

void Todo::toggleStatus() {
  completed = !completed;
}

string Todo::getName() const {
  return name;
}

string Todo::getId() const {
  return id;
}

void Todo::display() {
  cout << "ID: " << id << endl;
  cout << "Name: " << name << endl;
  cout << "Completed: " << completed << endl;
}

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

vector<string> createTodoLines(const vector<Todo> todos) {
  vector<string> lines;
  for (const Todo& todo : todos) {
    string status = todo.getStatus() ? "true" : "false";
    string line = todo.getId() + "," + todo.getName() + "," + status;
    lines.push_back(line);
  }
  return lines;
}