#include <iostream>

struct Todo {
  bool completed;
  std::string name;
  std::string id;
};

Todo* SetTodoStatus(Todo* todo, const bool completed);

Todo* FindTodoById(std::vector<Todo>& todos, const std::string id);

void PrintTodos(const std::vector<Todo> todos);

std::vector<std::string> CreateTodoLines(const std::vector<Todo> todos);