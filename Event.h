#pragma once

#define _CRT_SECURE_NO_WARNINGS

#include "Location.h"
#include <iostream>
#include <string>
#include<cstring>
#include <vector>
using namespace std;

class Event : public Location
{
    int event_id;
    string name;
    string data;
    string timp;
    string category;

public:

    int getevent_id();
    string getname();
    string getdata();
    string gettimp();
    string getcategory();

    void setevet_id(int event_id);
    void setname(string name);
    void setdata(string data);
    void settimp(string timp);
    void setcategory(string category);

    Event();
    Event(int, string, string, string, string);
    Event(const Event& e);
    Event(int);
    Event(int, string);
    void modify(vector <Event>& listaEvent);
    void deleting(vector <Event>& listaEvent);
    void filtru(vector <Event>& listaEvent);
    Event& operator = (const Event& e);
    friend ostream& operator << (ostream& out, const Event& e);
    friend istream& operator >> (istream& in, Event& e);
    bool operator ==(const Event& e);
    explicit operator int();
    ~Event();
};

