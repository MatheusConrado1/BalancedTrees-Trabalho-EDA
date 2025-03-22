#ifndef DATE_H
#define DATE_H

#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>

class date {
public:
    date() = default;
    date(int day, int month, int year);
    date(std::string date);
    int get_day();
    int get_month();
    int get_year();
    void set_day(int day);
    void set_month(int month);
    void set_year(int year);
    bool operator>(const date &d) const;
    bool operator<(const date &d) const;
    bool operator==(const date &d) const;
    bool operator>=(const date &d) const;
    bool operator<=(const date &d) const;
    ~date();

    friend std::ostream& operator<<(std::ostream& os, const date& d);

private:
    int day;
    int month;
    int year;

};

date::date(int day, int month, int year) {
    this->day = day;
    this->month = month;
    this->year = year;
}

date::date(std::string date){
    std::stringstream ss(date);
    std::stringstream aux;
    std::string auxstr;

    getline(ss, auxstr, '/');
    aux << auxstr;
    aux >> month;             // stringstream >> int (ja realiza a conversao)
    aux.clear();

    getline(ss, auxstr, '/');
    aux << auxstr;
    aux >> day;
    aux.clear();

    getline(ss, auxstr, '/');
    aux << auxstr;
    aux >> year;
    aux.clear();
}

int date::get_day() {
    return day;
}

int date::get_month() {
    return month;
}

int date::get_year() {
    return year;
}

void date::set_day(int day) {
    this->day = day;
}

void date::set_month(int month) {
    this->month = month;
}

void date::set_year(int year) {
    this->year = year;
}

date::~date() {
    //dtor
}

bool date::operator>(const date &d) const {
    if(this->year > d.year)
        return true;
    else if(this->year < d.year)
        return false;
    else {
        if(this->month > d.month)
            return true;
        else if(this->month < d.month)
            return false;
        else {
            if(this->day > d.day)
                return true;
            else if(this->day < d.day)
                return false;
            else
                return true;
        }
    }
}

bool date::operator<(const date &d) const {
    if(this->year < d.year)
        return true;
    else if(this->year > d.year)
        return false;
    else {
        if(this->month < d.month)
            return true;
        else if(this->month > d.month)
            return false;
        else {
            if(this->day < d.day)
                return true;
            else if(this->day > d.day)
                return false;
            else
                return true;
        }
    }
}

bool date::operator==(const date &d) const {
    if(this->year == d.year && this->month == d.month && this->day == d.day)
        return true;
    else
        return false;
}

bool date::operator>=(const date &d) const {
    if(*this > d || *this == d)
        return true;
    else
        return false;
}

bool date::operator<=(const date &d) const {
    if(*this < d || *this == d)
        return true;
    else
        return false;
}

std::ostream& operator<<(std::ostream& os, const date& d) {
    os << std::setfill('0') << std::setw(2) << d.day << "/" << std::setfill('0') << std::setw(2) << d.month << "/" << std::setfill('0') << std::setw(4) << d.year;
    return os;
}

#endif