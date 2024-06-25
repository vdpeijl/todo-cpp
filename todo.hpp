#include <iostream>
using namespace std;

class Todo {
  private:
    bool completed;
    string name;
    string id;

  public:
    Todo(const string id, const string name, const bool completed);
    string getName();
    bool getStatus();
    void toggleStatus();
    void display();
};