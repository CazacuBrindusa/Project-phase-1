#pragma once

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
using namespace std;

class Location
{
protected:
    int location_id = 0;
    string venue = "unknown";
    int max_nr_seats = 100000;
    int nr_rows = 100;
    string zones = "unknown";
    int* seats = nullptr;

public:
    
    int getlocation_id();
    string getvenue();
    int getmax_nr_seats();
    int getnr_rows();
    string getzones();
    int* getseats();

    void setlocation_id(int location_id);
    void setvenue(string venue);
    void setmax_nr_seats(int max_nr_seats);
    void setnr_rows(int nr_rows);
    void setzones(string zones);
    void setseats(int* seat);

    Location();
    Location(int, string, int, int, string, int* seats);
    Location(const Location& l);

    void modify(vector <Location>& listaLocation);
    void deleting(vector <Location>& listaLocation);
    void filtru(vector <Location>& listaLocation);

    Location& operator =(const Location& l);

    int operator [](int i);
    bool operator ==(const Location& l);
    bool operator <(const Location& t);
    bool operator <(int p);
    friend bool operator <(int p, const Location& t);
    bool operator <=(const Location& t);
    bool operator <=(int p);
    friend bool operator <=(int p, const Location& t);
    bool operator >(const Location& t);
    bool operator >(int p);
    friend bool operator >(int p, const Location& t);
    bool operator >=(const Location& t);
    bool operator >=(int p);
    friend bool operator >=(int p, const Location& t);
    Location& operator ++();
    Location operator ++(int);
    Location& operator --();
    Location operator --(int);
    Location operator +(const Location& t);
    Location operator +(int p);
    friend Location operator +(int p, const Location& t);
    Location operator -(const Location& t);
    Location operator -(int p);
    bool operator !();
    explicit operator string();
    friend Location operator -(int p, const Location& t);

    friend ostream& operator <<(ostream& out, const Location& p);
    friend istream& operator >>(istream& in, Location& p);
    ~Location() {}
};
