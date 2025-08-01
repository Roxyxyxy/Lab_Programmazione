#pragma once

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
    // Costruttori
    ToDo();
    ToDo(const string &desc, const Date &date);

    // Getters
    string getDescription() const;
    Date getDate() const;
    bool isCompleted() const;

    // Setters
    void setDescription(const string &desc);
    void setDate(const Date &date);
    void setCompleted(bool status);

    // Metodi
    void markCompleted();
    string getInfo() const;
};
