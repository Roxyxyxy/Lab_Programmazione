
#include "ToDoList.h"
#include <iostream>
using namespace std;

ToDoList::ToDoList(string title) : title(move(title)) {}

void ToDoList::addTodo(const string &description)
{
    ToDo newTodo(description, Date());
    toDoList.push_back(newTodo);
    numberOfTodos++;
}

void ToDoList::removeTodo(int index)
{
    if (index < 1 || index > (int)toDoList.size())
    {
        cout << "Indice non valido!" << endl;
        return;
    }

    auto it = toDoList.begin();
    for (int i = 1; i < index; i++)
    {
        ++it;
    }

    bool wasCompleted = it->isCompleted();
    toDoList.erase(it);
    numberOfTodos--;
    if (wasCompleted)
        numberOfCompletedTodos--;
}

void ToDoList::removeAll()
{
    toDoList.clear();
    numberOfTodos = 0;
    numberOfCompletedTodos = 0;
}

void ToDoList::markCompleted(int index)
{
    if (index < 1 || index > (int)toDoList.size())
    {
        cout << "Indice non valido!" << endl;
        return;
    }

    auto it = toDoList.begin();
    for (int i = 1; i < index; i++)
    {
        ++it;
    }

    if (!it->isCompleted())
    {
        it->setCompleted(true);
        numberOfCompletedTodos++;
        cout << "Todo completato!" << endl;
    }
    else
    {
        cout << "Questo todo è già completato!" << endl;
    }
}

void ToDoList::editDescription(int index, const string &newDesc)
{
    if (index < 1 || index > (int)toDoList.size())
    {
        cout << "Indice non valido!" << endl;
        return;
    }

    auto it = toDoList.begin();
    for (int i = 1; i < index; i++)
    {
        ++it;
    }

    it->setDescription(newDesc);
    cout << "Descrizione modificata!" << endl;
}

void ToDoList::displayAll()
{
    cout << "\n========== " << title << " ==========" << endl;
    if (toDoList.empty())
    {
        cout << "Nessun todo presente!" << endl;
        return;
    }

    int index = 1;
    for (const auto &todo : toDoList)
    {
        cout << index << ". " << todo.getInfo() << endl;
        index++;
    }
    cout << "====================================" << endl;
}

void ToDoList::displayPending()
{
    cout << "\n========== TODOS DA COMPLETARE ==========" << endl;
    if (toDoList.empty())
    {
        cout << "Nessun todo presente!" << endl;
        return;
    }

    int index = 1;
    bool hasPending = false;
    for (const auto &todo : toDoList)
    {
        if (!todo.isCompleted())
        {
            cout << index << ". " << todo.getInfo() << endl;
            hasPending = true;
        }
        index++; 
    }

    if (!hasPending)
    {
        cout << "Tutti i todos sono completati!" << endl;
    }
    cout << "=========================================" << endl;
}

void ToDoList::showStats() const
{
    cout << "\n========== STATISTICHE ==========" << endl;
    cout << "Titolo lista: " << title << endl;
    cout << "Todos totali: " << numberOfTodos << endl;
    cout << "Todos completati: " << numberOfCompletedTodos << endl;
    cout << "Todos da completare: " << (numberOfTodos - numberOfCompletedTodos) << endl;
    if (numberOfTodos > 0)
    {
        double percentuale = (double)numberOfCompletedTodos / numberOfTodos * 100;
        cout << "Percentuale completamento: " << percentuale << "%" << endl;
    }
    cout << "=================================" << endl;
}

bool ToDoList::isEmpty() const
{
    return toDoList.empty();
}
