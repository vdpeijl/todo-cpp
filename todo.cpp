#include <iostream>
#include <fstream>
#include "todo.hpp"
#include "db.hpp"

Todo::Todo(const std::string id, const std::string name, const bool completed) {
  id_ = id;
  name_ = name;
  completed_ = completed;
}

bool Todo::GetStatus() const {
  return completed_;
}

void Todo::ToggleStatus() {
  completed_ = !completed_;
}

std::string Todo::GetName() const {
  return name_;
}

std::string Todo::GetId() const {
  return id_;
}

void Todo::Display() {
  std::cout << "ID: " << id_ << std::endl;
  std::cout << "Name: " << name_ << std::endl;
  std::cout << "Completed: " << completed_ << std::endl;
}

Todo* FindTodoById(std::vector<Todo>& todos, const std::string id) {
  for (Todo& todo : todos) {
    if (todo.GetId() == id) {
      return &todo;
    }
  }
  return nullptr;
}

void PrintTodos(const std::vector<Todo> todos) {
  for (const Todo& todo : todos) {
    std::string check = todo.GetStatus() ? "x" : " ";
    std::cout << "[" << check << "] " << todo.GetId() << ". " << todo.GetName() << std::endl;
  }
}

std::vector<std::string> CreateTodoLines(const std::vector<Todo> todos) {
  std::vector<std::string> lines;
  for (const Todo& todo : todos) {
    std::string status = todo.GetStatus() ? "true" : "false";
    std::string line = todo.GetId() + "," + todo.GetName() + "," + status;
    lines.push_back(line);
  }
  return lines;
}