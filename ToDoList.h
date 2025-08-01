
#ifndef MYTODOLIST_TODOLIST_H
#define MYTODOLIST_TODOLIST_H

#include "ToDo.h"
#include <list>
using namespace std;

class ToDoList
{
public:
    explicit ToDoList(string title);
    ToDoList() = default;

    // Gestione todos
    void addTodo(const string &description);
    void removeTodo(int index);
    void markCompleted(int index);
    void editDescription(int index, const string &newDesc);
    void removeAll();

    // Visualizzazione
    void displayAll();
    void displayPending();
    void showStats() const;

    // Utilità
    bool isEmpty() const;

private:
    list<ToDo> toDoList;
    string title;
    int numberOfTodos{0};
    int numberOfCompletedTodos{0};
};

#endif // MYTODOLIST_TODOLIST_H
