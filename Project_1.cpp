#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>
#include <cstring>
#include <vector>

using namespace std;

class Event;
class Ticket;
class Customer;
class Payment;
class Location;

class Location
{
protected:
    string venue = "unknown";
    int max_nr_seats = 100000;
    int nr_rows = 100;
    string zones = "unknown";
    int* seats = nullptr;

public:
    string getvenue() { return this->venue; }
    int getmax_nr_seats() { return this->max_nr_seats; }
    int getnr_rows() { return this->nr_rows; }
    string getzones() { return this->zones; }
    int* getseats() { return this->seats; }

    void setvenue(string venue)
    {
        if (venue != "\n")
            this->venue = venue;
    }
    void setmax_nr_seats(int max_nr_seats)
    {
        if (max_nr_seats >= 0 && max_nr_seats <= 100000)
            this->max_nr_seats = max_nr_seats;
    }
    void setnr_rows(int nr_rows)
    {
        if (nr_rows >= 0 && nr_rows <= 100)
            this->nr_rows = nr_rows;
    }
    void setzones(string zones)
    {
        if (zones != "\n")
            this->zones = zones;
    }
    void setseats(int* seat)
    {
        if (seats != nullptr)
            this->seats[this->nr_rows] = seats[this->nr_rows];
    }

    //generic methods (astept sem)
    //pointer -> "rule of 3" ?
    //op [], <=
    Location();
    Location(string, int, int, string, int* seats);
    Location(const Location& l);
    Location& operator =(const Location& l);
    int operator [](int i)
    {
        if (i<0 || i>this->nr_rows)
            throw runtime_error("Out of range");
        else
            return this->seats[i];
    }
    bool operator ==(const Location& l)
    {
        Location aux(*this);
        if (aux.venue == l.venue &&
            aux.max_nr_seats == l.max_nr_seats &&
            aux.nr_rows == l.nr_rows &&
            aux.zones == l.zones)
        {
            for (int i = 0; i < aux.nr_rows; i++)
                if (aux.seats != l.seats)
                    return false;
            return true;
        }
        return false;
    }
    bool operator <(const Location& t)
    {
        return this->max_nr_seats < t.max_nr_seats;
    }
    bool operator <(int p)
    {
        return this->max_nr_seats < p;
    }
    friend bool operator <(int p, const Location& t)
    {
        return p < t.max_nr_seats;
    }
    bool operator <=(const Location& t)
    {
        return this->max_nr_seats <= t.max_nr_seats;
    }
    bool operator <=(int p)
    {
        return this->max_nr_seats <= p;
    }
    friend bool operator <=(int p, const Location& t)
    {
        return p <= t.max_nr_seats;
    }
    bool operator >(const Location& t)
    {
        return this->max_nr_seats > t.max_nr_seats;
    }
    bool operator >(int p)
    {
        return this->max_nr_seats > p;
    }
    friend bool operator >(int p, const Location& t)
    {
        return p > t.max_nr_seats;
    }
    bool operator >=(const Location& t)
    {
        return this->max_nr_seats >= t.max_nr_seats;
    }
    bool operator >=(int p)
    {
        return this->max_nr_seats >= p;
    }
    friend bool operator >=(int p, const Location& t)
    {
        return p >= t.max_nr_seats;
    }
    Location& operator ++()
    {
        this->max_nr_seats++;
        return *this;
    }
    Location operator ++(int)
    {
        Location aux(*this);
        this->max_nr_seats++;
        return aux;
    }
    Location& operator --()
    {
        this->max_nr_seats--;
        return *this;
    }
    Location operator --(int)
    {
        Location aux(*this);
        this->max_nr_seats--;
        return aux;
    }
    Location operator +(const Location& t)
    {
        Location aux(*this);
        aux.max_nr_seats = t.max_nr_seats + aux.max_nr_seats;
        return aux;
    }
    Location operator +(int p)
    {
        Location aux(*this);
        aux.max_nr_seats = aux.max_nr_seats + p;
        return aux;
    }
    friend Location operator +(int p, const Location& t)
    {
        Location aux(t);
        aux.max_nr_seats = aux.max_nr_seats + p;
        return aux;
    }
    Location operator -(const Location& t)
    {
        Location aux(*this);
        aux.max_nr_seats = aux.max_nr_seats - t.max_nr_seats;
        return aux;
    }
    Location operator -(int p)
    {
        Location aux(*this);
        aux.max_nr_seats = aux.max_nr_seats - p;
        return aux;
    }
    friend Location operator -(int p, const Location& t)
    {
        Location aux(t);
        aux.max_nr_seats = p - aux.max_nr_seats;
        return aux;
    }
    friend ostream& operator <<(ostream& out, const Location& p);
    friend istream& operator >>(istream& in, Location& p);
    ~Location() {}
};

