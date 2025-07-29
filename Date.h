#ifndef DATE_H
#define DATE_H

#include <string>
#include <sstream>
#include <iostream>
using namespace std;

class Date
{
private:
    int day;
    int month;
    int year;

public:
    // Costruttore di default
    Date() : day(0), month(0), year(0) {}

    // Costruttore con parametri
    Date(int d, int m, int y) : day(d), month(m), year(y) {}

    // Getters
    int getDay() const { return day; }
    int getMonth() const { return month; }
    int getYear() const { return year; }

    // Setters
    void setDay(int d) { day = d; }
    void setMonth(int m) { month = m; }
    void setYear(int y) { year = y; }

    // Operatore di uguaglianza
    bool operator==(const Date &other) const
    {
        return day == other.day && month == other.month && year == other.year;
    }

    // Metodo per convertire la data in stringa
    string toString() const
    {
        if (day == 0 && month == 0 && year == 0)
        {
            return "Non specificata";
        }
        stringstream ss;
        ss << day << "/" << month << "/" << year;
        return ss.str();
    }

    // Metodo per verificare se la data è valida
    bool isValid() const
    {
        if (year < 2000 || year > 2100)
            return false;
        if (month < 1 || month > 12)
            return false;
        if (day < 1 || day > 31)
            return false;
        return true;
    }
};

#endif // DATE_H
