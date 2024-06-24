#include <iostream>
using namespace std;

class Todo {
  private:
    bool completed;
    string name;
    string id;

  public:
    Todo(string todoName);
    string getName();
    bool getStatus();
    void toggleStatus();
    void saveTodo();
};