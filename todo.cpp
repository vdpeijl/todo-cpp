#include <iostream>
#include <fstream>
#include "todo.hpp"
#include "db.hpp"

Todo* SetTodoStatus(Todo* todo, const bool completed) {
  todo->completed = completed;
  return todo;
}

Todo* FindTodoById(std::vector<Todo>& todos, const std::string id) {
  for (Todo& todo : todos) {
    if (todo.id == id) {
      return &todo;
    }
  }
  return nullptr;
}

void PrintTodos(const std::vector<Todo> todos) {
  for (const Todo& todo : todos) {
    std::string check = todo.completed ? "x" : " ";
    std::cout << "[" << check << "] " << todo.id << ". " << todo.name << std::endl;
  }
}

std::vector<std::string> CreateTodoLines(const std::vector<Todo> todos) {
  std::vector<std::string> lines;
  for (const Todo& todo : todos) {
    std::string status = todo.completed ? "true" : "false";
    std::string line = todo.id + "," + todo.name + "," + status;
    lines.push_back(line);
  }
  return lines;
}