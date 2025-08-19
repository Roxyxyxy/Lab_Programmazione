#include "Date.h"
using namespace std;

Date::Date() : day(0), month(0), year(0) {}

Date::Date(int d, int m, int y)
{
    // Controllo data
    if (d < 1 || d > 31 || m < 1 || m > 12 || y < 2000 || y > 2100)
    {
        day = 0;
        month = 0;
        year = 0;
    }
    else
    {
        day = d;
        month = m;
        year = y;
    }
}

int Date::getDay() const { return day; }
int Date::getMonth() const { return month; }
int Date::getYear() const { return year; }

void Date::setDay(int d)
{
    if (d >= 1 && d <= 31)
    {
        day = d;
    }
}

void Date::setMonth(int m)
{
    if (m >= 1 && m <= 12)
    {
        month = m;
    }
}

void Date::setYear(int y)
{
    if (y >= 2000 && y <= 2100)
    {
        year = y;
    }
}

bool Date::operator==(const Date &other) const
{
    return day == other.day && month == other.month && year == other.year;
}

string Date::toString() const
{
    if (day == 0 && month == 0 && year == 0)
    {
        return "Non specificata";
    }
    stringstream ss;
    ss << day << "/" << month << "/" << year;
    return ss.str();
}

bool Date::isValid() const
{
    if (year < 2000 || year > 2100)
        return false;
    if (month < 1 || month > 12)
        return false;
    if (day < 1 || day > 31)
        return false;

    // Controllo giorni specifici per mese
    if (month == 2) // Febbraio
    {
        bool isLeap = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
        return day <= (isLeap ? 29 : 28);
    }
    else if (month == 4 || month == 6 || month == 9 || month == 11) // Mesi con 30 giorni
    {
        return day <= 30;
    }

    return true;
}
