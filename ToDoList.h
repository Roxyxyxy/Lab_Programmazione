#ifndef TODOLIST_H
#define TODOLIST_H

#include "ToDo.h"
#include <vector>
#include <iostream>
using namespace std;

class ToDoList
{
private:
    vector<ToDo> todos;
    string listName;

public:
    // Costruttore
    ToDoList(const string &name = "My ToDo List") : listName(name) {}

    // Aggiungere un todo
    void addTodo(const ToDo &todo)
    {
        todos.push_back(todo);
        cout << "Todo aggiunto: " << todo.getDescription() << endl;
    }

    // Aggiungere un todo con solo la descrizione
    void addTodo(const string &description)
    {
        ToDo newTodo(description);
        todos.push_back(newTodo);
        cout << "Todo aggiunto: " << description << endl;
    }

    // Mostrare tutti i todos
    void displayAll()
    {
        cout << "\n=== " << listName << " ===" << endl;
        if (todos.empty())
        {
            cout << "Nessun todo presente!" << endl;
            return;
        }

        for (size_t i = 0; i < todos.size(); i++)
        {
            cout << i + 1 << ". " << todos[i].getInfo() << endl;
        }
    }

    // Mostrare solo i todos non completati
    void displayPending()
    {
        cout << "\n=== Todos da completare ===" << endl;
        bool hasPending = false;

        for (size_t i = 0; i < todos.size(); i++)
        {
            if (!todos[i].isCompleted())
            {
                cout << i + 1 << ". " << todos[i].getInfo() << endl;
                hasPending = true;
            }
        }

        if (!hasPending)
        {
            cout << "Tutti i todos sono completati! Ottimo lavoro!" << endl;
        }
    }

    // Contrassegnare un todo come completato
    bool markCompleted(int index)
    {
        if (index >= 1 && index <= (int)todos.size())
        {
            todos[index - 1].markCompleted();
            cout << "Todo completato: " << todos[index - 1].getDescription() << endl;
            return true;
        }
        else
        {
            cout << "Numero non valido! Scegli tra 1 e " << todos.size() << endl;
            return false;
        }
    }

    // Rimuovere un todo
    bool removeTodo(int index)
    {
        if (index >= 1 && index <= (int)todos.size())
        {
            cout << "Todo rimosso: " << todos[index - 1].getDescription() << endl;
            todos.erase(todos.begin() + index - 1);
            return true;
        }
        else
        {
            cout << "Numero non valido!" << endl;
            return false;
        }
    }

    // Ottenere statistiche
    void showStats()
    {
        int total = todos.size();
        int completed = 0;

        for (const auto &todo : todos)
        {
            if (todo.isCompleted())
            {
                completed++;
            }
        }

        cout << "\n=== Statistiche ===" << endl;
        cout << "Totale todos: " << total << endl;
        cout << "Completati: " << completed << endl;
        cout << "Da completare: " << (total - completed) << endl;

        if (total > 0)
        {
            double percentage = (double)completed / total * 100;
            cout << "Percentuale completamento: " << percentage << "%" << endl;
        }
    }

    // Ottenere il numero di todos
    int getCount() const { return todos.size(); }

    // Verificare se la lista è vuota
    bool isEmpty() const { return todos.empty(); }
};

#endif // TODOLIST_H
