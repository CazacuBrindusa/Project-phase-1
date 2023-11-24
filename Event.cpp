#include "Event.h"
#include "Location.h"
#include <iostream>
#include <vector>
using namespace std;


int Event:: getevent_id() { return this->event_id; }
string Event::getname() { return this->name; }
string Event::getdata() { return this->data; }
string Event::gettimp() { return this->timp; }
string Event::getcategory() { return this->category; }

void Event::setevet_id(int event_id)
{
    if (event_id != NULL)
        this->event_id = event_id;
}
void Event::setname(string name)
{
    if (name != "\n")
        this->name = name;
}
void Event::setdata(string data)
{
    if (data != "\n")
        this->data = data;
}
void Event::settimp(string timp)
{
    if (timp != "\n")
        this->timp = timp;
}
void Event::setcategory(string category)
{
    if (category != "\n")
        this->category = category;
}

Event::Event() : Location()
{
    this->event_id = 0;
    this->name = "unknown";
    this->data = "unknown";
    this->timp = '0';
    this->category = '0';
}
Event::Event(int event_id, string name, string data, string timp, string category) : Location(location_id, venue, max_nr_seats, nr_rows, zones, seats)
{
    this->event_id = event_id;
    this->name = name;
    this->data = data;
    this->timp = timp;
    this->category = category;
}
Event::Event(int event_id) : Location()
{
    this->event_id = event_id;
    this->name = "unknown";
    this->data = "unknown";
    this->timp = '0';
    this->category = '0';
}
Event::Event(int event_id, string name) : Location()
{
    this->event_id = event_id;
    this->name = name;
    this->data = "unknown";
    this->timp = '0';
    this->category = '0';
}
Event::Event(const Event& e) : Location(e)
{
    this->event_id = e.event_id;
    this->name = e.name;
    this->data = e.data;
    this->timp = e.timp;
    this->category = e.category;
}
void Event::modify(vector <Event>& listaEvent)
{
    int id, ci;
    std::string data;
    cout << "Which is the id of the event that you want to modify? ";
    cin >> id;
    cout << endl;
    for (int i = 0; i < listaEvent.size(); i++)
        if (listaEvent[i].getevent_id() == id)
        {
            ci = i;
            break;
        }
    cout << "Which is the new date? ";
    cin >> data;
    cout << endl;
    listaEvent[ci].setdata(data);
}
void Event::deleting(vector <Event>& listaEvent)
{
    int id, ci;
    cout << "Which is the id of the event that you want to delete? ";
    cin >> id;
    cout << endl;
    for (int i = 0; i < listaEvent.size(); i++)
        if (listaEvent[i].getevent_id() == id)
        {
            ci = i;
            break;
        }
    listaEvent.erase(listaEvent.begin() + ci);
}
void Event::filtru(vector <Event>& listaEvent)
{
    cout << "Which is the date?";
    string ziua;
    cin >> ziua;
    for (int i = 0; i < listaEvent.size(); i++)
        if (listaEvent[i].getdata() == ziua)
        {
            cout << listaEvent[i];
            cout << endl;
        }
}
Event& Event::operator =(const Event& e)
{
    if (this != &e)
    {
        Location::operator =(e);
        this->event_id = e.event_id;
        this->name = e.name;
        this->data = e.data;
        this->timp = e.timp;
        this->category = e.category;
    }
    return *this;
}
ostream& operator << (ostream& out, const Event& e)
{
    out << (Location&)e;
    out << "The event id is: " << e.event_id << endl;
    out << "The name of the event is: " << e.name << endl;
    out << "The date of the event is: " << e.data << endl;
    out << "The time of the event is: " << e.timp << endl;
    out << "The type of the event is: " << e.category << endl;
    return out;
}
istream& operator >> (istream& in, Event& e)
{
    in >> (Location&)e;
    cout << "The event id is: ";
    in >> e.event_id;
    cout << endl;
    cout << "The name of the event is: ";
    in >> e.name;
    cout << endl;
    cout << "The date of the event is: ";
    in >> e.data;
    cout << endl;
    cout << "The time of the event is: ";
    in >> e.timp;
    cout << endl;
    cout << "The type of the event is: ";
    in >> e.category;
    cout << endl;
    return in;
}

bool Event:: operator ==(const Event& e)
{
    Event aux(*this);
    return Location:: operator == (e) &&
        aux.event_id == e.event_id &&
        aux.name == e.name &&
        aux.data == e.data &&
        aux.timp == e.timp &&
        aux.category == e.category;
}
Event::operator int()
{
    return this->event_id;
}
Event::~Event()
{
    Location::~Location();
};
