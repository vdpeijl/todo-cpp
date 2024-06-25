#include <iostream>
using namespace std;

class Todo {
  private:
    bool completed;
    string name;
    string id;

  public:
    Todo(const string id, const string name, const bool completed);
    string getName() const;
    bool getStatus() const;
    string getId() const;
    void toggleStatus();
    void display();
};