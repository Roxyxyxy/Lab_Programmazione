
#include "ToDoList.h"
#include <iostream>
#include <fstream>
using namespace std;

ToDoList::ToDoList(string title) : title(move(title)) {}

void ToDoList::addTodo(const string &description)
{
    ToDo newTodo(description, Date());
    toDoList.push_back(newTodo);
    numberOfTodos++;
}

void ToDoList::addTodo(const string &description, const Date &dueDate)
{
    ToDo newTodo(description, dueDate);
    toDoList.push_back(newTodo);
    numberOfTodos++;
}

void ToDoList::removeTodo(int index)
{
    if (index < 1 || index > static_cast<int>(toDoList.size()))
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

    cout << "Todo rimosso con successo!" << endl;
}

void ToDoList::removeAll()
{
    toDoList.clear();
    numberOfTodos = 0;
    numberOfCompletedTodos = 0;
    cout << "Tutti i todos sono stati rimossi!" << endl;
}

void ToDoList::markCompleted(int index)
{
    if (index < 1 || index > static_cast<int>(toDoList.size()))
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
    if (index < 1 || index > static_cast<int>(toDoList.size()))
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

void ToDoList::displayAll() const
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

void ToDoList::displayPending() const
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
        double percentuale = static_cast<double>(numberOfCompletedTodos) / numberOfTodos * 100;
        cout << "Percentuale completamento: " << percentuale << "%" << endl;
    }
    cout << "=================================" << endl;
}

bool ToDoList::isEmpty() const
{
    return toDoList.empty();
}

int ToDoList::getSize() const
{
    return static_cast<int>(toDoList.size());
}

bool ToDoList::saveToFile(const string &filename) const
{
    ofstream file(filename);
    if (!file.is_open())
    {
        cout << "Errore: impossibile aprire il file " << filename << endl;
        return false;
    }

    file << title << endl;
    file << numberOfTodos << endl;
    file << numberOfCompletedTodos << endl;

    for (const auto &todo : toDoList)
    {
        file << todo.getDescription() << "|";
        file << todo.getDate().getDay() << "/" << todo.getDate().getMonth() << "/" << todo.getDate().getYear() << "|";
        file << (todo.isCompleted() ? "1" : "0") << endl;
    }

    file.close();
    cout << "Lista salvata nel file " << filename << endl;
    return true;
}

bool ToDoList::loadFromFile(const string &filename)
{
    ifstream file(filename);
    if (!file.is_open())
    {
        cout << "Errore: impossibile aprire il file " << filename << endl;
        return false;
    }

    toDoList.clear();

    getline(file, title);
    file >> numberOfTodos >> numberOfCompletedTodos;
    file.ignore(); // Ignora il newline dopo i numeri

    string line;
    while (getline(file, line))
    {
        size_t pos1 = line.find('|');
        size_t pos2 = line.find('|', pos1 + 1);

        if (pos1 != string::npos && pos2 != string::npos)
        {
            string description = line.substr(0, pos1);
            string dateStr = line.substr(pos1 + 1, pos2 - pos1 - 1);
            string completedStr = line.substr(pos2 + 1);

            // Parse date
            size_t slash1 = dateStr.find('/');
            size_t slash2 = dateStr.find('/', slash1 + 1);

            int day = 0, month = 0, year = 0;
            if (slash1 != string::npos && slash2 != string::npos)
            {
                day = stoi(dateStr.substr(0, slash1));
                month = stoi(dateStr.substr(slash1 + 1, slash2 - slash1 - 1));
                year = stoi(dateStr.substr(slash2 + 1));
            }

            Date date(day, month, year);
            ToDo todo(description, date);

            if (completedStr == "1")
            {
                todo.setCompleted(true);
            }

            toDoList.push_back(todo);
        }
    }

    file.close();
    cout << "Lista caricata dal file " << filename << endl;
    return true;
}
