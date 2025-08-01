#include "ToDo.h"
using namespace std;

ToDo::ToDo() : description(""), dueDate(Date()), completed(false) {}

ToDo::ToDo(const string &desc, const Date &date)
    : description(desc), dueDate(date), completed(false) {}

string ToDo::getDescription() const { return description; }
Date ToDo::getDate() const { return dueDate; }
bool ToDo::isCompleted() const { return completed; }

void ToDo::setDescription(const string &desc) { description = desc; }
void ToDo::setDate(const Date &date) { dueDate = date; }
void ToDo::setCompleted(bool status) { completed = status; }

void ToDo::markCompleted() { completed = true; }

string ToDo::getInfo() const
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

    // Aggiungi data se specificata
    if (dueDate.getDay() != 0 || dueDate.getMonth() != 0 || dueDate.getYear() != 0)
    {
        info += " - Scadenza: " + dueDate.toString();
    }

    return info;
}