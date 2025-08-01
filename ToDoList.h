
#pragma once

#include "ToDo.h"
#include <list>
#include <string>
using namespace std;

class ToDoList
{
public:
    explicit ToDoList(string title);
    ToDoList() = default;

    // Gestione todos
    void addTodo(const string &description);
    void addTodo(const string &description, const Date &dueDate);
    void removeTodo(int index);
    void markCompleted(int index);
    void editDescription(int index, const string &newDesc);
    void removeAll();

    // Visualizzazione
    void displayAll() const;
    void displayPending() const;
    void showStats() const;

    // Utilità
    bool isEmpty() const;
    int getSize() const;

    // Salvataggio/Caricamento file (facoltativo)
    bool saveToFile(const string &filename) const;
    bool loadFromFile(const string &filename);

private:
    list<ToDo> toDoList;
    string title;
    int numberOfTodos{0};
    int numberOfCompletedTodos{0};
};