Location::Location()
{

}
Location::Location(string venue, int max_nr_seats, int nr_rows, string zones, int* seats)
{
    setvenue(venue);
    setmax_nr_seats(max_nr_seats);
    setnr_rows(nr_rows);
    setzones(zones);
    setseats(seats);
}
Location::Location(const Location& l)
{
    setvenue(l.venue);
    setmax_nr_seats(l.max_nr_seats);
    setnr_rows(l.nr_rows);
    setzones(l.zones);
    setseats(l.seats);
}
Location& Location::operator =(const Location& l)
{
    if (this != &l)
    {
        this->venue = l.venue;
        this->max_nr_seats = l.max_nr_seats;
        this->nr_rows = l.nr_rows;
        this->zones = l.zones;
        this->seats = l.seats;
    }
    return *this;
}
ostream& operator <<(ostream& out, const Location& p)
{
    out << "The location of the venue is: " << p.venue << endl;
    out << "The maximum number of seats is: " << p.max_nr_seats << endl;
    out << "The number of rows is: " << p.nr_rows << endl;
    out << "The zone is: " << p.zones << endl;
    out << "The number of seats per row are: ";
    for (int i = 0; i < p.nr_rows; i++)
        out << p.seats[i] << endl;
    return out;
}
istream& operator >>(istream& in, Location& p)
{
    cout << "The location of the venue is: ";
    in >> p.venue;
    cout << endl;
    cout << "The maximum number of seats is: ";
    in >> p.max_nr_seats;
    cout << endl;
    cout << "The number of rows is: ";
    in >> p.nr_rows;
    cout << endl;
    cout << "The zone is: ";
    in >> p.zones;
    cout << endl;
    cout << "The number of seats per row are: ";
    for (int i = 0; i < p.nr_rows; i++)
    {
        in >> p.seats[i];
        cout << endl;
    }
    return in;
}


class Event : public Location
{
    int event_id;
    string name;
    string data;
    string timp;
    string category;

public:

    int getevent_id() { return this->event_id; }
    string getname() { return this->name; }
    string getdata() { return this->data; }
    string gettimp() { return this->timp; }
    string getcategory() { return this->category; }

    void setevet_id(int event_id)
    {
        if (event_id != NULL)
            this->event_id = event_id;
    }
    void setname(string name)
    {
        if (name != "\n")
            this->name = name;
    }
    void setdata(string data)
    {
        if (data != "\n")
            this->data = data;
    }
    void settimp(string timp)
    {
        if (timp != "\n")
            this->timp = timp;
    }
    void setcategory(string category)
    {
        if (category != "\n")
            this->category = category;
    }

    Event();
    Event(int, string, string, string, string);
    Event(const Event& e);
    Event(int);
    Event(int, string);
    Event& operator = (const Event& e);
    friend ostream& operator << (ostream& out, const Event& e);
    friend istream& operator >> (istream& in, Event& e);
    bool operator ==(const Event& e)
    {
        Event aux(*this);
        return Location:: operator == (e) &&
            aux.event_id == e.event_id &&
            aux.name == e.name &&
            aux.data == e.data &&
            aux.timp == e.timp &&
            aux.category == e.category;
    }

    ~Event()
    {
        Location::~Location();
    };
};
Event::Event() : Location()
{
    this->event_id = 0;
    this->name = "unknown";
    this->data = "unknown";
    this->timp = '0';
    this->category = '0';
}
Event::Event(int event_id, string name, string data, string timp, string category) : Location(venue, max_nr_seats, nr_rows, zones, seats)
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
