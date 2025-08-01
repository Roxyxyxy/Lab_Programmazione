#ifndef TODO_H
#define TODO_H

#include "Date.h"
#include <string>
using namespace std;

class ToDo
{
private:
    string description;
    Date dueDate;
    bool completed;

public:
    // Costruttore di default
    ToDo() : description(""), dueDate(Date()), completed(false) {}

    // Costruttore con parametri
    ToDo(const string &desc, const Date &date)
        : description(desc), dueDate(date), completed(false) {}

    // Getters
    string getDescription() const { return description; }
    Date getDate() const { return dueDate; }
    bool isCompleted() const { return completed; }

    // Setters
    void setDescription(const string &desc) { description = desc; }
    void setDate(const Date &date) { dueDate = date; }
    void setCompleted(bool status) { completed = status; }

    // Metodo per contrassegnare come completato
    void markCompleted() { completed = true; }

    // Metodo per ottenere informazioni complete del todo
    string getInfo() const
    {
        string info = description;
        if (completed)
        {
            info += " [COMPLETATO]";
        }
        else
        {
            info += " [DA FARE]";
        }
        return info;
    }
};

#endif // TODO_H
