#pragma once

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
    // Costruttori
    Date();
    Date(int d, int m, int y);

    // Getters
    int getDay() const;
    int getMonth() const;
    int getYear() const;

    // Setters
    void setDay(int d);
    void setMonth(int m);
    void setYear(int y);

    // Operatori
    bool operator==(const Date &other) const;

    // Metodi
    string toString() const;
    bool isValid() const;
};
