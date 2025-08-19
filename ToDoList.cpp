
#include "ToDoList.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// Costruttore con nome
ToDoList::ToDoList(string title) : title(title) {}

// Costruttore di default
ToDoList::ToDoList() : title("La mia ToDo List"), numberOfTodos(0), numberOfCompletedTodos(0) {}

// Funzione per trovare un todo per indice
bool ToDoList::isValidIndex(int index) const
{
    if (index < 1 || index > numberOfTodos)
    {
        return false;
    }
    return true;
}

// Trova un todo per indice
ToDo *ToDoList::getTodoAtIndex(int index)
{
    if (!isValidIndex(index))
    {
        return nullptr;
    }

    // Uso un contatore per arrivare all'elemento giusto
    int count = 1;
    for (auto &todo : toDoList)
    {
        if (count == index)
        {
            return &todo;
        }
        count++;
    }
    return nullptr;
}

void ToDoList::addTodo(const string &description)
{
    Date emptyDate; // Data vuota
    ToDo newTodo(description, emptyDate);
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
    if (!isValidIndex(index))
    {
        cout << "Indice non valido!" << endl;
        return;
    }

    // Trovo il todo da rimuovere
    int count = 1;
    for (auto it = toDoList.begin(); it != toDoList.end(); it++)
    {
        if (count == index)
        {
            // Controllo se era completato per aggiornare il contatore
            if (it->isCompleted())
            {
                numberOfCompletedTodos--;
            }

            toDoList.erase(it);
            numberOfTodos--;
            cout << "Todo rimosso con successo!" << endl;
            return;
        }
        count++;
    }
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
    ToDo *todo = getTodoAtIndex(index);
    if (todo == nullptr)
    {
        cout << "Indice non valido!" << endl;
        return;
    }

    if (!todo->isCompleted())
    {
        todo->setCompleted(true);
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
    ToDo *todo = getTodoAtIndex(index);
    if (todo == nullptr)
    {
        cout << "Indice non valido!" << endl;
        return;
    }

    todo->setDescription(newDesc);
    cout << "Descrizione modificata!" << endl;
}

void ToDoList::displayAll() const
{
    cout << "\n========== " << title << " ==========" << endl;

    if (numberOfTodos == 0)
    {
        cout << "Nessun todo presente!" << endl;
        return;
    }

    // Visualizzazione di tutti i todo
    int index = 1;
    for (const ToDo &todo : toDoList)
    {
        cout << index << ". " << todo.getInfo() << endl;
        index++;
    }
    cout << "====================================" << endl;
}

void ToDoList::displayPending() const
{
    cout << "\n========== TODOS DA COMPLETARE ==========" << endl;

    if (numberOfTodos == 0)
    {
        cout << "Nessun todo presente!" << endl;
        return;
    }

    int index = 1;
    bool hasPending = false;

    // Mostro solo quelli non completati con indice corretto
    for (const ToDo &todo : toDoList)
    {
        if (!todo.isCompleted())
        {
            cout << index << ". " << todo.getInfo() << endl;
            hasPending = true;
        }
        index++; // Incremento sempre per mantenere l'indice originale
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

    // Calcolo percentuale di completamento
    if (numberOfTodos > 0)
    {
        double percentuale = (double)numberOfCompletedTodos / numberOfTodos * 100;
        cout << "Percentuale completamento: " << percentuale << "%" << endl;
    }
    cout << "=================================" << endl;
}

bool ToDoList::isEmpty() const
{
    return (numberOfTodos == 0);
}

int ToDoList::getSize() const
{
    return numberOfTodos;
}

bool ToDoList::saveToFile(const string &filename) const
{
    // Apro il file per scrittura
    ofstream file(filename);
    if (!file.is_open())
    {
        cout << "Errore: impossibile aprire il file " << filename << endl;
        return false;
    }

    // Scrivo le informazioni di base
    file << title << endl;
    file << numberOfTodos << endl;
    file << numberOfCompletedTodos << endl;

    // Scrivo ogni todo (ogni dato su una riga)
    for (const ToDo &todo : toDoList)
    {
        file << todo.getDescription() << endl;
        file << todo.getDate().getDay() << endl;
        file << todo.getDate().getMonth() << endl;
        file << todo.getDate().getYear() << endl;
        
        if (todo.isCompleted())
        {
            file << "1" << endl; // 1 = completato
        }
        else
        {
            file << "0" << endl; // 0 = non completato
        }
    }

    file.close();
    cout << "Lista salvata nel file " << filename << endl;
    return true;
}

bool ToDoList::loadFromFile(const string &filename)
{
    // Apro il file per lettura
    ifstream file(filename);
    if (!file.is_open())
    {
        cout << "Errore: impossibile aprire il file " << filename << endl;
        return false;
    }

    // Pulisco la lista attuale
    toDoList.clear();

    // Leggo le informazioni di base
    getline(file, title);
    file >> numberOfTodos >> numberOfCompletedTodos;
    file.ignore(); // Salto la nuova riga

    // Leggo ogni riga del file
    string line;
    while (getline(file, line))
    {
        // Cerco la prima | (separatore)
        int pos1 = (int)line.find('|');
        if (pos1 == -1)
            continue; // Riga non valida

        // Cerco la seconda |
        int pos2 = (int)line.find('|', pos1 + 1);
        if (pos2 == -1)
            continue; // Riga non valida

        // Estraggo le parti
        string description = line.substr(0, pos1);
        string dateStr = line.substr(pos1 + 1, pos2 - pos1 - 1);
        string completedStr = line.substr(pos2 + 1);

        // Processo la data (formato giorno/mese/anno)
        int day = 0, month = 0, year = 0;
        int slash1 = (int)dateStr.find('/');
        int slash2 = (int)dateStr.find('/', slash1 + 1);

        if (slash1 != -1 && slash2 != -1)
        {
            // Controllo per evitare errori con stringhe malformate
            try
            {
                day = stoi(dateStr.substr(0, slash1));
                month = stoi(dateStr.substr(slash1 + 1, slash2 - slash1 - 1));
                year = stoi(dateStr.substr(slash2 + 1));
            }
            catch (...)
            {
                // Se ci sono errori, usa data vuota
                day = 0;
                month = 0;
                year = 0;
            }
        }

        // Creo il todo con controllo di validità
        Date date(day, month, year);
        ToDo todo(description, date);

        // Imposto se completato
        if (completedStr == "1")
        {
            todo.setCompleted(true);
        }

        // Aggiungo alla lista
        toDoList.push_back(todo);
    }

    file.close();
    cout << "Lista caricata dal file " << filename << endl;
    return true;
}
