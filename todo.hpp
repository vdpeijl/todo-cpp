#include <iostream>

class Todo {
  private:
    bool completed_;
    std::string name_;
    std::string id_;

  public:
    Todo(const std::string id, const std::string name, const bool completed);
    std::string GetName() const;
    bool GetStatus() const;
    std::string GetId() const;
    void ToggleStatus();
    void Display();
};

Todo* FindTodoById(std::vector<Todo>& todos, const std::string id);

void PrintTodos(const std::vector<Todo> todos);

std::vector<std::string> CreateTodoLines(const std::vector<Todo> todos);